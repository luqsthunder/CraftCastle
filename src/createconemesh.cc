#include "createconemesh.h"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <array>

void
castle::createConeMesh(std::vector<float> &vertices, const glm::vec3 &pos,
                       float texNum, float baseRadius, float heigth, 
                       float coneAngle, float rot, const glm::vec3 &rotVec, 
                       uint32_t slicesY)
{
  std::vector<glm::vec4> verts;

  float increment = 2.f / (float)slicesY;
  float currrad, curheigth = -1;
  currrad = glm::tan(glm::radians(coneAngle)) / -1.f * (1.f - curheigth);
  for(uint32_t y = 0; y < (slicesY - 1); ++y)
  {
    for(float radIt = 0; radIt < 360.f; radIt += 360.f / 20.f)
    {
      verts.insert(verts.end(), 
                   {currrad * glm::sin(glm::radians(radIt)), curheigth, 
                    currrad * glm::cos(glm::radians(radIt)), 1.f});
    }
    curheigth += increment;
    currrad = glm::tan(glm::radians(coneAngle)) / -1.f * (1.f - curheigth);
  }                                //63.43f

  std::array<glm::vec4, 4> vertaux;
  uint32_t vertCont = 0;
  auto matobj = glm::translate(pos) * 
                ((rotVec == glm::vec3{}) ? glm::mat4{} : 
                                           glm::rotate(rot, rotVec)) *
                glm::scale(glm::vec3{baseRadius, heigth, baseRadius});

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