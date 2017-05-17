//! created by l4qsthun3r
//!

#include <vector>
#include <glm/vec3.hpp>

namespace castle
{

//! \brief
//! this function creates a sphere with ySlices numbers of circle slices
//! the function will create ySlices from a normal vector angled by
//! begYAngle to endYAngle, like a integral of volume works.
//!
//! \param vertsOut vertices output array to been added sphere mesh
//! \param pos position where sphere will stand on world
//! \param sizeScale the real size of sphere in meters
//! \param begYAngle begining integration interval, this value cannot be more
//!  90 degrees
//! \param endYAngle ending integration interval, this value cannot be less
//! than -90 degrees
//! \param slicesY number of slices of sphere
void createSphereMesh(std::vector<float> &vertsOut, const glm::vec3 &pos, 
                      float texNum, const float sizeScale, 
                      const float begYAngle, const float endYAngle, 
                      const uint32_t slicesY = 20);

}