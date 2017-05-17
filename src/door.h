#pragma once

#include <vector>
#include <glm/vec3.hpp>

namespace castle
{
void
createDoor(std::vector<float> &a, const glm::vec3 &pos, float texNum, 
           float width, float heigth, float zsize);
}
