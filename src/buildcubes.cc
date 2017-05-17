#include "buildcubes.h"

#include <algorithm>

std::vector<castle::Cube>
castle::buildCubesFromMatrix(const std::vector<unsigned> &voxelMatrix, 
                             const glm::vec3 &sizes)
{
  std::vector<unsigned> vxMat = voxelMatrix;
  //achando as quinas
  std::vector<glm::vec3> corners;
  for(size_t y = 0; y < sizes.y; ++y)
  {
    for(size_t x = 0; x < sizes.x; ++x)
    {
      for(size_t z = 0; z < sizes.z; ++z)
      {
      }
    }
  }

  return std::vector<castle::Cube>{};
}
