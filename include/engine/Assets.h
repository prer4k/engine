#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "core/Shader.h"
#include "graphics/Mesh.h"
#include "graphics/Texture.h"
#include "renderer/Material.h"

class Assets
{
public:
    std::shared_ptr<Shader> shader(const std::string& key,
                                  const std::string& vertPath,
                                  const std::string& fragPath);

    std::shared_ptr<Texture> texture2D(const std::string& key,
                                       const std::string& path);
    std::shared_ptr<Texture> solidTexture(const std::string& key,
                                          unsigned char r,
                                          unsigned char g,
                                          unsigned char b,
                                          unsigned char a = 255);

    std::shared_ptr<Mesh> mesh(const std::string& key,
                               const std::vector<float>& vertices,
                               int stride);

    std::shared_ptr<Material> material(const std::string& key);

private:
    std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
    std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
    std::unordered_map<std::string, std::shared_ptr<Mesh>> meshes;
    std::unordered_map<std::string, std::shared_ptr<Material>> materials;
};

