#pragma once
#include "../../glad/glad.h"
#include <string>
#include <iostream>

int CreateAndCompileShader(std::string);

int LinkShader(int shader, int &shaderProgram);