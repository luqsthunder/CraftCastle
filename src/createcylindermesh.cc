#include "createcylindermesh.h"

#include <algorithm>
#include <array>

#include <glm/gtx/transform.hpp>

void
castle::createCylinderMesh(std::vector<float> &vertices, const glm::vec3 &pos, 
                           float texNum, float radius, float heigth, 
                           uint32_t slicesY)
{
  std::vector<glm::vec4> verts;
  float increment = 2.f / (float)slicesY;
  float curheigth = -1;
  

  for(uint32_t y = 0; y < slicesY; ++y, curheigth += increment)
  {
    for(float radIt = 0; radIt < 360.f; radIt += 360.f / 20.f)
    {
      verts.insert(verts.end(),
      {glm::sin(glm::radians(radIt)), curheigth,
       glm::cos(glm::radians(radIt)), 1.f});
    }
  }

  std::array<glm::vec4, 4> vertaux;
  uint32_t vertCont = 0;
  auto matobj = glm::translate(pos) *
                glm::scale(glm::vec3{radius, heigth, radius});
  for(uint32_t y = 0; y < (slicesY - 3); ++y)
  {
    for(uint32_t x = 0; x < 20; ++x)
    {
      vertCont = (x + y * 20);

      if(x == 19)
      {
        vertaux[0] = verts[vertCont + 20];
        vertaux[1] = verts[vertCont];
        vertaux[2] = verts[y * 20];
        vertaux[3] = verts[(y + 1) * 20];
      }
      else
      {
        vertaux[0] = verts[vertCont + 20];
        vertaux[1] = verts[vertCont];
        vertaux[2] = verts[vertCont + 1];
        vertaux[3] = verts[vertCont + 21];
      }

      auto veca = vertaux[0] - vertaux[1];
      auto vecb = vertaux[2] - vertaux[1];

      auto vecc = vertaux[0] - vertaux[1];
      auto vecd = vertaux[3] - vertaux[1];

      glm::vec4 norm1 = (veca * vecb);
      glm::vec4 norm2 = (vecc * vecd);

      std::transform(vertaux.begin(), vertaux.end(), vertaux.begin(),
                     [&](glm::vec4 v) { return (matobj * v); });

      vertices.insert(vertices.end(),
      {
        vertaux[0].x, vertaux[0].y, vertaux[0].z, vertaux[0].w, norm1.x,
        norm1.y, norm1.z, 0.0, 0.0, texNum,

        vertaux[1].x, vertaux[1].y, vertaux[1].z, vertaux[1].w, norm1.x,
        norm1.y, norm1.z, 0.0, 1.0, texNum,

        vertaux[2].x, vertaux[2].y, vertaux[2].z, vertaux[2].w, norm1.x,
        norm1.y, norm1.z, 1.0, 1.0, texNum,

        vertaux[0].x, vertaux[0].y, vertaux[0].z, vertaux[0].w, norm2.x,
        norm2.y, norm2.z, 0.0, 0.0, texNum,

        vertaux[2].x, vertaux[2].y, vertaux[2].z, vertaux[2].w, norm2.x,
        norm2.y, norm2.z, 1.0, 1.0, texNum,

        vertaux[3].x, vertaux[3].y, vertaux[3].z, vertaux[3].w, norm2.x,
        norm2.y, norm2.z, 1.0, 0.0, texNum,
      });
    }
  }
}