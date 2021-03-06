#include "../../glad/glad.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include "init_shortcuts.hpp"
#include "shaders.hpp"
#include "bspline/bspline.h"
#include <bits/stdc++.h>

void processInput(GLFWwindow *window);


vector<float> getVertices(BSpline *spline)
{
    std::vector<double> p_x;
    std::vector<double> p_y;
    spline->CopyPoints(p_x, p_y);


    std::vector<float> vector_vertices;

    for(int i = 0; i < p_x.size(); i++)
    {
        vector_vertices.push_back( p_x[i]/9 );
        vector_vertices.push_back( p_y[i]/9 );
        vector_vertices.push_back(0.0f);
    }

    return vector_vertices;

}


int main()
{
    InitGLFW();

    // glfw window creation
    // --------------------
    GLFWwindow *mainWindow = glfwInitializeWindow();
    if (mainWindow == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    LoadGlad();

    int vertexShader = CreateAndCompileShader("vertex");
    int fragmentShader = CreateAndCompileShader("fragment");
    int shaderProgram = glCreateProgram();

    LinkShader(vertexShader, shaderProgram);
    LinkShader(fragmentShader, shaderProgram);

    BSpline *spline = new BSpline({make_pair(1.0,4.5), make_pair(2.7,6), make_pair(5.3,3), make_pair(9,9)}, 0.001);

    vector<float> vertices = getVertices(spline);


    //////////////////////////////////////////////////
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
    /////////////////////////////////////////////////

    
    vector<double> vx;
    vector<double> vy;
    spline->CopyPoints(vx, vy);
    // render loop
    // -----------
    while (!glfwWindowShouldClose(mainWindow))
    {
        // input
        // -----
        processInput(mainWindow);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_LINE_STRIP, 0, vertices.size()/3);

        glBindVertexArray(0); // no need to unbind it every time 

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(mainWindow);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

