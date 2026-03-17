#pragma once
#include <string>

class Shader {
public:
    unsigned int ID = 0;

    Shader(const std::string& vertexPath,
           const std::string& fragmentPath);
    ~Shader();

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;

    void use() const;
};
