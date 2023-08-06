VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibDir = {}
LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"

Lib = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"