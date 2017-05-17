#include "createspheremesh.h"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <numeric>
#include <array>

void
castle::createSphereMesh(std::vector<float> &vertsOut, const glm::vec3 &pos, 
                         float texNum, const float sizeScale,
                         const float begYAngle, const float endYAngle,
                         const uint32_t slicesY)
{
  std::vector<glm::vec4> vertices;

  bool bottonNoRadius, topNoRadius;
  bottonNoRadius = (begYAngle == -90);
  topNoRadius = (endYAngle == 90);
  float currRCir = 0;
  float currHeigth = 0;
  float increment = ((endYAngle - begYAngle) / (float)slicesY) - (bottonNoRadius ? 1 : 0);
  for(float angleIt = bottonNoRadius ? begYAngle + increment :begYAngle;
      angleIt <= (topNoRadius ? (endYAngle - increment) : endYAngle);
      angleIt += increment)
  {
    //make a circle
    currRCir = glm::cos(glm::radians(angleIt));
    currHeigth = glm::sin(glm::radians(angleIt));

    for(float cAngleIt  = 0; cAngleIt < 360; cAngleIt += 360.f/20.f)
      vertices.insert(vertices.end(),
                      {currRCir * glm::cos(glm::radians(cAngleIt)), currHeigth,
                       currRCir * glm::sin(glm::radians(cAngleIt)), 1.f});
  }

  if(bottonNoRadius)
  {
  }
  if(topNoRadius)
  {
  }

  std::array<glm::vec4, 4> vertaux;

  uint32_t vertCont = 0;
  auto matobj = glm::translate(pos) * 
                glm::scale(glm::vec3{sizeScale, sizeScale, sizeScale});
  for(uint32_t y = 0; y < (slicesY-1); ++y)
  {
    for(uint32_t x = 0; x < 20; ++x)
    {
      vertCont = (x + y * 20);

      if(x == 19)
      {
        vertaux[0] = vertices[vertCont + 20];
        vertaux[1] = vertices[vertCont];
        vertaux[2] = vertices[y * 20];
        vertaux[3] = vertices[(y + 1) * 20];
      }
      else
      {
        vertaux[0] = vertices[vertCont + 20];
        vertaux[1] = vertices[vertCont];
        vertaux[2] = vertices[vertCont + 1];
        vertaux[3] = vertices[vertCont + 21];
      }

      auto veca = vertaux[0] - vertaux[1];
      auto vecb = vertaux[2] - vertaux[1];
      
      auto vecc = vertaux[0] - vertaux[1];
      auto vecd = vertaux[3] - vertaux[1];

      glm::vec4 norm1 = (veca * vecb);
      glm::vec4 norm2 = (vecc * vecd);

      std::transform(vertaux.begin(), vertaux.end(), vertaux.begin(),
                     [&](glm::vec4 v) { return (matobj * v); });

      vertsOut.insert(vertsOut.end(), 
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