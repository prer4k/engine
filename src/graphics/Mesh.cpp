#include "graphics/Mesh.h"

#include <glad/glad.h>

Mesh::Mesh(const std::vector<float>& vertices,
           int stride)
{
    vertexCount = vertices.size() / stride;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(
        GL_ARRAY_BUFFER,
        vertices.size() * sizeof(float),
        vertices.data(),
        GL_STATIC_DRAW
    );

    // position
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        stride * sizeof(float),
        (void*)0
    );
    glEnableVertexAttribArray(0);

    // color
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        stride * sizeof(float),
        (void*)(3*sizeof(float))
    );
    glEnableVertexAttribArray(1);

    // uv
    glVertexAttribPointer(
        2,
        2,
        GL_FLOAT,
        GL_FALSE,
        stride * sizeof(float),
        (void*)(6 * sizeof(float))
    );
    glEnableVertexAttribArray(2);
}

Mesh::~Mesh()
{
    if (VBO != 0)
        glDeleteBuffers(1, &VBO);
    if (VAO != 0)
        glDeleteVertexArrays(1, &VAO);
}

Mesh::Mesh(Mesh&& other) noexcept
{
    VAO = other.VAO;
    VBO = other.VBO;
    vertexCount = other.vertexCount;

    other.VAO = 0;
    other.VBO = 0;
    other.vertexCount = 0;
}

Mesh& Mesh::operator=(Mesh&& other) noexcept
{
    if (this == &other)
        return *this;

    if (VBO != 0)
        glDeleteBuffers(1, &VBO);
    if (VAO != 0)
        glDeleteVertexArrays(1, &VAO);

    VAO = other.VAO;
    VBO = other.VBO;
    vertexCount = other.vertexCount;

    other.VAO = 0;
    other.VBO = 0;
    other.vertexCount = 0;

    return *this;
}

void Mesh::draw() const
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}
