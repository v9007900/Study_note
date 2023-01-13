#include "include.h"

GLFWwindow *Windows;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    Windows = glfwCreateWindow(900, 800, "标题", NULL, NULL);
    glfwMakeContextCurrent(Windows);
    glfwSwapInterval(0);


    //
}