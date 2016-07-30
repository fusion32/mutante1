#include "../log.h"
#include "../util.h"
#include "../system.h"

#include <vulkan/vulkan.h>
#include <vulkan/vk_sdk_platform.h>

#include <string.h>

#define MAX_PHYSICAL_DEVICES 16
#define MAX_QUEUE_FAMILIES 16
#define MAX_SURFACE_FORMATS 16

static VkInstance			l_instance;
static VkPhysicalDevice		l_gpu;
static VkSurfaceKHR			l_surface;
static VkDevice				l_device;
static VkQueue				l_queue;

static uint32_t				l_queueFamilyIndex;


// ===================================================
// Auxiliary functions for debugging
//
// ===================================================

static const char *VK_ResultString(VkResult res)
{
	switch(res){
		case VK_SUCCESS:							return "VK_SUCCESS";
		case VK_NOT_READY:							return "VK_NOT_READY";
		case VK_TIMEOUT:							return "VK_TIMEOUT";
		case VK_EVENT_SET:							return "VK_EVENT_SET";
		case VK_EVENT_RESET:						return "VK_EVENT_RESET";
		case VK_INCOMPLETE:							return "VK_INCOMPLETE";
		case VK_ERROR_OUT_OF_HOST_MEMORY:			return "VK_ERROR_OUT_OF_HOST_MEMORY";
		case VK_ERROR_OUT_OF_DEVICE_MEMORY:			return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
		case VK_ERROR_INITIALIZATION_FAILED:		return "VK_ERROR_INITIALIZATION_FAILED";
		case VK_ERROR_DEVICE_LOST:					return "VK_ERROR_DEVICE_LOST";
		case VK_ERROR_MEMORY_MAP_FAILED:			return "VK_ERROR_MEMORY_MAP_FAILED";
		case VK_ERROR_LAYER_NOT_PRESENT:			return "VK_ERROR_LAYER_NOT_PRESENT";
		case VK_ERROR_EXTENSION_NOT_PRESENT:		return "VK_ERROR_EXTENSION_NOT_PRESENT";
		case VK_ERROR_FEATURE_NOT_PRESENT:			return "VK_ERROR_FEATURE_NOT_PRESENT";
		case VK_ERROR_INCOMPATIBLE_DRIVER:			return "VK_ERROR_INCOMPATIBLE_DRIVER";
		case VK_ERROR_TOO_MANY_OBJECTS:				return "VK_ERROR_TOO_MANY_OBJECTS";
		case VK_ERROR_FORMAT_NOT_SUPPORTED:			return "VK_ERROR_FORMAT_NOT_SUPPORTED";
		case VK_ERROR_SURFACE_LOST_KHR:				return "VK_ERROR_SURFACE_LOST_KHR";
		case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:		return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
		case VK_SUBOPTIMAL_KHR:						return "VK_SUBOPTIMAL_KHR";
		case VK_ERROR_OUT_OF_DATE_KHR:				return "VK_ERROR_OUT_OF_DATE_KHR";
		case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:		return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
		case VK_ERROR_VALIDATION_FAILED_EXT:		return "VK_ERROR_VALIDATION_FAILED_EXT";
		case VK_ERROR_INVALID_SHADER_NV:			return "VK_ERROR_INVALID_SHADER_NV";
	}

	return "VK_NULL_HANDLE";
}

static void VK_LogDeviceProperties(VkPhysicalDeviceProperties *props)
{
	//
}

static void VK_LogDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties *memProps)
{
	//
}


// ===================================================
// Initialization functions
//
// ===================================================

static void VK_CreateInstance()
{
	VkResult res;
#ifndef _DEBUG
	const char **layerNames = NULL;
	uint32_t layerCount = 0;
#else
	const char *layerNames[] = {
		"VK_LAYER_LUNARG_standard_validation"
	};
	uint32_t layerCount = ARRAYSIZE(layerNames);
#endif

	const char *extensionNames[] = {
#ifdef _DEBUG
		VK_EXT_DEBUG_REPORT_EXTENSION_NAME,
#endif
		VK_KHR_SURFACE_EXTENSION_NAME,
	};

	VkInstanceCreateInfo createInfo = {
		.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		.pNext = NULL,
		.flags = 0,
		.pApplicationInfo = NULL,
		.enabledLayerCount = layerCount,
		.ppEnabledLayerNames = layerNames,
		.enabledExtensionCount = ARRAYSIZE(extensionNames),
		.ppEnabledExtensionNames = extensionNames
	};

	res = vkCreateInstance(&createInfo, NULL, &l_instance);
	if(res != VK_SUCCESS){
		switch(res){
			case VK_ERROR_EXTENSION_NOT_PRESENT:
				SYS_Error("VK_CreateInstance: Requested extension is not supported!");
			case VK_ERROR_LAYER_NOT_PRESENT:
				SYS_Error("VK_CreateInstance: Requested layer could not be loaded!");
			case VK_ERROR_INCOMPATIBLE_DRIVER:
				SYS_Error("VK_CreateInstance: Unable to find compatible Vulkan ICD!");
			default:
				SYS_Error("VK_CreateInstance: %s", VK_ResultString(res));
		}
	}
}

static void VK_GetPhysicalDevice()
{
	VkResult res;
	uint32_t devCount;
	VkPhysicalDevice devices[MAX_PHYSICAL_DEVICES];

	res = vkEnumeratePhysicalDevices(l_instance, &devCount, NULL);
	if(res != VK_SUCCESS || devCount == 0)
		SYS_Error("VK_GetPhysicalDevice: Failed to enumerate physical devices!");

	if(devCount > MAX_PHYSICAL_DEVICES)
		devCount = MAX_PHYSICAL_DEVICES;
	res = vkEnumeratePhysicalDevices(l_instance, &devCount, devices);
	if(!(res == VK_SUCCESS || res == VK_INCOMPLETE))
		SYS_Error("VK_GetPhysicalDevice: Failed to retrieve physical devices!");

	//
	uint32_t i, k;
	uint32_t devIdx;
	VkPhysicalDeviceProperties props;
	VkPhysicalDeviceMemoryProperties memProps;
	//VkPhysicalDeviceFeatures features;
	VkPhysicalDeviceType devType;
	VkDeviceSize heapSize, curHeapSize;

	devType = VK_PHYSICAL_DEVICE_TYPE_OTHER;
	for(i = 0; i < devCount; ++i){
		vkGetPhysicalDeviceProperties(devices[i], &props);
		if(props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU ||
				props.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU ||
				props.deviceType == VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU){

			vkGetPhysicalDeviceMemoryProperties(devices[i], &memProps);
			curHeapSize = 0;
			for(k = 0; k < memProps.memoryHeapCount; ++k){
				if(memProps.memoryHeaps[k].flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT)
					curHeapSize = memProps.memoryHeaps[k].size;
			}


			// if we have 2 devices of equal type, check which one has more used features 
			// and the biggest device local heap (features have priority over heap size)
			if(props.deviceType == devType){
				// NOTE: add this later as we add more things into the renderer
				//vkGetPhysicalDeviceFeatures(devices[i], &features);

				if(heapSize < curHeapSize){
					heapSize = curHeapSize;
					devIdx = i;
				}
			}
			else{
				// preference:
				//	1 - VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU
				//	2 - VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU
				//	3 - VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU
				if(props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU ||

					(props.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU &&
						devType != VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) ||

					(props.deviceType == VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU &&
						devType != VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
						devType != VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU)){

					heapSize = curHeapSize;
					devType = props.deviceType;
					devIdx = i;
				}
			}
		}
	}

	//
	if(devType == VK_PHYSICAL_DEVICE_TYPE_OTHER)
		SYS_Error("VK_GetPhysicalDevice: Failed to retrieve a graphics device!");

	l_gpu = devices[devIdx];
}

#if defined(_WIN32)
/* TODO: review this
VkResult VK_CreateSurface(VkInstance instance, VkSurfaceKHR *pSurface)
{
	HWND hwnd;
	HINSTANCE hinstance;
	VkResult res;

	if (fpCreateWin32SurfaceKHR == NULL)
		return VK_NOT_READY;

	hwnd = WIN32_GetWindowHandle();
	hinstance = GetModuleHandle(NULL);
	VkWin32SurfaceCreateInfoKHR createInfo = {
		.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
		.pNext = NULL,
		.flags = 0,
		.hinstance = hinstance,
		.hwnd = hwnd
	};

	res = fpCreateWin32SurfaceKHR(instance, &createInfo, NULL, pSurface);
	return res;
}
*/
#endif

static void VK_CreateDevice()
{
	VkResult res;

	const char *extensionNames[] = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME,
	};

	float queuePriority = 1.0f;
	VkDeviceQueueCreateInfo queueCreateInfo = {
		.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
		.pNext = NULL,
		.flags = 0,
		.queueFamilyIndex = l_queueFamilyIndex,
		.queueCount = 1,
		.pQueuePriorities = &queuePriority,
	};

	VkPhysicalDeviceFeatures enabledFeatures;
	memset(&enabledFeatures, 0, sizeof(VkPhysicalDeviceFeatures));
	//enabledFeatures.geometryShader = VK_TRUE;

	VkDeviceCreateInfo createInfo = {
		.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
		.pNext = NULL,
		.flags = 0,
		.queueCreateInfoCount = 1,
		.pQueueCreateInfos = &queueCreateInfo,
		.enabledLayerCount = 0,
		.ppEnabledLayerNames = NULL,
		.enabledExtensionCount = ARRAYSIZE(extensionNames),
		.ppEnabledExtensionNames = extensionNames,
		.pEnabledFeatures = &enabledFeatures,
	};

	res = vkCreateDevice(l_gpu, &createInfo, NULL, &l_device);
	if(res != VK_SUCCESS){
		switch(res){
			case VK_ERROR_EXTENSION_NOT_PRESENT:
				SYS_Error("VK_CreateDevice: Requested extension is not supported!");
			case VK_ERROR_FEATURE_NOT_PRESENT:
				SYS_Error("VK_CreateDevice: Requested feature is not supported!");
			default:
				SYS_Error("VK_CreateDevice: %s", VK_ResultString(res));
		}
	}
}

// TODO ->
static void VK_CheckSurface();
static void VK_CreateHeaps(); // heaps for buffers and textures on device local memory
static void VK_CreateStagingHeaps(); // heaps on host visible memory for uploading to buffers and textures on device local memory
static void VK_CreateSwapchain();

//
static void VK_CreateCommandPool();
static void VK_CreateCommandBuffers();

//
static void VK_CreateDescriptorLayout();
static void VK_CreateDescriptorPool();
static void VK_CreateDescriptorSet();

static void VK_CreateRenderPasses();
static void VK_CreateFramebuffers();
static void VK_LoadShaders();
static void VK_CreatePipepine();


// NOTE: think about these! these will be called by the main thread and will dispatch work to the render thread.
void VK_Begin();
void VK_End();
void VK_Next();
void VK_Present();

void VK_RenderModel();
void VK_RenderSurface();
void VK_RenderStaticModel();

// maybe dispatch a couple of these to the worker threads
// and each one will generate one command buffer or more
// and send to the renderthread
void VK_RenderWork(void *wtf);


//VK_Sync(); -> check if last frame has finished
//VK_Transfer(); --> do any pending uploads
//VK_Begin() -> begin render pass
//dispatch [n] VK_RenderWork threads
//VK_Next() -> next subpass
//dispatch [n] VK_RenderWork
//VK_End() --> end render pass
//VK_Present(); --> present


static void RenderThread(void *unused)
{
}