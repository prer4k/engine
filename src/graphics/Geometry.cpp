#include "graphics/Geometry.h"

#include <cmath>

namespace
{
    constexpr float PI = 3.14159265358979323846f;

    inline void pushVertex(std::vector<float>& v,
                           float px, float py, float pz,
                           float nx, float ny, float nz,
                           float u, float w)
    {
        v.push_back(px); v.push_back(py); v.push_back(pz);
        v.push_back(nx); v.push_back(ny); v.push_back(nz);
        v.push_back(u);  v.push_back(w);
    }
}

GeometryData Geometry::cube()
{
    GeometryData out;
    out.stride = 8;
    out.vertices = {
        // front
        -0.5f,-0.5f, 0.5f, 0,0,1, 0,0,
         0.5f,-0.5f, 0.5f, 0,0,1, 1,0,
         0.5f, 0.5f, 0.5f, 0,0,1, 1,1,
         0.5f, 0.5f, 0.5f, 0,0,1, 1,1,
        -0.5f, 0.5f, 0.5f, 0,0,1, 0,1,
        -0.5f,-0.5f, 0.5f, 0,0,1, 0,0,

        // back
        -0.5f,-0.5f,-0.5f, 0,0,-1, 0,0,
         0.5f,-0.5f,-0.5f, 0,0,-1, 1,0,
         0.5f, 0.5f,-0.5f, 0,0,-1, 1,1,
         0.5f, 0.5f,-0.5f, 0,0,-1, 1,1,
        -0.5f, 0.5f,-0.5f, 0,0,-1, 0,1,
        -0.5f,-0.5f,-0.5f, 0,0,-1, 0,0,

        // left
        -0.5f, 0.5f, 0.5f, -1,0,0, 1,1,
        -0.5f, 0.5f,-0.5f, -1,0,0, 0,1,
        -0.5f,-0.5f,-0.5f, -1,0,0, 0,0,
        -0.5f,-0.5f,-0.5f, -1,0,0, 0,0,
        -0.5f,-0.5f, 0.5f, -1,0,0, 1,0,
        -0.5f, 0.5f, 0.5f, -1,0,0, 1,1,

        // right
         0.5f, 0.5f, 0.5f, 1,0,0, 1,1,
         0.5f, 0.5f,-0.5f, 1,0,0, 0,1,
         0.5f,-0.5f,-0.5f, 1,0,0, 0,0,
         0.5f,-0.5f,-0.5f, 1,0,0, 0,0,
         0.5f,-0.5f, 0.5f, 1,0,0, 1,0,
         0.5f, 0.5f, 0.5f, 1,0,0, 1,1,

        // top
        -0.5f, 0.5f,-0.5f, 0,1,0, 0,1,
         0.5f, 0.5f,-0.5f, 0,1,0, 1,1,
         0.5f, 0.5f, 0.5f, 0,1,0, 1,0,
         0.5f, 0.5f, 0.5f, 0,1,0, 1,0,
        -0.5f, 0.5f, 0.5f, 0,1,0, 0,0,
        -0.5f, 0.5f,-0.5f, 0,1,0, 0,1,

        // bottom
        -0.5f,-0.5f,-0.5f, 0,-1,0, 0,1,
         0.5f,-0.5f,-0.5f, 0,-1,0, 1,1,
         0.5f,-0.5f, 0.5f, 0,-1,0, 1,0,
         0.5f,-0.5f, 0.5f, 0,-1,0, 1,0,
        -0.5f,-0.5f, 0.5f, 0,-1,0, 0,0,
        -0.5f,-0.5f,-0.5f, 0,-1,0, 0,1,
    };
    return out;
}

GeometryData Geometry::uvSphere(int stacks, int slices)
{
    if (stacks < 2) stacks = 2;
    if (slices < 3) slices = 3;

    GeometryData out;
    out.stride = 8;
    auto& v = out.vertices;
    v.reserve(static_cast<size_t>(stacks) * static_cast<size_t>(slices) * 6ULL * 8ULL);

    for (int i = 0; i < stacks; i++)
    {
        const float v0 = static_cast<float>(i) / static_cast<float>(stacks);
        const float v1 = static_cast<float>(i + 1) / static_cast<float>(stacks);

        const float phi0 = v0 * PI;
        const float phi1 = v1 * PI;

        for (int j = 0; j < slices; j++)
        {
            const float u0 = static_cast<float>(j) / static_cast<float>(slices);
            const float u1 = static_cast<float>(j + 1) / static_cast<float>(slices);

            const float theta0 = u0 * 2.0f * PI;
            const float theta1 = u1 * 2.0f * PI;

            // positions on unit sphere (also normals)
            const float x00 = std::sin(phi0) * std::cos(theta0);
            const float y00 = std::cos(phi0);
            const float z00 = std::sin(phi0) * std::sin(theta0);

            const float x10 = std::sin(phi1) * std::cos(theta0);
            const float y10 = std::cos(phi1);
            const float z10 = std::sin(phi1) * std::sin(theta0);

            const float x01 = std::sin(phi0) * std::cos(theta1);
            const float y01 = std::cos(phi0);
            const float z01 = std::sin(phi0) * std::sin(theta1);

            const float x11 = std::sin(phi1) * std::cos(theta1);
            const float y11 = std::cos(phi1);
            const float z11 = std::sin(phi1) * std::sin(theta1);

            // two triangles per quad
            pushVertex(v, x00, y00, z00, x00, y00, z00, u0, v0);
            pushVertex(v, x10, y10, z10, x10, y10, z10, u0, v1);
            pushVertex(v, x11, y11, z11, x11, y11, z11, u1, v1);

            pushVertex(v, x00, y00, z00, x00, y00, z00, u0, v0);
            pushVertex(v, x11, y11, z11, x11, y11, z11, u1, v1);
            pushVertex(v, x01, y01, z01, x01, y01, z01, u1, v0);
        }
    }

    return out;
}

