// this file was generated automatically by vklgen-1.py

///////////////////////////////////////////////////////////////////////////////////////
// Overview:
//	TODO
//
///////////////////////////////////////////////////////////////////////////////////////
// Base API: the functions needed for querying any extension or layer properties
// and for creating a valid Vulkan Instance. The instance and device APIs can't load
// without this.
//
// Instance API: the functions needed for querying information about the system hardware
// and the creation of the Vulkan Device. The device API can't load without this.
//
// Device API: the functions needed for the Vulkan Device management.
///////////////////////////////////////////////////////////////////////////////////////
// VK_LoadBaseAPI
//	- Info: In case of failure, VK_FALSE will be returned and the library is to be
//	considered invalid or inexistant. If it succeed, VK_TRUE will be returned and
//	the base API will be loaded.
//
// VK_LoadInstanceAPI
//	- Info: In case of failure, VK_FALSE will be returned and the contents of the
//	API function pointers will be undefined. If it succeed, VK_TRUE will be returned
//	and the instance API will be loaded.
//
// VK_LoadDeviceAPI
//	- Info: In case of failure, VK_FALSE will be returned and the contents of the
//	API function pointers will be undefined. If it succeed, VK_TRUE will be returned
//	and the device API will be loaded.
//
// VK_UnloadAPI
//	- Info: If the library is open, it will be closed and vkGetInstanceProcAddr
//	and vkGetDeviceProcAddr will be set to NULL. The contents of the other function
//	pointers will be undefined and calling any of those will result in undefined
//	behaviour.
///////////////////////////////////////////////////////////////////////////////////////

#include "vk_loader.h"
#include "../../log.h"

#ifndef LOG
	#define LOG(fmt, ...)
#endif

#ifndef LOG_WARNING
	#define LOG_WARNING(fmt, ...)
#endif

#ifndef LOG_ERROR
    #define LOG_ERROR(fmt, ...)
#endif

#ifndef LOG_DEBUG
	#define LOG_DEBUG(fmt, ...)
#endif

// Vulkan Loader State
// 0 = unloaded
// 1 = base api loaded
// 2 = instance api loaded
// 3 = device api loaded
uint32_t l_state = 0;

// Vulkan 1.0 Core
// ==================================

// Base API
VKAPI_ATTR PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr = NULL;
VKAPI_ATTR PFN_vkCreateInstance vkCreateInstance = NULL;
VKAPI_ATTR PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties = NULL;
VKAPI_ATTR PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties = NULL;

// Instance API
VKAPI_ATTR PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr = NULL;
VKAPI_ATTR PFN_vkDestroyInstance vkDestroyInstance = NULL;
VKAPI_ATTR PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties = NULL;
VKAPI_ATTR PFN_vkCreateDevice vkCreateDevice = NULL;
VKAPI_ATTR PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties = NULL;
VKAPI_ATTR PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties = NULL;

// Device API
VKAPI_ATTR PFN_vkDestroyDevice vkDestroyDevice = NULL;
VKAPI_ATTR PFN_vkGetDeviceQueue vkGetDeviceQueue = NULL;
VKAPI_ATTR PFN_vkQueueSubmit vkQueueSubmit = NULL;
VKAPI_ATTR PFN_vkQueueWaitIdle vkQueueWaitIdle = NULL;
VKAPI_ATTR PFN_vkDeviceWaitIdle vkDeviceWaitIdle = NULL;
VKAPI_ATTR PFN_vkAllocateMemory vkAllocateMemory = NULL;
VKAPI_ATTR PFN_vkFreeMemory vkFreeMemory = NULL;
VKAPI_ATTR PFN_vkMapMemory vkMapMemory = NULL;
VKAPI_ATTR PFN_vkUnmapMemory vkUnmapMemory = NULL;
VKAPI_ATTR PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges = NULL;
VKAPI_ATTR PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges = NULL;
VKAPI_ATTR PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment = NULL;
VKAPI_ATTR PFN_vkBindBufferMemory vkBindBufferMemory = NULL;
VKAPI_ATTR PFN_vkBindImageMemory vkBindImageMemory = NULL;
VKAPI_ATTR PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements = NULL;
VKAPI_ATTR PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements = NULL;
VKAPI_ATTR PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements = NULL;
VKAPI_ATTR PFN_vkQueueBindSparse vkQueueBindSparse = NULL;
VKAPI_ATTR PFN_vkCreateFence vkCreateFence = NULL;
VKAPI_ATTR PFN_vkDestroyFence vkDestroyFence = NULL;
VKAPI_ATTR PFN_vkResetFences vkResetFences = NULL;
VKAPI_ATTR PFN_vkGetFenceStatus vkGetFenceStatus = NULL;
VKAPI_ATTR PFN_vkWaitForFences vkWaitForFences = NULL;
VKAPI_ATTR PFN_vkCreateSemaphore vkCreateSemaphore = NULL;
VKAPI_ATTR PFN_vkDestroySemaphore vkDestroySemaphore = NULL;
VKAPI_ATTR PFN_vkCreateEvent vkCreateEvent = NULL;
VKAPI_ATTR PFN_vkDestroyEvent vkDestroyEvent = NULL;
VKAPI_ATTR PFN_vkGetEventStatus vkGetEventStatus = NULL;
VKAPI_ATTR PFN_vkSetEvent vkSetEvent = NULL;
VKAPI_ATTR PFN_vkResetEvent vkResetEvent = NULL;
VKAPI_ATTR PFN_vkCreateQueryPool vkCreateQueryPool = NULL;
VKAPI_ATTR PFN_vkDestroyQueryPool vkDestroyQueryPool = NULL;
VKAPI_ATTR PFN_vkGetQueryPoolResults vkGetQueryPoolResults = NULL;
VKAPI_ATTR PFN_vkCreateBuffer vkCreateBuffer = NULL;
VKAPI_ATTR PFN_vkDestroyBuffer vkDestroyBuffer = NULL;
VKAPI_ATTR PFN_vkCreateBufferView vkCreateBufferView = NULL;
VKAPI_ATTR PFN_vkDestroyBufferView vkDestroyBufferView = NULL;
VKAPI_ATTR PFN_vkCreateImage vkCreateImage = NULL;
VKAPI_ATTR PFN_vkDestroyImage vkDestroyImage = NULL;
VKAPI_ATTR PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout = NULL;
VKAPI_ATTR PFN_vkCreateImageView vkCreateImageView = NULL;
VKAPI_ATTR PFN_vkDestroyImageView vkDestroyImageView = NULL;
VKAPI_ATTR PFN_vkCreateShaderModule vkCreateShaderModule = NULL;
VKAPI_ATTR PFN_vkDestroyShaderModule vkDestroyShaderModule = NULL;
VKAPI_ATTR PFN_vkCreatePipelineCache vkCreatePipelineCache = NULL;
VKAPI_ATTR PFN_vkDestroyPipelineCache vkDestroyPipelineCache = NULL;
VKAPI_ATTR PFN_vkGetPipelineCacheData vkGetPipelineCacheData = NULL;
VKAPI_ATTR PFN_vkMergePipelineCaches vkMergePipelineCaches = NULL;
VKAPI_ATTR PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines = NULL;
VKAPI_ATTR PFN_vkCreateComputePipelines vkCreateComputePipelines = NULL;
VKAPI_ATTR PFN_vkDestroyPipeline vkDestroyPipeline = NULL;
VKAPI_ATTR PFN_vkCreatePipelineLayout vkCreatePipelineLayout = NULL;
VKAPI_ATTR PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout = NULL;
VKAPI_ATTR PFN_vkCreateSampler vkCreateSampler = NULL;
VKAPI_ATTR PFN_vkDestroySampler vkDestroySampler = NULL;
VKAPI_ATTR PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout = NULL;
VKAPI_ATTR PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout = NULL;
VKAPI_ATTR PFN_vkCreateDescriptorPool vkCreateDescriptorPool = NULL;
VKAPI_ATTR PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool = NULL;
VKAPI_ATTR PFN_vkResetDescriptorPool vkResetDescriptorPool = NULL;
VKAPI_ATTR PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets = NULL;
VKAPI_ATTR PFN_vkFreeDescriptorSets vkFreeDescriptorSets = NULL;
VKAPI_ATTR PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets = NULL;
VKAPI_ATTR PFN_vkCreateFramebuffer vkCreateFramebuffer = NULL;
VKAPI_ATTR PFN_vkDestroyFramebuffer vkDestroyFramebuffer = NULL;
VKAPI_ATTR PFN_vkCreateRenderPass vkCreateRenderPass = NULL;
VKAPI_ATTR PFN_vkDestroyRenderPass vkDestroyRenderPass = NULL;
VKAPI_ATTR PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity = NULL;
VKAPI_ATTR PFN_vkCreateCommandPool vkCreateCommandPool = NULL;
VKAPI_ATTR PFN_vkDestroyCommandPool vkDestroyCommandPool = NULL;
VKAPI_ATTR PFN_vkResetCommandPool vkResetCommandPool = NULL;
VKAPI_ATTR PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers = NULL;
VKAPI_ATTR PFN_vkFreeCommandBuffers vkFreeCommandBuffers = NULL;
VKAPI_ATTR PFN_vkBeginCommandBuffer vkBeginCommandBuffer = NULL;
VKAPI_ATTR PFN_vkEndCommandBuffer vkEndCommandBuffer = NULL;
VKAPI_ATTR PFN_vkResetCommandBuffer vkResetCommandBuffer = NULL;
VKAPI_ATTR PFN_vkCmdBindPipeline vkCmdBindPipeline = NULL;
VKAPI_ATTR PFN_vkCmdSetViewport vkCmdSetViewport = NULL;
VKAPI_ATTR PFN_vkCmdSetScissor vkCmdSetScissor = NULL;
VKAPI_ATTR PFN_vkCmdSetLineWidth vkCmdSetLineWidth = NULL;
VKAPI_ATTR PFN_vkCmdSetDepthBias vkCmdSetDepthBias = NULL;
VKAPI_ATTR PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants = NULL;
VKAPI_ATTR PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds = NULL;
VKAPI_ATTR PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask = NULL;
VKAPI_ATTR PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask = NULL;
VKAPI_ATTR PFN_vkCmdSetStencilReference vkCmdSetStencilReference = NULL;
VKAPI_ATTR PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets = NULL;
VKAPI_ATTR PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer = NULL;
VKAPI_ATTR PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers = NULL;
VKAPI_ATTR PFN_vkCmdDraw vkCmdDraw = NULL;
VKAPI_ATTR PFN_vkCmdDrawIndexed vkCmdDrawIndexed = NULL;
VKAPI_ATTR PFN_vkCmdDrawIndirect vkCmdDrawIndirect = NULL;
VKAPI_ATTR PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect = NULL;
VKAPI_ATTR PFN_vkCmdDispatch vkCmdDispatch = NULL;
VKAPI_ATTR PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect = NULL;
VKAPI_ATTR PFN_vkCmdCopyBuffer vkCmdCopyBuffer = NULL;
VKAPI_ATTR PFN_vkCmdCopyImage vkCmdCopyImage = NULL;
VKAPI_ATTR PFN_vkCmdBlitImage vkCmdBlitImage = NULL;
VKAPI_ATTR PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage = NULL;
VKAPI_ATTR PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer = NULL;
VKAPI_ATTR PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer = NULL;
VKAPI_ATTR PFN_vkCmdFillBuffer vkCmdFillBuffer = NULL;
VKAPI_ATTR PFN_vkCmdClearColorImage vkCmdClearColorImage = NULL;
VKAPI_ATTR PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage = NULL;
VKAPI_ATTR PFN_vkCmdClearAttachments vkCmdClearAttachments = NULL;
VKAPI_ATTR PFN_vkCmdResolveImage vkCmdResolveImage = NULL;
VKAPI_ATTR PFN_vkCmdSetEvent vkCmdSetEvent = NULL;
VKAPI_ATTR PFN_vkCmdResetEvent vkCmdResetEvent = NULL;
VKAPI_ATTR PFN_vkCmdWaitEvents vkCmdWaitEvents = NULL;
VKAPI_ATTR PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier = NULL;
VKAPI_ATTR PFN_vkCmdBeginQuery vkCmdBeginQuery = NULL;
VKAPI_ATTR PFN_vkCmdEndQuery vkCmdEndQuery = NULL;
VKAPI_ATTR PFN_vkCmdResetQueryPool vkCmdResetQueryPool = NULL;
VKAPI_ATTR PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp = NULL;
VKAPI_ATTR PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults = NULL;
VKAPI_ATTR PFN_vkCmdPushConstants vkCmdPushConstants = NULL;
VKAPI_ATTR PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass = NULL;
VKAPI_ATTR PFN_vkCmdNextSubpass vkCmdNextSubpass = NULL;
VKAPI_ATTR PFN_vkCmdEndRenderPass vkCmdEndRenderPass = NULL;
VKAPI_ATTR PFN_vkCmdExecuteCommands vkCmdExecuteCommands = NULL;


// Instance Extensions
// ==================================

// VK_EXT_debug_report
VKAPI_ATTR PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT = NULL;
VKAPI_ATTR PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT = NULL;
VKAPI_ATTR PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT = NULL;

// VK_KHR_surface
VKAPI_ATTR PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR = NULL;

// WSI Extensions (Instance)
// ==================================

// VK_KHR_xlib_surface
#ifdef VK_USE_PLATFORM_XLIB_KHR
VKAPI_ATTR PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR = NULL;
#endif

// VK_KHR_xcb_surface
#ifdef VK_USE_PLATFORM_XCB_KHR
VKAPI_ATTR PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR = NULL;
#endif

// VK_KHR_wayland_surface
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
VKAPI_ATTR PFN_vkCreateWaylandSurfaceKHR vkCreateWaylandSurfaceKHR = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR = NULL;
#endif

// VK_KHR_mir_surface
#ifdef VK_USE_PLATFORM_MIR_KHR
VKAPI_ATTR PFN_vkCreateMirSurfaceKHR vkCreateMirSurfaceKHR = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceMirPresentationSupportKHR vkGetPhysicalDeviceMirPresentationSupportKHR = NULL;
#endif

// VK_KHR_android_surface
#ifdef VK_USE_PLATFORM_ANDROID_KHR
VKAPI_ATTR PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR = NULL;
#endif

// VK_KHR_win32_surface
#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR = NULL;
VKAPI_ATTR PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR = NULL;
#endif

// Device Extensions
// ==================================

// VK_KHR_swapchain
VKAPI_ATTR PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR = NULL;
VKAPI_ATTR PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR = NULL;
VKAPI_ATTR PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR = NULL;
VKAPI_ATTR PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR = NULL;
VKAPI_ATTR PFN_vkQueuePresentKHR vkQueuePresentKHR = NULL;

// Platform specific library loading
// ==================================

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

static HMODULE l_libvulkan = NULL;

static VkBool32 VK_OpenLib()
{
	if(l_libvulkan == NULL){
		l_libvulkan = LoadLibraryA("vulkan-1.dll");
		if(l_libvulkan == NULL)
			return VK_FALSE;
	}

	return VK_TRUE;
}

static void VK_CloseLib()
{
	if(l_libvulkan != NULL){
		FreeLibrary(l_libvulkan);
		l_libvulkan = NULL;
	}
}

static VkBool32 VK_IsLibOpen()
{
	return (l_libvulkan != NULL);
}

static PFN_vkVoidFunction VK_GetProcAddr(const char *procName)
{
	if(l_libvulkan == NULL){
		LOG_ERROR("VK_GetProcAddr: Vulkan library is not loaded!");
		return NULL;
	}

	return (PFN_vkVoidFunction)GetProcAddress(l_libvulkan, procName);
}
#endif

// API Loading
// ==================================

VkBool32 VK_LoadBaseAPI()
{
	// LOG("Updating your drivers may solve this issue.");
	VkBool32 res;

	if(VK_IsLibOpen() == VK_FALSE){
		if(VK_OpenLib() == VK_FALSE){
			LOG_ERROR("VK_LoadBaseAPI: Failed to open Vulkan library.");
			return VK_FALSE;
		}
	}

	if(l_state >= 1){
		LOG_WARNING("VK_LoadBaseAPI: Base API is already loaded!");
		return VK_TRUE;
	}

	vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr) VK_GetProcAddr("vkGetInstanceProcAddr");
	if(vkGetInstanceProcAddr == NULL){
		LOG_ERROR("VK_LoadBaseAPI: Failed to load vkGetInstanceProcAddr! Unable to proceed.");
		VK_CloseLib();
		return VK_FALSE;
	}

	//=================================================================
	#define VK_GET_PROC_ADDR(proc_name)												\
		proc_name = (PFN_##proc_name) vkGetInstanceProcAddr(NULL, #proc_name);		\
		if(proc_name == NULL){														\
			LOG_ERROR("VK_LoadBaseAPI: Failed to load %s!", #proc_name);			\
			res = VK_FALSE;															\
		}

	res = VK_TRUE;
	VK_GET_PROC_ADDR(vkGetInstanceProcAddr);
	VK_GET_PROC_ADDR(vkCreateInstance);
	VK_GET_PROC_ADDR(vkEnumerateInstanceExtensionProperties);
	VK_GET_PROC_ADDR(vkEnumerateInstanceLayerProperties);

	#undef VK_GET_PROC_ADDR
	//=================================================================


	if(res == VK_FALSE){
		LOG_ERROR("VK_LoadBaseAPI: Failed to load all procs.");
		VK_CloseLib();
		return VK_FALSE;
	}

	// retrieve instance extensions
	//uint32_t extensionCount;
	//VkExtensionProperties ext;
	//vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, &ext);

	l_state = 1;
	return VK_TRUE;
}

VkBool32 VK_LoadInstanceAPI(VkInstance instance)
{
	VkBool32 res;

	if(VK_IsLibOpen() == VK_FALSE || l_state == 0){
		LOG_ERROR("VK_LoadInstanceAPI: Base API not loaded!");
		return VK_FALSE;
	}

	if(l_state >= 2){
		LOG_WARNING("VK_LoadInstanceAPI: Instance API is already loaded!");
		return VK_TRUE;
	}

	//=================================================================
	#define VK_GET_PROC_ADDR(proc_name)													\
		proc_name = (PFN_##proc_name) vkGetInstanceProcAddr(instance, #proc_name);		\
		if(proc_name == NULL){															\
			LOG_ERROR("VK_LoadInstanceAPI: Failed to load %s!", #proc_name);			\
			res = VK_FALSE;																\
		}

	res = VK_TRUE;
	VK_GET_PROC_ADDR(vkGetDeviceProcAddr);
	VK_GET_PROC_ADDR(vkDestroyInstance);
	VK_GET_PROC_ADDR(vkEnumeratePhysicalDevices);
	VK_GET_PROC_ADDR(vkGetPhysicalDeviceFeatures);
	VK_GET_PROC_ADDR(vkGetPhysicalDeviceFormatProperties);
	VK_GET_PROC_ADDR(vkGetPhysicalDeviceImageFormatProperties);
	VK_GET_PROC_ADDR(vkGetPhysicalDeviceProperties);
	VK_GET_PROC_ADDR(vkGetPhysicalDeviceQueueFamilyProperties);
	VK_GET_PROC_ADDR(vkGetPhysicalDeviceMemoryProperties);
	VK_GET_PROC_ADDR(vkCreateDevice);
	VK_GET_PROC_ADDR(vkEnumerateDeviceExtensionProperties);
	VK_GET_PROC_ADDR(vkEnumerateDeviceLayerProperties);
	VK_GET_PROC_ADDR(vkGetPhysicalDeviceSparseImageFormatProperties);

	#undef VK_GET_PROC_ADDR
	//=================================================================

	if(res == VK_FALSE){
		LOG_ERROR("VK_LoadInstanceAPI: Failed to load all procs.");
		return VK_FALSE;
	}

	l_state = 2;
	return VK_TRUE;
}

VkBool32 VK_LoadDeviceAPI(VkDevice device)
{
	VkBool32 res;

	if(VK_IsLibOpen() == VK_FALSE || l_state < 2){
		LOG_ERROR("VK_LoadDeviceAPI: Instance API not loaded!");
		return VK_FALSE;
	}

	if(l_state >= 3){
		LOG_WARNING("VK_LoadDeviceAPI: Device API is already loaded!");
		return VK_TRUE;
	}

	//=================================================================
	#define VK_GET_PROC_ADDR(proc_name)													\
		proc_name = (PFN_##proc_name) vkGetDeviceProcAddr(device, #proc_name);			\
		if(proc_name == NULL){															\
			LOG_ERROR("VK_LoadDeviceAPI: Failed to load %s!", #proc_name);				\
			res = VK_FALSE;																\
		}

	res = VK_TRUE;
	VK_GET_PROC_ADDR(vkDestroyDevice);
	VK_GET_PROC_ADDR(vkGetDeviceQueue);
	VK_GET_PROC_ADDR(vkQueueSubmit);
	VK_GET_PROC_ADDR(vkQueueWaitIdle);
	VK_GET_PROC_ADDR(vkDeviceWaitIdle);
	VK_GET_PROC_ADDR(vkAllocateMemory);
	VK_GET_PROC_ADDR(vkFreeMemory);
	VK_GET_PROC_ADDR(vkMapMemory);
	VK_GET_PROC_ADDR(vkUnmapMemory);
	VK_GET_PROC_ADDR(vkFlushMappedMemoryRanges);
	VK_GET_PROC_ADDR(vkInvalidateMappedMemoryRanges);
	VK_GET_PROC_ADDR(vkGetDeviceMemoryCommitment);
	VK_GET_PROC_ADDR(vkBindBufferMemory);
	VK_GET_PROC_ADDR(vkBindImageMemory);
	VK_GET_PROC_ADDR(vkGetBufferMemoryRequirements);
	VK_GET_PROC_ADDR(vkGetImageMemoryRequirements);
	VK_GET_PROC_ADDR(vkGetImageSparseMemoryRequirements);
	VK_GET_PROC_ADDR(vkQueueBindSparse);
	VK_GET_PROC_ADDR(vkCreateFence);
	VK_GET_PROC_ADDR(vkDestroyFence);
	VK_GET_PROC_ADDR(vkResetFences);
	VK_GET_PROC_ADDR(vkGetFenceStatus);
	VK_GET_PROC_ADDR(vkWaitForFences);
	VK_GET_PROC_ADDR(vkCreateSemaphore);
	VK_GET_PROC_ADDR(vkDestroySemaphore);
	VK_GET_PROC_ADDR(vkCreateEvent);
	VK_GET_PROC_ADDR(vkDestroyEvent);
	VK_GET_PROC_ADDR(vkGetEventStatus);
	VK_GET_PROC_ADDR(vkSetEvent);
	VK_GET_PROC_ADDR(vkResetEvent);
	VK_GET_PROC_ADDR(vkCreateQueryPool);
	VK_GET_PROC_ADDR(vkDestroyQueryPool);
	VK_GET_PROC_ADDR(vkGetQueryPoolResults);
	VK_GET_PROC_ADDR(vkCreateBuffer);
	VK_GET_PROC_ADDR(vkDestroyBuffer);
	VK_GET_PROC_ADDR(vkCreateBufferView);
	VK_GET_PROC_ADDR(vkDestroyBufferView);
	VK_GET_PROC_ADDR(vkCreateImage);
	VK_GET_PROC_ADDR(vkDestroyImage);
	VK_GET_PROC_ADDR(vkGetImageSubresourceLayout);
	VK_GET_PROC_ADDR(vkCreateImageView);
	VK_GET_PROC_ADDR(vkDestroyImageView);
	VK_GET_PROC_ADDR(vkCreateShaderModule);
	VK_GET_PROC_ADDR(vkDestroyShaderModule);
	VK_GET_PROC_ADDR(vkCreatePipelineCache);
	VK_GET_PROC_ADDR(vkDestroyPipelineCache);
	VK_GET_PROC_ADDR(vkGetPipelineCacheData);
	VK_GET_PROC_ADDR(vkMergePipelineCaches);
	VK_GET_PROC_ADDR(vkCreateGraphicsPipelines);
	VK_GET_PROC_ADDR(vkCreateComputePipelines);
	VK_GET_PROC_ADDR(vkDestroyPipeline);
	VK_GET_PROC_ADDR(vkCreatePipelineLayout);
	VK_GET_PROC_ADDR(vkDestroyPipelineLayout);
	VK_GET_PROC_ADDR(vkCreateSampler);
	VK_GET_PROC_ADDR(vkDestroySampler);
	VK_GET_PROC_ADDR(vkCreateDescriptorSetLayout);
	VK_GET_PROC_ADDR(vkDestroyDescriptorSetLayout);
	VK_GET_PROC_ADDR(vkCreateDescriptorPool);
	VK_GET_PROC_ADDR(vkDestroyDescriptorPool);
	VK_GET_PROC_ADDR(vkResetDescriptorPool);
	VK_GET_PROC_ADDR(vkAllocateDescriptorSets);
	VK_GET_PROC_ADDR(vkFreeDescriptorSets);
	VK_GET_PROC_ADDR(vkUpdateDescriptorSets);
	VK_GET_PROC_ADDR(vkCreateFramebuffer);
	VK_GET_PROC_ADDR(vkDestroyFramebuffer);
	VK_GET_PROC_ADDR(vkCreateRenderPass);
	VK_GET_PROC_ADDR(vkDestroyRenderPass);
	VK_GET_PROC_ADDR(vkGetRenderAreaGranularity);
	VK_GET_PROC_ADDR(vkCreateCommandPool);
	VK_GET_PROC_ADDR(vkDestroyCommandPool);
	VK_GET_PROC_ADDR(vkResetCommandPool);
	VK_GET_PROC_ADDR(vkAllocateCommandBuffers);
	VK_GET_PROC_ADDR(vkFreeCommandBuffers);
	VK_GET_PROC_ADDR(vkBeginCommandBuffer);
	VK_GET_PROC_ADDR(vkEndCommandBuffer);
	VK_GET_PROC_ADDR(vkResetCommandBuffer);
	VK_GET_PROC_ADDR(vkCmdBindPipeline);
	VK_GET_PROC_ADDR(vkCmdSetViewport);
	VK_GET_PROC_ADDR(vkCmdSetScissor);
	VK_GET_PROC_ADDR(vkCmdSetLineWidth);
	VK_GET_PROC_ADDR(vkCmdSetDepthBias);
	VK_GET_PROC_ADDR(vkCmdSetBlendConstants);
	VK_GET_PROC_ADDR(vkCmdSetDepthBounds);
	VK_GET_PROC_ADDR(vkCmdSetStencilCompareMask);
	VK_GET_PROC_ADDR(vkCmdSetStencilWriteMask);
	VK_GET_PROC_ADDR(vkCmdSetStencilReference);
	VK_GET_PROC_ADDR(vkCmdBindDescriptorSets);
	VK_GET_PROC_ADDR(vkCmdBindIndexBuffer);
	VK_GET_PROC_ADDR(vkCmdBindVertexBuffers);
	VK_GET_PROC_ADDR(vkCmdDraw);
	VK_GET_PROC_ADDR(vkCmdDrawIndexed);
	VK_GET_PROC_ADDR(vkCmdDrawIndirect);
	VK_GET_PROC_ADDR(vkCmdDrawIndexedIndirect);
	VK_GET_PROC_ADDR(vkCmdDispatch);
	VK_GET_PROC_ADDR(vkCmdDispatchIndirect);
	VK_GET_PROC_ADDR(vkCmdCopyBuffer);
	VK_GET_PROC_ADDR(vkCmdCopyImage);
	VK_GET_PROC_ADDR(vkCmdBlitImage);
	VK_GET_PROC_ADDR(vkCmdCopyBufferToImage);
	VK_GET_PROC_ADDR(vkCmdCopyImageToBuffer);
	VK_GET_PROC_ADDR(vkCmdUpdateBuffer);
	VK_GET_PROC_ADDR(vkCmdFillBuffer);
	VK_GET_PROC_ADDR(vkCmdClearColorImage);
	VK_GET_PROC_ADDR(vkCmdClearDepthStencilImage);
	VK_GET_PROC_ADDR(vkCmdClearAttachments);
	VK_GET_PROC_ADDR(vkCmdResolveImage);
	VK_GET_PROC_ADDR(vkCmdSetEvent);
	VK_GET_PROC_ADDR(vkCmdResetEvent);
	VK_GET_PROC_ADDR(vkCmdWaitEvents);
	VK_GET_PROC_ADDR(vkCmdPipelineBarrier);
	VK_GET_PROC_ADDR(vkCmdBeginQuery);
	VK_GET_PROC_ADDR(vkCmdEndQuery);
	VK_GET_PROC_ADDR(vkCmdResetQueryPool);
	VK_GET_PROC_ADDR(vkCmdWriteTimestamp);
	VK_GET_PROC_ADDR(vkCmdCopyQueryPoolResults);
	VK_GET_PROC_ADDR(vkCmdPushConstants);
	VK_GET_PROC_ADDR(vkCmdBeginRenderPass);
	VK_GET_PROC_ADDR(vkCmdNextSubpass);
	VK_GET_PROC_ADDR(vkCmdEndRenderPass);
	VK_GET_PROC_ADDR(vkCmdExecuteCommands);

	#undef VK_GET_PROC_ADDR
	//=================================================================

	if(res == VK_FALSE){
		LOG_ERROR("VK_LoadDeviceAPI: Failed to load all procs.");
		return VK_FALSE;
	}

	l_state = 3;
	return VK_TRUE;
}

void VK_UnloadAPI()
{
	VK_CloseLib();
	l_state = 0;
}

