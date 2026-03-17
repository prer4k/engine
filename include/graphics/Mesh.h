#pragma once

#include <vector>

class Mesh
{
private:

    unsigned int VAO = 0;
    unsigned int VBO = 0;

    int vertexCount = 0;

public:

    Mesh(const std::vector<float>& vertices,
         int stride);

    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    Mesh(Mesh&& other) noexcept;
    Mesh& operator=(Mesh&& other) noexcept;

    void draw() const;
};
