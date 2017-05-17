#include "door.h"

#include <array>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

void
castle::createDoor(std::vector<float> &a, const glm::vec3 &pos, float texNum,
                   float width, float heigth, float zsize)
{
  std::vector<glm::vec3> cubeaux
  {
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, 1.0}, //1
    {0.0, 1.0, 0.0}, //2
    {0.0, 1.0, 1.0}, //3
    {1.0, 0.0, 0.0}, //4
    {1.0, 0.0, 1.0}, //5
    {1.0, 1.0, 0.0}, //6
    {1.0, 1.0, 1.0}  //7
  };

  std::vector<unsigned> cubeFaces
  {
    1, 0, 4, 4, 5, 1, //baixo
    3, 2, 6, 6, 7, 3, //cima

    2, 0, 1, 1, 3 ,2, //left
    6, 4, 5, 5, 6, 7, //rigth

    2, 1, 4, 4, 2, 6, //frente
    3, 1, 5, 5, 7, 3  //costas
  };

  std::vector<glm::vec3> cubeVerts;
  std::vector<glm::vec3> cubeNormals;
  std::vector<glm::vec2> cubeTex;
  std::array<glm::vec3, 6> vertaux;
  float vertCont = 0;

  for(float y = 0; y < 6; ++y)
  {
    vertaux[0] = cubeaux[cubeFaces[(y * 6)]];
    vertaux[1] = cubeaux[cubeFaces[(y * 6) + 1]];
    vertaux[2] = cubeaux[cubeFaces[(y * 6) + 2]];
    vertaux[3] = cubeaux[cubeFaces[(y * 6) + 3]];
    vertaux[4] = cubeaux[cubeFaces[(y * 6) + 4]];
    vertaux[5] = cubeaux[cubeFaces[(y * 6) + 5]];

    auto veca = vertaux[0] - vertaux[1];
    auto vecb = vertaux[2] - vertaux[1];

    auto vecc = vertaux[3] - vertaux[4];
    auto vecd = vertaux[5] - vertaux[4];

    glm::vec3 norm1 = (veca * vecb);
    glm::vec3 norm2 = (vecc * vecd);

    cubeVerts.insert(cubeVerts.end(), vertaux.begin(), vertaux.end());
    cubeNormals.insert(cubeNormals.end(), {norm1, norm1, norm1,
                       norm2, norm2, norm2});
    cubeTex.insert(cubeTex.end(), {{0.0, 0.0} ,{0.0, 1.0},{1.0, 1.0},
                                   {1.0, 1.0} ,{1.0, 0.0},{0.0, 0.0}});
  }

  auto tmat = glm::translate(pos);// * glm::scale(glm::vec3{width, heigth, zsize});
  glm::vec4 res;
  for(size_t i = 0; i < cubeVerts.size(); ++i)
  {
    res = tmat * glm::vec4{cubeVerts[i], 1.f};
    a.insert(a.end(), {res.z, res.y, res.z, res.w, cubeNormals[i].x, 
                       cubeNormals[i].y, cubeNormals[i].z, cubeTex[i].x,
                       cubeTex[i].y, texNum});
  }
}