#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <glad/glad.h>
#include <graphics/Texture.h>

Texture::Texture(unsigned int id)
{
    ID = id;
}

Texture::Texture(const char* path)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_S,
        GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_T,
        GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D,
        GL_TEXTURE_MIN_FILTER,
        GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D,
        GL_TEXTURE_MAG_FILTER,
        GL_LINEAR);

    int w, h, c;

    // stb_image loads images with (0,0) at the top-left by default.
    // OpenGL UVs typically assume (0,0) is bottom-left, so flip on load.
    stbi_set_flip_vertically_on_load(1);

    unsigned char* data =
        stbi_load(path, &w, &h, &c, 0);

    if (data)
    {
        const GLenum format =
            (c == 4) ? GL_RGBA :
            (c == 3) ? GL_RGB  :
            (c == 1) ? GL_RED  : GL_RGB;

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            format,
            w,
            h,
            0,
            format,
            GL_UNSIGNED_BYTE,
            data
        );

        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);
}

Texture Texture::solidRGBA(unsigned char r,
                           unsigned char g,
                           unsigned char b,
                           unsigned char a)
{
    unsigned int id = 0;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    const unsigned char pixel[4] = { r, g, b, a };
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        1,
        1,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        pixel
    );
    return Texture(id);
}

Texture::~Texture()
{
    if (ID != 0)
        glDeleteTextures(1, &ID);
}

Texture::Texture(Texture&& other) noexcept
{
    ID = other.ID;
    other.ID = 0;
}

Texture& Texture::operator=(Texture&& other) noexcept
{
    if (this == &other)
        return *this;

    if (ID != 0)
        glDeleteTextures(1, &ID);

    ID = other.ID;
    other.ID = 0;
    return *this;
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, ID);
}
