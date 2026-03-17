#pragma once

#include <vector>

struct GeometryData
{
    std::vector<float> vertices;
    int stride = 0;
};

namespace Geometry
{
    GeometryData cube();                    // position(3), normal(3), uv(2)
    GeometryData uvSphere(int stacks = 16,  // position(3), normal(3), uv(2)
                          int slices = 32);
}

