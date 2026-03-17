#pragma once

class Texture
{
public:

    unsigned int ID = 0;

    Texture(const char* path);
    static Texture solidRGBA(unsigned char r,
                             unsigned char g,
                             unsigned char b,
                             unsigned char a = 255);
    ~Texture();

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    Texture(Texture&& other) noexcept;
    Texture& operator=(Texture&& other) noexcept;

    void bind() const;

private:
    explicit Texture(unsigned int id);
};
