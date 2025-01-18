#include <vulkan/vulkan.h> // Vulkan header for graphics and compute operations.

// Structure to hold Vulkan context information.
// This structure is used to manage Vulkan resources like the instance.
struct VkContext
{
    VkInstance instance; // Vulkan instance handle (represents the connection between the application and the Vulkan library).
};

// Function to initialize the Vulkan context.
// Takes a pointer to a VkContext structure to populate its instance field.
bool vk_init(VkContext *vkcontext)
{
    // Define application-level information for Vulkan.
    VkApplicationInfo appInfo = {}; // Structure to provide information about the application.
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO; // Specify the type of this structure (required).
    appInfo.pApplicationName = "Vulkan"; // Name of the application.
    appInfo.pEngineName = "vulkan_engine"; // Name of the engine (optional).

    // Define the Vulkan instance creation information.
    VkInstanceCreateInfo instanceInfo = {}; // Structure to provide information for creating a Vulkan instance.
    instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO; // Specify the type of this structure (required).
    instanceInfo.pApplicationInfo = &appInfo; // Link the application info to the instance creation info.

    // Create the Vulkan instance using the provided creation info.
    // The third parameter is an optional allocator (set to 0 for default allocation behavior).
    // The instance handle is stored in the vkcontext->instance field.
    VkResult result = vkCreateInstance(&instanceInfo, 0, &vkcontext->instance);

    // Check if the Vulkan instance was created successfully.
    if (result == VK_SUCCESS)
    {
        return true; // Return true if instance creation succeeded.
    }

    return false; // Return false if instance creation failed.
}
