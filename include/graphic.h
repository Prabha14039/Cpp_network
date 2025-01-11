#pragma once

#include"glad.h"
#include<GLFW/glfw3.h>
#include<iostream>
#include<optional>

class Window{
    public:
        Window(int height_=1200,int width_=1200);
        std::optional<int> createWindow();
        static void framebuffer_size_callback(GLFWwindow *,int,int);
        static void  processInput(GLFWwindow*);
        ~Window();
    private:
        int height,width;
};

