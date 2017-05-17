#pragma once

#include <glm/glm.hpp>

namespace castle
{

class Camera
{
public:
  Camera();
  Camera(const glm::vec3 &target, const glm::vec3 &pos,
         const glm::vec3 &up);

  void translate(const glm::vec3 &offset);
  void rotate(const float &rad, const glm::vec3 &axis);

  float const* viewMatrix();

protected:
  glm::mat4 _view;
};

}
