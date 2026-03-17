#include "core/Shader.h"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

static std::string readFile(const std::string& path)
{
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

Shader::Shader(const std::string& vertexPath,
               const std::string& fragmentPath)
{
    std::string vertexCode = readFile(vertexPath);
    std::string fragmentCode = readFile(fragmentPath);

    const char* vSrc = vertexCode.c_str();
    const char* fSrc = fragmentCode.c_str();

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vSrc, NULL);
    glCompileShader(vertex);
    int success;
    char info[512];

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertex,512,NULL,info);
        std::cout << info << std::endl;
    }

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fSrc, NULL);
    glCompileShader(fragment);
    int success1;
    char info1[512];

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success1);

    if (!success1)
    {
        glGetShaderInfoLog(fragment,512,NULL,info1);
        std::cout << info1 << std::endl;
    }
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    int success2;
    char info2[512];

    glGetProgramiv(ID, GL_LINK_STATUS, &success2);

    if (!success2)
    {
        glGetProgramInfoLog(ID,512,NULL,info2);
        std::cout << info2 << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{
    if (ID != 0)
        glDeleteProgram(ID);
}

Shader::Shader(Shader&& other) noexcept
{
    ID = other.ID;
    other.ID = 0;
}

Shader& Shader::operator=(Shader&& other) noexcept
{
    if (this == &other)
        return *this;

    if (ID != 0)
        glDeleteProgram(ID);

    ID = other.ID;
    other.ID = 0;
    return *this;
}

void Shader::use() const
{
    glUseProgram(ID);
}

