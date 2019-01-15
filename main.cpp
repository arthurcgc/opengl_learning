#include <iostream>
#include <bits/stdc++.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <alloca.h>


static GLuint CompileShader(GLuint type, const std::string &source)
{
    GLuint id = glCreateShader(type); 
    const char *src = &source[0];
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << message << std::endl;
    }
    
    return id;
}

static int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    //program binds vertex and fragment shaders togheter
    GLuint program = glCreateProgram();
    // vs = vertex shader
    GLuint vs =  CompileShader(GL_VERTEX_SHADER, vertexShader); 
    GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);


    // attaching shaders to program
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    // initializing program
    glLinkProgram(program);
    glValidateProgram(program);

    // basically freeig the pointers
    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}


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



    std::string vertexShader = 
        "version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n "
        "}\n";

    std::string fragmentShader = 
    "version 330 core\n"
    "\n"
    "layout(location = 0) in vec4 color;\n"
    "void main()\n"
    "{\n"
    "   color = vec4(1.0, 0.7, 0.5, 1.0);\n "
    "}\n";
    

    GLuint shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);


    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers*/
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    
    return 0;
}
