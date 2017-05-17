#pragma once

#include <glm/vec3.hpp>
#include <vector>

namespace castle
{

void
createConeMesh(std::vector<float> &vertices, const glm::vec3 &pos, 
               float texNum, float baseRadius, float heigth, 
               float coneAngle = 25.f, float rot = 0, 
               const glm::vec3 &rotVec = {}, uint32_t slicesY = 20);
}
