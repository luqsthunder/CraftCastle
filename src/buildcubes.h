#pragma once

#include <vector>
#include <glm/glm.hpp>


namespace castle
{

struct Cube
{
  glm::vec3 center;
  glm::vec3 sizes;
};

struct Rect
{
  glm::vec3 point;
  glm::vec3 vec;
};

std::vector<Cube>
buildCubesFromMatrix(const std::vector<unsigned> &voxelMatrix, 
                     const glm::vec3 &sizes);

}