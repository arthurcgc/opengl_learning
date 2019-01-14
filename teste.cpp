#include <iostream>
#include <bits/stdc++.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>


int main(int argc, char *argv[])
{
    // Initialize the library
    if(!glfwInit())
        return -1;


    // create a windowed mode context and its opengl context
    GLFWwindow *window;
    window = glfwCreateWindow(1080, 720, "Hello World", nullptr, nullptr);

    // make the window's context current
    glfwMakeContextCurrent(window);

    if(!window)
    {
        glfwTerminate();
        return -1;
    }


    if(glewInit()!= GLEW_OK)
    {
        std::cout << "error" << std::endl;
    }

    //defining a buffer that will be used to bind to opengl so that we can draw with it on the screen
    unsigned int buff1;
    glGenBuffers(1, &buff1);
    glBindBuffer(GL_ARRAY_BUFFER, buff1);

    // defining a vector of points that we want to draw, in this case it is a triangle
    double positions[6] = 
    {
        -0.5, -0.5,
        0.0, 0.5,
        0.5, 0.5
    };



    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, sizeof(double)*2, 0);


    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
    }
    return 0;
}
