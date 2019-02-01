#pragma once
#include "../../glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

// glfw: initialize and configure
// ------------------------------
void InitGLFW();

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// glfw window creation
// --------------------
GLFWwindow *glfwInitializeWindow();

// glad: load all OpenGL function pointers
// ---------------------------------------
int LoadGlad();