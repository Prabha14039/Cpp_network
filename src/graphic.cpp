#include"../include/graphic.h"

Window::Window(int height_ ,int width_):height(height_),width(width_)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
}

Window::~Window()
{
    glfwTerminate();
}

void Window::framebuffer_size_callback(GLFWwindow* win, int width, int height) {
    // Retrieve the user pointer (this instance)
    Window* self = static_cast<Window*>(glfwGetWindowUserPointer(win));
    if (self) {
        self->width = width;
        self->height = height;
        glViewport(0, 0, width, height);
    }
}

void Window::processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

std::optional<int> Window::createWindow()
{
    GLFWwindow *window = glfwCreateWindow(width,height,"MySpace",NULL,NULL);
    if (window==NULL)
    {
        std::cerr<< "Failed to create a window\n";
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr<<"failed to initialise GLAD\n";
    }

    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
