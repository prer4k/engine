#include "engine/Assets.h"

std::shared_ptr<Shader> Assets::shader(const std::string& key,
                                       const std::string& vertPath,
                                       const std::string& fragPath)
{
    if (auto it = shaders.find(key); it != shaders.end())
        return it->second;

    auto s = std::make_shared<Shader>(vertPath, fragPath);
    shaders.emplace(key, s);
    return s;
}

std::shared_ptr<Texture> Assets::texture2D(const std::string& key,
                                           const std::string& path)
{
    if (auto it = textures.find(key); it != textures.end())
        return it->second;

    auto t = std::make_shared<Texture>(path.c_str());
    textures.emplace(key, t);
    return t;
}

std::shared_ptr<Texture> Assets::solidTexture(const std::string& key,
                                              unsigned char r,
                                              unsigned char g,
                                              unsigned char b,
                                              unsigned char a)
{
    if (auto it = textures.find(key); it != textures.end())
        return it->second;

    auto t = std::make_shared<Texture>(Texture::solidRGBA(r, g, b, a));
    textures.emplace(key, t);
    return t;
}

std::shared_ptr<Mesh> Assets::mesh(const std::string& key,
                                   const std::vector<float>& vertices,
                                   int stride)
{
    if (auto it = meshes.find(key); it != meshes.end())
        return it->second;

    auto m = std::make_shared<Mesh>(vertices, stride);
    meshes.emplace(key, m);
    return m;
}

std::shared_ptr<Material> Assets::material(const std::string& key)
{
    if (auto it = materials.find(key); it != materials.end())
        return it->second;

    auto m = std::make_shared<Material>();
    materials.emplace(key, m);
    return m;
}

