#ifndef __VK_LOADER_H__
#define __VK_LOADER_H__

// TODO: add other platforms defines

#ifdef _WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#endif

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>
#include <vulkan/vk_sdk_platform.h>


// Vulkan 1.0 Core
// ==================================

// Base API
extern VKAPI_ATTR PFN_vkGetInstanceProcAddr								vkGetInstanceProcAddr;
extern VKAPI_ATTR PFN_vkCreateInstance									vkCreateInstance;
extern VKAPI_ATTR PFN_vkEnumerateInstanceExtensionProperties			vkEnumerateInstanceExtensionProperties;
extern VKAPI_ATTR PFN_vkEnumerateInstanceLayerProperties				vkEnumerateInstanceLayerProperties;

// Instance API
extern VKAPI_ATTR PFN_vkGetDeviceProcAddr								vkGetDeviceProcAddr;
extern VKAPI_ATTR PFN_vkDestroyInstance									vkDestroyInstance;
extern VKAPI_ATTR PFN_vkEnumeratePhysicalDevices						vkEnumeratePhysicalDevices;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceFeatures						vkGetPhysicalDeviceFeatures;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceFormatProperties				vkGetPhysicalDeviceFormatProperties;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceImageFormatProperties			vkGetPhysicalDeviceImageFormatProperties;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceProperties						vkGetPhysicalDeviceProperties;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceQueueFamilyProperties			vkGetPhysicalDeviceQueueFamilyProperties;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceMemoryProperties				vkGetPhysicalDeviceMemoryProperties;
extern VKAPI_ATTR PFN_vkCreateDevice									vkCreateDevice;
extern VKAPI_ATTR PFN_vkEnumerateDeviceExtensionProperties				vkEnumerateDeviceExtensionProperties;
extern VKAPI_ATTR PFN_vkEnumerateDeviceLayerProperties					vkEnumerateDeviceLayerProperties;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceSparseImageFormatProperties	vkGetPhysicalDeviceSparseImageFormatProperties;

// Device API
extern VKAPI_ATTR PFN_vkDestroyDevice									vkDestroyDevice;
extern VKAPI_ATTR PFN_vkGetDeviceQueue									vkGetDeviceQueue;
extern VKAPI_ATTR PFN_vkQueueSubmit										vkQueueSubmit;
extern VKAPI_ATTR PFN_vkQueueWaitIdle									vkQueueWaitIdle;
extern VKAPI_ATTR PFN_vkDeviceWaitIdle									vkDeviceWaitIdle;
extern VKAPI_ATTR PFN_vkAllocateMemory									vkAllocateMemory;
extern VKAPI_ATTR PFN_vkFreeMemory										vkFreeMemory;
extern VKAPI_ATTR PFN_vkMapMemory										vkMapMemory;
extern VKAPI_ATTR PFN_vkUnmapMemory										vkUnmapMemory;
extern VKAPI_ATTR PFN_vkFlushMappedMemoryRanges							vkFlushMappedMemoryRanges;
extern VKAPI_ATTR PFN_vkInvalidateMappedMemoryRanges					vkInvalidateMappedMemoryRanges;
extern VKAPI_ATTR PFN_vkGetDeviceMemoryCommitment						vkGetDeviceMemoryCommitment;
extern VKAPI_ATTR PFN_vkBindBufferMemory								vkBindBufferMemory;
extern VKAPI_ATTR PFN_vkBindImageMemory									vkBindImageMemory;
extern VKAPI_ATTR PFN_vkGetBufferMemoryRequirements						vkGetBufferMemoryRequirements;
extern VKAPI_ATTR PFN_vkGetImageMemoryRequirements						vkGetImageMemoryRequirements;
extern VKAPI_ATTR PFN_vkGetImageSparseMemoryRequirements				vkGetImageSparseMemoryRequirements;
extern VKAPI_ATTR PFN_vkQueueBindSparse									vkQueueBindSparse;
extern VKAPI_ATTR PFN_vkCreateFence										vkCreateFence;
extern VKAPI_ATTR PFN_vkDestroyFence									vkDestroyFence;
extern VKAPI_ATTR PFN_vkResetFences										vkResetFences;
extern VKAPI_ATTR PFN_vkGetFenceStatus									vkGetFenceStatus;
extern VKAPI_ATTR PFN_vkWaitForFences									vkWaitForFences;
extern VKAPI_ATTR PFN_vkCreateSemaphore									vkCreateSemaphore;
extern VKAPI_ATTR PFN_vkDestroySemaphore								vkDestroySemaphore;
extern VKAPI_ATTR PFN_vkCreateEvent										vkCreateEvent;
extern VKAPI_ATTR PFN_vkDestroyEvent									vkDestroyEvent;
extern VKAPI_ATTR PFN_vkGetEventStatus									vkGetEventStatus;
extern VKAPI_ATTR PFN_vkSetEvent										vkSetEvent;
extern VKAPI_ATTR PFN_vkResetEvent										vkResetEvent;
extern VKAPI_ATTR PFN_vkCreateQueryPool									vkCreateQueryPool;
extern VKAPI_ATTR PFN_vkDestroyQueryPool								vkDestroyQueryPool;
extern VKAPI_ATTR PFN_vkGetQueryPoolResults								vkGetQueryPoolResults;
extern VKAPI_ATTR PFN_vkCreateBuffer									vkCreateBuffer;
extern VKAPI_ATTR PFN_vkDestroyBuffer									vkDestroyBuffer;
extern VKAPI_ATTR PFN_vkCreateBufferView								vkCreateBufferView;
extern VKAPI_ATTR PFN_vkDestroyBufferView								vkDestroyBufferView;
extern VKAPI_ATTR PFN_vkCreateImage										vkCreateImage;
extern VKAPI_ATTR PFN_vkDestroyImage									vkDestroyImage;
extern VKAPI_ATTR PFN_vkGetImageSubresourceLayout						vkGetImageSubresourceLayout;
extern VKAPI_ATTR PFN_vkCreateImageView									vkCreateImageView;
extern VKAPI_ATTR PFN_vkDestroyImageView								vkDestroyImageView;
extern VKAPI_ATTR PFN_vkCreateShaderModule								vkCreateShaderModule;
extern VKAPI_ATTR PFN_vkDestroyShaderModule								vkDestroyShaderModule;
extern VKAPI_ATTR PFN_vkCreatePipelineCache								vkCreatePipelineCache;
extern VKAPI_ATTR PFN_vkDestroyPipelineCache							vkDestroyPipelineCache;
extern VKAPI_ATTR PFN_vkGetPipelineCacheData							vkGetPipelineCacheData;
extern VKAPI_ATTR PFN_vkMergePipelineCaches								vkMergePipelineCaches;
extern VKAPI_ATTR PFN_vkCreateGraphicsPipelines							vkCreateGraphicsPipelines;
extern VKAPI_ATTR PFN_vkCreateComputePipelines							vkCreateComputePipelines;
extern VKAPI_ATTR PFN_vkDestroyPipeline									vkDestroyPipeline;
extern VKAPI_ATTR PFN_vkCreatePipelineLayout							vkCreatePipelineLayout;
extern VKAPI_ATTR PFN_vkDestroyPipelineLayout							vkDestroyPipelineLayout;
extern VKAPI_ATTR PFN_vkCreateSampler									vkCreateSampler;
extern VKAPI_ATTR PFN_vkDestroySampler									vkDestroySampler;
extern VKAPI_ATTR PFN_vkCreateDescriptorSetLayout						vkCreateDescriptorSetLayout;
extern VKAPI_ATTR PFN_vkDestroyDescriptorSetLayout						vkDestroyDescriptorSetLayout;
extern VKAPI_ATTR PFN_vkCreateDescriptorPool							vkCreateDescriptorPool;
extern VKAPI_ATTR PFN_vkDestroyDescriptorPool							vkDestroyDescriptorPool;
extern VKAPI_ATTR PFN_vkResetDescriptorPool								vkResetDescriptorPool;
extern VKAPI_ATTR PFN_vkAllocateDescriptorSets							vkAllocateDescriptorSets;
extern VKAPI_ATTR PFN_vkFreeDescriptorSets								vkFreeDescriptorSets;
extern VKAPI_ATTR PFN_vkUpdateDescriptorSets							vkUpdateDescriptorSets;
extern VKAPI_ATTR PFN_vkCreateFramebuffer								vkCreateFramebuffer;
extern VKAPI_ATTR PFN_vkDestroyFramebuffer								vkDestroyFramebuffer;
extern VKAPI_ATTR PFN_vkCreateRenderPass								vkCreateRenderPass;
extern VKAPI_ATTR PFN_vkDestroyRenderPass								vkDestroyRenderPass;
extern VKAPI_ATTR PFN_vkGetRenderAreaGranularity						vkGetRenderAreaGranularity;
extern VKAPI_ATTR PFN_vkCreateCommandPool								vkCreateCommandPool;
extern VKAPI_ATTR PFN_vkDestroyCommandPool								vkDestroyCommandPool;
extern VKAPI_ATTR PFN_vkResetCommandPool								vkResetCommandPool;
extern VKAPI_ATTR PFN_vkAllocateCommandBuffers							vkAllocateCommandBuffers;
extern VKAPI_ATTR PFN_vkFreeCommandBuffers								vkFreeCommandBuffers;
extern VKAPI_ATTR PFN_vkBeginCommandBuffer								vkBeginCommandBuffer;
extern VKAPI_ATTR PFN_vkEndCommandBuffer								vkEndCommandBuffer;
extern VKAPI_ATTR PFN_vkResetCommandBuffer								vkResetCommandBuffer;
extern VKAPI_ATTR PFN_vkCmdBindPipeline									vkCmdBindPipeline;
extern VKAPI_ATTR PFN_vkCmdSetViewport									vkCmdSetViewport;
extern VKAPI_ATTR PFN_vkCmdSetScissor									vkCmdSetScissor;
extern VKAPI_ATTR PFN_vkCmdSetLineWidth									vkCmdSetLineWidth;
extern VKAPI_ATTR PFN_vkCmdSetDepthBias									vkCmdSetDepthBias;
extern VKAPI_ATTR PFN_vkCmdSetBlendConstants							vkCmdSetBlendConstants;
extern VKAPI_ATTR PFN_vkCmdSetDepthBounds								vkCmdSetDepthBounds;
extern VKAPI_ATTR PFN_vkCmdSetStencilCompareMask						vkCmdSetStencilCompareMask;
extern VKAPI_ATTR PFN_vkCmdSetStencilWriteMask							vkCmdSetStencilWriteMask;
extern VKAPI_ATTR PFN_vkCmdSetStencilReference							vkCmdSetStencilReference;
extern VKAPI_ATTR PFN_vkCmdBindDescriptorSets							vkCmdBindDescriptorSets;
extern VKAPI_ATTR PFN_vkCmdBindIndexBuffer								vkCmdBindIndexBuffer;
extern VKAPI_ATTR PFN_vkCmdBindVertexBuffers							vkCmdBindVertexBuffers;
extern VKAPI_ATTR PFN_vkCmdDraw											vkCmdDraw;
extern VKAPI_ATTR PFN_vkCmdDrawIndexed									vkCmdDrawIndexed;
extern VKAPI_ATTR PFN_vkCmdDrawIndirect									vkCmdDrawIndirect;
extern VKAPI_ATTR PFN_vkCmdDrawIndexedIndirect							vkCmdDrawIndexedIndirect;
extern VKAPI_ATTR PFN_vkCmdDispatch										vkCmdDispatch;
extern VKAPI_ATTR PFN_vkCmdDispatchIndirect								vkCmdDispatchIndirect;
extern VKAPI_ATTR PFN_vkCmdCopyBuffer									vkCmdCopyBuffer;
extern VKAPI_ATTR PFN_vkCmdCopyImage									vkCmdCopyImage;
extern VKAPI_ATTR PFN_vkCmdBlitImage									vkCmdBlitImage;
extern VKAPI_ATTR PFN_vkCmdCopyBufferToImage							vkCmdCopyBufferToImage;
extern VKAPI_ATTR PFN_vkCmdCopyImageToBuffer							vkCmdCopyImageToBuffer;
extern VKAPI_ATTR PFN_vkCmdUpdateBuffer									vkCmdUpdateBuffer;
extern VKAPI_ATTR PFN_vkCmdFillBuffer									vkCmdFillBuffer;
extern VKAPI_ATTR PFN_vkCmdClearColorImage								vkCmdClearColorImage;
extern VKAPI_ATTR PFN_vkCmdClearDepthStencilImage						vkCmdClearDepthStencilImage;
extern VKAPI_ATTR PFN_vkCmdClearAttachments								vkCmdClearAttachments;
extern VKAPI_ATTR PFN_vkCmdResolveImage									vkCmdResolveImage;
extern VKAPI_ATTR PFN_vkCmdSetEvent										vkCmdSetEvent;
extern VKAPI_ATTR PFN_vkCmdResetEvent									vkCmdResetEvent;
extern VKAPI_ATTR PFN_vkCmdWaitEvents									vkCmdWaitEvents;
extern VKAPI_ATTR PFN_vkCmdPipelineBarrier								vkCmdPipelineBarrier;
extern VKAPI_ATTR PFN_vkCmdBeginQuery									vkCmdBeginQuery;
extern VKAPI_ATTR PFN_vkCmdEndQuery										vkCmdEndQuery;
extern VKAPI_ATTR PFN_vkCmdResetQueryPool								vkCmdResetQueryPool;
extern VKAPI_ATTR PFN_vkCmdWriteTimestamp								vkCmdWriteTimestamp;
extern VKAPI_ATTR PFN_vkCmdCopyQueryPoolResults							vkCmdCopyQueryPoolResults;
extern VKAPI_ATTR PFN_vkCmdPushConstants								vkCmdPushConstants;
extern VKAPI_ATTR PFN_vkCmdBeginRenderPass								vkCmdBeginRenderPass;
extern VKAPI_ATTR PFN_vkCmdNextSubpass									vkCmdNextSubpass;
extern VKAPI_ATTR PFN_vkCmdEndRenderPass								vkCmdEndRenderPass;
extern VKAPI_ATTR PFN_vkCmdExecuteCommands								vkCmdExecuteCommands;

// Instance Extensions
// ==================================

// VK_EXT_debug_report
extern VKAPI_ATTR PFN_vkCreateDebugReportCallbackEXT					vkCreateDebugReportCallbackEXT;
extern VKAPI_ATTR PFN_vkDestroyDebugReportCallbackEXT					vkDestroyDebugReportCallbackEXT;
extern VKAPI_ATTR PFN_vkDebugReportMessageEXT							vkDebugReportMessageEXT;

// VK_KHR_surface
extern VKAPI_ATTR PFN_vkDestroySurfaceKHR								vkDestroySurfaceKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfaceSupportKHR				vkGetPhysicalDeviceSurfaceSupportKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR			vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfaceFormatsKHR				vkGetPhysicalDeviceSurfaceFormatsKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceSurfacePresentModesKHR			vkGetPhysicalDeviceSurfacePresentModesKHR;

#if 0
// VK_KHR_display
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceDisplayPropertiesKHR			vkGetPhysicalDeviceDisplayPropertiesKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR		vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
extern VKAPI_ATTR PFN_vkGetDisplayPlaneSupportedDisplaysKHR				vkGetDisplayPlaneSupportedDisplaysKHR;
extern VKAPI_ATTR PFN_vkGetDisplayModePropertiesKHR						vkGetDisplayModePropertiesKHR;
extern VKAPI_ATTR PFN_vkCreateDisplayModeKHR							vkCreateDisplayModeKHR;
extern VKAPI_ATTR PFN_vkGetDisplayPlaneCapabilitiesKHR					vkGetDisplayPlaneCapabilitiesKHR;
extern VKAPI_ATTR PFN_vkCreateDisplayPlaneSurfaceKHR					vkCreateDisplayPlaneSurfaceKHR;
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
extern VKAPI_ATTR PFN_vkCreateWin32SurfaceKHR							vkCreateWin32SurfaceKHR;
extern VKAPI_ATTR PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR	vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif

// Device Extensions
// ==================================

// VK_KHR_swapchain
extern VKAPI_ATTR PFN_vkCreateSwapchainKHR								vkCreateSwapchainKHR;
extern VKAPI_ATTR PFN_vkDestroySwapchainKHR								vkDestroySwapchainKHR;
extern VKAPI_ATTR PFN_vkGetSwapchainImagesKHR							vkGetSwapchainImagesKHR;
extern VKAPI_ATTR PFN_vkAcquireNextImageKHR								vkAcquireNextImageKHR;
extern VKAPI_ATTR PFN_vkQueuePresentKHR									vkQueuePresentKHR;

#if 0
// VK_KHR_display_swapchain
extern VKAPI_ATTR PFN_vkCreateSharedSwapchainsKHR						vkCreateSharedSwapchainsKHR;
#endif

// API Loading
// ==================================
VkBool32	VK_LoadBaseAPI();
VkBool32	VK_LoadInstanceAPI(VkInstance instance);
VkBool32	VK_LoadDeviceAPI(VkDevice device);

void		VK_UnloadAPI();


#endif //__VK_LOADER_H__