#include "vk_loader.h"

#include "../../log.h"



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

// Vulkan 1.0 Core
// ==================================

// Base API
VKAPI_ATTR PFN_vkGetInstanceProcAddr							vkGetInstanceProcAddr = NULL;
VKAPI_ATTR PFN_vkCreateInstance									vkCreateInstance;
VKAPI_ATTR PFN_vkEnumerateInstanceExtensionProperties			vkEnumerateInstanceExtensionProperties;
VKAPI_ATTR PFN_vkEnumerateInstanceLayerProperties				vkEnumerateInstanceLayerProperties;

// Instance API
VKAPI_ATTR PFN_vkGetDeviceProcAddr								vkGetDeviceProcAddr = NULL;
VKAPI_ATTR PFN_vkDestroyInstance								vkDestroyInstance;
VKAPI_ATTR PFN_vkEnumeratePhysicalDevices						vkEnumeratePhysicalDevices;
VKAPI_ATTR PFN_vkGetPhysicalDeviceFeatures						vkGetPhysicalDeviceFeatures;
VKAPI_ATTR PFN_vkGetPhysicalDeviceFormatProperties				vkGetPhysicalDeviceFormatProperties;
VKAPI_ATTR PFN_vkGetPhysicalDeviceImageFormatProperties			vkGetPhysicalDeviceImageFormatProperties;
VKAPI_ATTR PFN_vkGetPhysicalDeviceProperties					vkGetPhysicalDeviceProperties;
VKAPI_ATTR PFN_vkGetPhysicalDeviceQueueFamilyProperties			vkGetPhysicalDeviceQueueFamilyProperties;
VKAPI_ATTR PFN_vkGetPhysicalDeviceMemoryProperties				vkGetPhysicalDeviceMemoryProperties;
VKAPI_ATTR PFN_vkCreateDevice									vkCreateDevice;
VKAPI_ATTR PFN_vkEnumerateDeviceExtensionProperties				vkEnumerateDeviceExtensionProperties;
VKAPI_ATTR PFN_vkEnumerateDeviceLayerProperties					vkEnumerateDeviceLayerProperties;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSparseImageFormatProperties	vkGetPhysicalDeviceSparseImageFormatProperties;

// Device API
VKAPI_ATTR PFN_vkDestroyDevice									vkDestroyDevice;
VKAPI_ATTR PFN_vkGetDeviceQueue									vkGetDeviceQueue;
VKAPI_ATTR PFN_vkQueueSubmit									vkQueueSubmit;
VKAPI_ATTR PFN_vkQueueWaitIdle									vkQueueWaitIdle;
VKAPI_ATTR PFN_vkDeviceWaitIdle									vkDeviceWaitIdle;
VKAPI_ATTR PFN_vkAllocateMemory									vkAllocateMemory;
VKAPI_ATTR PFN_vkFreeMemory										vkFreeMemory;
VKAPI_ATTR PFN_vkMapMemory										vkMapMemory;
VKAPI_ATTR PFN_vkUnmapMemory									vkUnmapMemory;
VKAPI_ATTR PFN_vkFlushMappedMemoryRanges						vkFlushMappedMemoryRanges;
VKAPI_ATTR PFN_vkInvalidateMappedMemoryRanges					vkInvalidateMappedMemoryRanges;
VKAPI_ATTR PFN_vkGetDeviceMemoryCommitment						vkGetDeviceMemoryCommitment;
VKAPI_ATTR PFN_vkBindBufferMemory								vkBindBufferMemory;
VKAPI_ATTR PFN_vkBindImageMemory								vkBindImageMemory;
VKAPI_ATTR PFN_vkGetBufferMemoryRequirements					vkGetBufferMemoryRequirements;
VKAPI_ATTR PFN_vkGetImageMemoryRequirements						vkGetImageMemoryRequirements;
VKAPI_ATTR PFN_vkGetImageSparseMemoryRequirements				vkGetImageSparseMemoryRequirements;
VKAPI_ATTR PFN_vkQueueBindSparse								vkQueueBindSparse;
VKAPI_ATTR PFN_vkCreateFence									vkCreateFence;
VKAPI_ATTR PFN_vkDestroyFence									vkDestroyFence;
VKAPI_ATTR PFN_vkResetFences									vkResetFences;
VKAPI_ATTR PFN_vkGetFenceStatus									vkGetFenceStatus;
VKAPI_ATTR PFN_vkWaitForFences									vkWaitForFences;
VKAPI_ATTR PFN_vkCreateSemaphore								vkCreateSemaphore;
VKAPI_ATTR PFN_vkDestroySemaphore								vkDestroySemaphore;
VKAPI_ATTR PFN_vkCreateEvent									vkCreateEvent;
VKAPI_ATTR PFN_vkDestroyEvent									vkDestroyEvent;
VKAPI_ATTR PFN_vkGetEventStatus									vkGetEventStatus;
VKAPI_ATTR PFN_vkSetEvent										vkSetEvent;
VKAPI_ATTR PFN_vkResetEvent										vkResetEvent;
VKAPI_ATTR PFN_vkCreateQueryPool								vkCreateQueryPool;
VKAPI_ATTR PFN_vkDestroyQueryPool								vkDestroyQueryPool;
VKAPI_ATTR PFN_vkGetQueryPoolResults							vkGetQueryPoolResults;
VKAPI_ATTR PFN_vkCreateBuffer									vkCreateBuffer;
VKAPI_ATTR PFN_vkDestroyBuffer									vkDestroyBuffer;
VKAPI_ATTR PFN_vkCreateBufferView								vkCreateBufferView;
VKAPI_ATTR PFN_vkDestroyBufferView								vkDestroyBufferView;
VKAPI_ATTR PFN_vkCreateImage									vkCreateImage;
VKAPI_ATTR PFN_vkDestroyImage									vkDestroyImage;
VKAPI_ATTR PFN_vkGetImageSubresourceLayout						vkGetImageSubresourceLayout;
VKAPI_ATTR PFN_vkCreateImageView								vkCreateImageView;
VKAPI_ATTR PFN_vkDestroyImageView								vkDestroyImageView;
VKAPI_ATTR PFN_vkCreateShaderModule								vkCreateShaderModule;
VKAPI_ATTR PFN_vkDestroyShaderModule							vkDestroyShaderModule;
VKAPI_ATTR PFN_vkCreatePipelineCache							vkCreatePipelineCache;
VKAPI_ATTR PFN_vkDestroyPipelineCache							vkDestroyPipelineCache;
VKAPI_ATTR PFN_vkGetPipelineCacheData							vkGetPipelineCacheData;
VKAPI_ATTR PFN_vkMergePipelineCaches							vkMergePipelineCaches;
VKAPI_ATTR PFN_vkCreateGraphicsPipelines						vkCreateGraphicsPipelines;
VKAPI_ATTR PFN_vkCreateComputePipelines							vkCreateComputePipelines;
VKAPI_ATTR PFN_vkDestroyPipeline								vkDestroyPipeline;
VKAPI_ATTR PFN_vkCreatePipelineLayout							vkCreatePipelineLayout;
VKAPI_ATTR PFN_vkDestroyPipelineLayout							vkDestroyPipelineLayout;
VKAPI_ATTR PFN_vkCreateSampler									vkCreateSampler;
VKAPI_ATTR PFN_vkDestroySampler									vkDestroySampler;
VKAPI_ATTR PFN_vkCreateDescriptorSetLayout						vkCreateDescriptorSetLayout;
VKAPI_ATTR PFN_vkDestroyDescriptorSetLayout						vkDestroyDescriptorSetLayout;
VKAPI_ATTR PFN_vkCreateDescriptorPool							vkCreateDescriptorPool;
VKAPI_ATTR PFN_vkDestroyDescriptorPool							vkDestroyDescriptorPool;
VKAPI_ATTR PFN_vkResetDescriptorPool							vkResetDescriptorPool;
VKAPI_ATTR PFN_vkAllocateDescriptorSets							vkAllocateDescriptorSets;
VKAPI_ATTR PFN_vkFreeDescriptorSets								vkFreeDescriptorSets;
VKAPI_ATTR PFN_vkUpdateDescriptorSets							vkUpdateDescriptorSets;
VKAPI_ATTR PFN_vkCreateFramebuffer								vkCreateFramebuffer;
VKAPI_ATTR PFN_vkDestroyFramebuffer								vkDestroyFramebuffer;
VKAPI_ATTR PFN_vkCreateRenderPass								vkCreateRenderPass;
VKAPI_ATTR PFN_vkDestroyRenderPass								vkDestroyRenderPass;
VKAPI_ATTR PFN_vkGetRenderAreaGranularity						vkGetRenderAreaGranularity;
VKAPI_ATTR PFN_vkCreateCommandPool								vkCreateCommandPool;
VKAPI_ATTR PFN_vkDestroyCommandPool								vkDestroyCommandPool;
VKAPI_ATTR PFN_vkResetCommandPool								vkResetCommandPool;
VKAPI_ATTR PFN_vkAllocateCommandBuffers							vkAllocateCommandBuffers;
VKAPI_ATTR PFN_vkFreeCommandBuffers								vkFreeCommandBuffers;
VKAPI_ATTR PFN_vkBeginCommandBuffer								vkBeginCommandBuffer;
VKAPI_ATTR PFN_vkEndCommandBuffer								vkEndCommandBuffer;
VKAPI_ATTR PFN_vkResetCommandBuffer								vkResetCommandBuffer;
VKAPI_ATTR PFN_vkCmdBindPipeline								vkCmdBindPipeline;
VKAPI_ATTR PFN_vkCmdSetViewport									vkCmdSetViewport;
VKAPI_ATTR PFN_vkCmdSetScissor									vkCmdSetScissor;
VKAPI_ATTR PFN_vkCmdSetLineWidth								vkCmdSetLineWidth;
VKAPI_ATTR PFN_vkCmdSetDepthBias								vkCmdSetDepthBias;
VKAPI_ATTR PFN_vkCmdSetBlendConstants							vkCmdSetBlendConstants;
VKAPI_ATTR PFN_vkCmdSetDepthBounds								vkCmdSetDepthBounds;
VKAPI_ATTR PFN_vkCmdSetStencilCompareMask						vkCmdSetStencilCompareMask;
VKAPI_ATTR PFN_vkCmdSetStencilWriteMask							vkCmdSetStencilWriteMask;
VKAPI_ATTR PFN_vkCmdSetStencilReference							vkCmdSetStencilReference;
VKAPI_ATTR PFN_vkCmdBindDescriptorSets							vkCmdBindDescriptorSets;
VKAPI_ATTR PFN_vkCmdBindIndexBuffer								vkCmdBindIndexBuffer;
VKAPI_ATTR PFN_vkCmdBindVertexBuffers							vkCmdBindVertexBuffers;
VKAPI_ATTR PFN_vkCmdDraw										vkCmdDraw;
VKAPI_ATTR PFN_vkCmdDrawIndexed									vkCmdDrawIndexed;
VKAPI_ATTR PFN_vkCmdDrawIndirect								vkCmdDrawIndirect;
VKAPI_ATTR PFN_vkCmdDrawIndexedIndirect							vkCmdDrawIndexedIndirect;
VKAPI_ATTR PFN_vkCmdDispatch									vkCmdDispatch;
VKAPI_ATTR PFN_vkCmdDispatchIndirect							vkCmdDispatchIndirect;
VKAPI_ATTR PFN_vkCmdCopyBuffer									vkCmdCopyBuffer;
VKAPI_ATTR PFN_vkCmdCopyImage									vkCmdCopyImage;
VKAPI_ATTR PFN_vkCmdBlitImage									vkCmdBlitImage;
VKAPI_ATTR PFN_vkCmdCopyBufferToImage							vkCmdCopyBufferToImage;
VKAPI_ATTR PFN_vkCmdCopyImageToBuffer							vkCmdCopyImageToBuffer;
VKAPI_ATTR PFN_vkCmdUpdateBuffer								vkCmdUpdateBuffer;
VKAPI_ATTR PFN_vkCmdFillBuffer									vkCmdFillBuffer;
VKAPI_ATTR PFN_vkCmdClearColorImage								vkCmdClearColorImage;
VKAPI_ATTR PFN_vkCmdClearDepthStencilImage						vkCmdClearDepthStencilImage;
VKAPI_ATTR PFN_vkCmdClearAttachments							vkCmdClearAttachments;
VKAPI_ATTR PFN_vkCmdResolveImage								vkCmdResolveImage;
VKAPI_ATTR PFN_vkCmdSetEvent									vkCmdSetEvent;
VKAPI_ATTR PFN_vkCmdResetEvent									vkCmdResetEvent;
VKAPI_ATTR PFN_vkCmdWaitEvents									vkCmdWaitEvents;
VKAPI_ATTR PFN_vkCmdPipelineBarrier								vkCmdPipelineBarrier;
VKAPI_ATTR PFN_vkCmdBeginQuery									vkCmdBeginQuery;
VKAPI_ATTR PFN_vkCmdEndQuery									vkCmdEndQuery;
VKAPI_ATTR PFN_vkCmdResetQueryPool								vkCmdResetQueryPool;
VKAPI_ATTR PFN_vkCmdWriteTimestamp								vkCmdWriteTimestamp;
VKAPI_ATTR PFN_vkCmdCopyQueryPoolResults						vkCmdCopyQueryPoolResults;
VKAPI_ATTR PFN_vkCmdPushConstants								vkCmdPushConstants;
VKAPI_ATTR PFN_vkCmdBeginRenderPass								vkCmdBeginRenderPass;
VKAPI_ATTR PFN_vkCmdNextSubpass									vkCmdNextSubpass;
VKAPI_ATTR PFN_vkCmdEndRenderPass								vkCmdEndRenderPass;
VKAPI_ATTR PFN_vkCmdExecuteCommands								vkCmdExecuteCommands;

// Instance Extensions
// ==================================

// VK_EXT_debug_report
VKAPI_ATTR PFN_vkCreateDebugReportCallbackEXT					vkCreateDebugReportCallbackEXT;
VKAPI_ATTR PFN_vkDestroyDebugReportCallbackEXT					vkDestroyDebugReportCallbackEXT;
VKAPI_ATTR PFN_vkDebugReportMessageEXT							vkDebugReportMessageEXT;

// VK_KHR_surface
VKAPI_ATTR PFN_vkDestroySurfaceKHR								vkDestroySurfaceKHR;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfaceSupportKHR				vkGetPhysicalDeviceSurfaceSupportKHR;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR		vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfaceFormatsKHR				vkGetPhysicalDeviceSurfaceFormatsKHR;
VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfacePresentModesKHR		vkGetPhysicalDeviceSurfacePresentModesKHR;

#if 0
// VK_KHR_display
VKAPI_ATTR PFN_vkGetPhysicalDeviceDisplayPropertiesKHR			vkGetPhysicalDeviceDisplayPropertiesKHR;
VKAPI_ATTR PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR		vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
VKAPI_ATTR PFN_vkGetDisplayPlaneSupportedDisplaysKHR			vkGetDisplayPlaneSupportedDisplaysKHR;
VKAPI_ATTR PFN_vkGetDisplayModePropertiesKHR					vkGetDisplayModePropertiesKHR;
VKAPI_ATTR PFN_vkCreateDisplayModeKHR							vkCreateDisplayModeKHR;
VKAPI_ATTR PFN_vkGetDisplayPlaneCapabilitiesKHR					vkGetDisplayPlaneCapabilitiesKHR;
VKAPI_ATTR PFN_vkCreateDisplayPlaneSurfaceKHR					vkCreateDisplayPlaneSurfaceKHR;
#endif

// VK_KHR_xlib_surface
#ifdef VK_USE_PLATFORM_XLIB_KHR
extern VKAPI_ATTR PFN_vkCreateXlibSurfaceKHR							vkCreateXlibSurfaceKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR		vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif

// VK_KHR_xcb_surface
#ifdef VK_USE_PLATFORM_XCB_KHR
extern VKAPI_ATTR PFN_vkCreateXcbSurfaceKHR								vkCreateXcbSurfaceKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR		vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif

// VK_KHR_wayland_surface
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
extern VKAPI_ATTR PFN_vkCreateWaylandSurfaceKHR							vkCreateWaylandSurfaceKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR	vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif

// VK_KHR_mir_surface
#ifdef VK_USE_PLATFORM_MIR_KHR
extern VKAPI_ATTR PFN_vkCreateMirSurfaceKHR								vkCreateMirSurfaceKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceMirPresentationSupportKHR		vkGetPhysicalDeviceMirPresentationSupportKHR;
#endif

// VK_KHR_android_surface
#ifdef VK_USE_PLATFORM_ANDROID_KHR
extern VKAPI_ATTR PFN_vkCreateAndroidSurfaceKHR							vkCreateAndroidSurfaceKHR;
#endif

// VK_KHR_win32_surface
#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR PFN_vkCreateWin32SurfaceKHR							vkCreateWin32SurfaceKHR;
VKAPI_ATTR PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR	vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif

// Device Extensions
// ==================================

// VK_KHR_swapchain
VKAPI_ATTR PFN_vkCreateSwapchainKHR								vkCreateSwapchainKHR;
VKAPI_ATTR PFN_vkDestroySwapchainKHR							vkDestroySwapchainKHR;
VKAPI_ATTR PFN_vkGetSwapchainImagesKHR							vkGetSwapchainImagesKHR;
VKAPI_ATTR PFN_vkAcquireNextImageKHR							vkAcquireNextImageKHR;
VKAPI_ATTR PFN_vkQueuePresentKHR								vkQueuePresentKHR;

#if 0
// VK_KHR_display_swapchain
VKAPI_ATTR PFN_vkCreateSharedSwapchainsKHR						vkCreateSharedSwapchainsKHR;
#endif



// Platform specific library loading
// ==================================

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
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
		LOG_ERROR("VK_GetProcAddr: Vulkan dynamic library is not loaded!");
		return NULL;
	}

	return (PFN_vkVoidFunction)GetProcAddress(l_libvulkan, procName);
}
#elif defined(__UNIX__)

#endif

// API Loading
// ==================================

VkBool32 VK_LoadBaseAPI()
{
	// LOG("Updating your drivers may solve this issue.");

	VkBool32 res;

	if(VK_OpenLib() == VK_FALSE){
		LOG_ERROR("VK_LoadBaseAPI: Failed to open Vulkan dynamic library.");
		return VK_FALSE;
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
	VK_GET_PROC_ADDR(vkCreateInstance);
	VK_GET_PROC_ADDR(vkEnumerateInstanceExtensionProperties);
	VK_GET_PROC_ADDR(vkEnumerateInstanceLayerProperties);

	#undef VK_GET_PROC_ADDR
	//=================================================================

	if(res == VK_FALSE){
		LOG_ERROR("VK_LoadBaseAPI: Failed to load all procs.");
		VK_CloseLib();
		vkGetInstanceProcAddr = NULL;
		return VK_FALSE;
	}

	// retrieve instance extensions
	//uint32_t extensionCount;
	//VkExtensionProperties ext;
	//vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, &ext);

	// retrieve instance layers

	return VK_TRUE;
}

VkBool32 VK_LoadInstanceAPI(VkInstance instance)
{
	VkBool32 res;

	if(VK_IsLibOpen() == VK_FALSE || vkGetInstanceProcAddr == NULL){
		LOG_ERROR("VK_LoadInstanceAPI: Base API not loaded!");
		return VK_FALSE;
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

	//if(VKL_EXT_debug_report == VK_TRUE){
		VK_GET_PROC_ADDR(vkCreateDebugReportCallbackEXT);
		VK_GET_PROC_ADDR(vkDestroyDebugReportCallbackEXT);
		VK_GET_PROC_ADDR(vkDebugReportMessageEXT);
	//}

	//if(VKL_KHR_surface == VK_TRUE){
		VK_GET_PROC_ADDR(vkDestroySurfaceKHR);
		VK_GET_PROC_ADDR(vkGetPhysicalDeviceSurfaceSupportKHR);
		VK_GET_PROC_ADDR(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
		VK_GET_PROC_ADDR(vkGetPhysicalDeviceSurfaceFormatsKHR);
		VK_GET_PROC_ADDR(vkGetPhysicalDeviceSurfacePresentModesKHR);
	//}

#if 0
	//if(VKL_KHR_display == VK_TRUE){
		VK_GET_PROC_ADDR(vkGetPhysicalDeviceDisplayPropertiesKHR);
		VK_GET_PROC_ADDR(vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
		VK_GET_PROC_ADDR(vkGetDisplayPlaneSupportedDisplaysKHR);
		VK_GET_PROC_ADDR(vkGetDisplayModePropertiesKHR);
		VK_GET_PROC_ADDR(vkCreateDisplayModeKHR);
		VK_GET_PROC_ADDR(vkGetDisplayPlaneCapabilitiesKHR);
		VK_GET_PROC_ADDR(vkCreateDisplayPlaneSurfaceKHR);
	//}
#endif

#ifdef VK_USE_PLATFORM_XLIB_KHR
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
#endif

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
#endif

#ifdef VK_USE_PLATFORM_MIR_KHR
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
	//if(VKL_KHR_win32_surface == VK_TRUE){
		VK_GET_PROC_ADDR(vkCreateWin32SurfaceKHR);
		VK_GET_PROC_ADDR(vkGetPhysicalDeviceWin32PresentationSupportKHR);
	//}
#endif

	#undef VK_GET_PROC_ADDR
	//=================================================================

	if(res == VK_FALSE){
		LOG_ERROR("VK_LoadInstanceAPI: Failed to load all procs.");
		return VK_FALSE;
	}

	return VK_TRUE;
}

VkBool32 VK_LoadDeviceAPI(VkDevice device)
{
	VkBool32 res;

	if(VK_IsLibOpen() == VK_FALSE || vkGetDeviceProcAddr == NULL){
		LOG_ERROR("VK_LoadDeviceAPI: Instance API not loaded!");
		return VK_FALSE;
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

#if 0
	//if(VKL_KHR_display_swapchain){
		VK_GET_PROC_ADDR(vkCreateSharedSwapchainsKHR);
	//}
#endif

	#undef VK_GET_PROC_ADDR
	//=================================================================

	if(res == VK_FALSE){
		LOG_ERROR("VK_LoadDeviceAPI: Failed to load all procs.");
		return VK_FALSE;
	}

	return VK_TRUE;
}

void VK_UnloadAPI()
{
	VK_CloseLib();
	vkGetInstanceProcAddr = NULL;
	vkGetDeviceProcAddr = NULL;
}