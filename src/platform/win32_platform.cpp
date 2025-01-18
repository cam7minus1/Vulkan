#include <windows.h> // Windows-specific header for window creation and management.
#include "renderer/vk_renderer.cpp" // Custom Vulkan renderer implementation.

// Global flag to control the main application loop.
static bool running = true;

// Callback function for processing Windows messages.
// This function is called by the OS whenever there is an event related to the window.
LRESULT CALLBACK platform_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) // Check the type of message received.
    {
    case WM_CLOSE: // WM_CLOSE is sent when the user tries to close the window.
        running = false; // Stop the application loop when the window is closed.
        break;
    }

    // Pass unhandled messages to the default Windows procedure for processing.
    return DefWindowProcA(window, msg, wParam, lParam);
}

// Function to create a new window using the Windows API.
// Returns true if the window was created successfully, false otherwise.
bool platform_create_window(HWND window)
{
    // Get the instance handle of the current application.
    HINSTANCE instance = GetModuleHandleA(0);

    // Define the window class properties.
    WNDCLASS wc = {}; // Initialize the WNDCLASS structure with zeros.
    wc.lpfnWndProc = platform_window_callback; // Set the callback function for window events.
    wc.hInstance = instance; // Set the instance of the application.
    wc.lpszClassName = "vulkan_engine_class"; // Unique name for the window class.
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Load the default arrow cursor.

    // Register the window class with the OS.
    if (!RegisterClassA(&wc)) // If registration fails, return false.
    {
        MessageBoxA(window, "Failed registering window class", "Error", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    // Create the actual window using the registered class.
    window = CreateWindowExA(
        WS_EX_APPWINDOW, // Extended window style.
        "vulkan_engine_class", // Class name (must match the registered class).
        "vulkan", // Window title.
        WS_THICKFRAME | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_OVERLAPPED, // Window styles.
        100, 100, // Initial position of the window (x, y).
        1600, 720, // Initial size of the window (width, height).
        0, 0, // Parent window and menu (none in this case).
        instance, // Application instance.
        0); // Additional parameters (none in this case).

    if (window == 0) // If window creation fails, return false.
    {
        MessageBoxA(window, "Failed creating window", "Error", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    // Make the window visible.
    ShowWindow(window, SW_SHOW);

    return true; // Window creation successful.
}

// Function to process window messages (e.g., user input, resizing, etc.).
void platform_update_window(HWND window)
{
    MSG msg; // Structure to store message information.

    // Process all messages in the message queue for the window.
    while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE)) // Non-blocking check for messages.
    {
        TranslateMessage(&msg); // Translates virtual key messages into character messages.
        DispatchMessageA(&msg); // Dispatches the message to the appropriate window procedure.
    }
}

// Entry point of the program.
int main()
{
    VkContext vkcontext = {}; // Vulkan context structure for graphics rendering.

    HWND window = 0; // Handle to the window (initially set to 0).

    // Create the window. If it fails, exit with an error code.
    if (!platform_create_window(window))
    {
        return -1;
    }

    // Initialize the Vulkan context for rendering. If it fails, exit with an error code.
    if (!vk_init(&vkcontext))
    {
        return -1;
    }

    // Main application loop.
    // The loop continues until the "running" flag is set to false (e.g., when the window is closed).
    while (running)
    {
        platform_update_window(window); // Update the window (process messages).
    }

    return 0; // Exit the application.
}
