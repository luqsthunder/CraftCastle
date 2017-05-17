#include "camera.h"

using namespace castle;

Camera::Camera(): Camera({0, 0, 0}, {0, 0, -1}, {0, 1, 0})
{
}

Camera::Camera(const glm::vec3 &target, const glm::vec3 &direction,
               const glm::vec3 &up)
{
  //_view = glm::lookat();
}

void 
Camera::translate(const glm::vec3 &offset)
{

}

void
Camera::rotate(const float &rad, const glm::vec3 &axis)
{
}