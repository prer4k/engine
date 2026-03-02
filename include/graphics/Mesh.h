#pragma once

#include <vector>

class Mesh
{
private:

    unsigned int VAO;
    unsigned int VBO;

    int vertexCount;

public:

    Mesh(const std::vector<float>& vertices,
         int stride);

    void draw();
};
