#pragma once

#include <vector>
#include <glm/glm.hpp>

namespace castle
{
void
createCylinderMesh(std::vector<float> &verticesOut, const glm::vec3 &pos,
                   float radius, float heigth, float texNumber,
                   uint32_t slicesY = 20);
}