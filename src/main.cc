#include <iostream>
#include <algorithm>

#include <SDL.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#include <globjects/base/File.h>

#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>

#ifdef main
#undef main
#endif

#ifndef _MSC_VER
#pragma warning(pop)
#endif

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "createspheremesh.h"
#include "createconemesh.h"
#include "createcylindermesh.h"
#include "oglshader.h"
#include "floor.h"
#include "subwall.h"
#include "completewall.h"
#include "upperlevel.h"
#include "upperfloor.h"
#include "ogltexture.h"
#include "door.h"

using namespace gl;

void 
addTree(std::vector<float> &verts, const glm::vec3 &pos)
{
  castle::createCylinderMesh(verts, pos, 1, .5f, 1.2f);
  castle::createSphereMesh(verts, pos + glm::vec3{0, 1, 0}, 0, 1.25f, -90.f, 90.f);

  castle::createConeMesh(verts, 
                         pos + glm::vec3{0, -1.2f, 
                                         .5f}, 1, 
                         .5f, .5f, 25.f, 90.f, {1 , 0, 0});
  
  castle::createConeMesh(verts,
                         pos + glm::vec3{0, -1.2f,
                         -.5f}, 1,
                         .5f, .5f, 25.f, -90.f, {1 , 0, 0});
  
  castle::createConeMesh(verts,
                         pos + glm::vec3{-.5f, -1.2f,
                         .0f}, 1,
                         .5f, .5f, 25.f, 90.f, {0 , 0, 1});

  castle::createConeMesh(verts,
                         pos + glm::vec3{.5f, -1.2f,
                         .0f}, 1,
                         .5f, .5f, 25.f, -90.f, {0 , 0, 1});
}

void
addCubeMatrix(const float yL, const glm::vec2 &pos, 
              const  int * color, const unsigned w,
              const unsigned h, std::vector<float> &verts)
{
  glm::vec4 res;
  const glm::vec3 corner{pos.x - w > 1 ? ((float)w / 2) : 0, yL, 
                         pos.y - h > 1 ? ((float)h / 2) : 0};

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
    6, 4, 5, 5, 7, 6, //rigth

    //2, 1, 4, 4, 2, 6, //frente
    2, 0, 4, 4, 6, 2,
    3, 1, 5, 5, 7, 3  //costas
  };

  std::vector<glm::vec3> cubeVerts, cubeNormals;
  std::vector<glm::vec2> cubeTex;
  std::array<glm::vec3, 6> vertaux;
  uint32_t vertCont = 0;

  for(uint32_t y = 0; y < 6; ++y)
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
    cubeTex.insert(cubeTex.end(), {{0.0, 0.0} , {0.0, 1.0}, {1.0, 1.0},
                                   {1.0, 1.0} ,{1.0, 0.0},{0.0, 0.0}});
  }

  for(size_t z = 0; z < h; ++z)
  {
    for(size_t x = 0; x < w; ++x)
    {
      if(color[x + z * w] == 0)
      {
        continue;
      }

      for(size_t i = 0; i < cubeVerts.size(); ++i)
      {
        auto tv = corner + glm::vec3{(float)x, 0, (float)z};
        res = glm::translate(tv) * glm::vec4{cubeVerts[i], 1.0};

        verts.insert(verts.end(), {res.x, res.y, res.z, res.w,cubeNormals[i].x,
                     cubeNormals[i].y, cubeNormals[i].z, cubeTex[i].x, 
                     cubeTex[i].y, ((float)color[x + z * w] + 1.f)});
      }
    }
  }

}

int
main(int, char **)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cerr << "unable to init SDL2" << std::endl;
    return -1;
  }
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  SDL_Window* window = SDL_CreateWindow("Voxel World",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, 1366, 768,
                                        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  SDL_GLContext context = SDL_GL_CreateContext(window);

  glbinding::Binding::initialize();

  int attrMajor, attrMinor, attrStencil, attrDepth;
  SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &attrMajor);
  SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &attrMinor);
  SDL_GL_GetAttribute(SDL_GL_DEPTH_SIZE, &attrDepth);
  SDL_GL_GetAttribute(SDL_GL_STENCIL_SIZE, &attrStencil);
  
  if(attrMajor != 3 || attrMinor != 3)
  {
    fprintf(stderr, "unable to set context OpenGL Version: %d.%d || \n"
            "DepthBuffer:%d StencilBuffer:%d\n",
            attrMajor, attrMinor, attrDepth, attrStencil);
    return -1;
  }

  std::vector<float> finalVerts;

  addCubeMatrix(0, {38, 52}, castle::floor, 76, 104, finalVerts);

  addCubeMatrix(1, {38, 52}, castle::subwall, 76, 104, finalVerts );
  addCubeMatrix(2, {38, 52}, castle::subwall, 76, 104, finalVerts );
  addCubeMatrix(3, {38, 52}, castle::subwall, 76, 104, finalVerts );
  addCubeMatrix(4, {38, 52}, castle::subwall, 76, 104, finalVerts );

  addCubeMatrix(4, {38, 52}, castle::upperlevel, 76, 104, finalVerts );

  addCubeMatrix(1, {38, 52}, castle::completewall, 76, 104, finalVerts );
  addCubeMatrix(2, {38, 52}, castle::completewall, 76, 104, finalVerts );
  addCubeMatrix(3, {38, 52}, castle::completewall, 76, 104, finalVerts );
  addCubeMatrix(4, {38, 52}, castle::completewall, 76, 104, finalVerts );
  addCubeMatrix(5, {38, 52}, castle::completewall, 76, 104, finalVerts );
  addCubeMatrix(6, {38, 52}, castle::completewall, 76, 104, finalVerts );


  addCubeMatrix(6, {38, 52}, castle::upperfloor, 76, 104, finalVerts);

  addTree(finalVerts, {22.622793, 2.5, 63.199265});
  addTree(finalVerts,{37.278645, 2.5, 63.199265});
  //pinkBrush (1.5) (grupo.quantidade) ROSA LADO ESQUERDO 5
  //pinkBrush (1.5) (grupo.quantidade) ROSA LADO ESQUERDO 5
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 61.121136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 61.621136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 60.121136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 59.621136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 59.121136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 58.621136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 58.121136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 57.621136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 57.121136}, 13, 0.25, -90, 90);
  //pinkBrush (2.3) ROSA LADO ESQUERDO 3 CIMA
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 71.121136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 70.621136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 70.121136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 69.621136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 69.121136}, 13, 0.25, -90, 90);
  //pinkBrush (3.3) ROSA LADO ESQUERDO 3 BAIXO
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 66.121136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 65.621136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 65.121136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 64.621136}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {25.710840, 1.080124, 64.121136}, 13, 0.25, -90, 90);
  //pinkBrush (4.7) ROSA LADO DIREITO 7
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 58.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 59.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 60.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 61.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 62.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 63.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 64.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 65.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 66.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 67.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 68.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 69.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 70.659111}, 13, 0.25, -90, 90);
  //pinkBrush (5.5) ROSA LADO DIREITO 5 ESQUERDOS
  castle::createSphereMesh(finalVerts, {34.419609, 1.080124, 74.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {34.419609, 1.080124, 74.059111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {34.419609, 1.080124, 73.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {34.419609, 1.080124, 73.059111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {34.419609, 1.080124, 72.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {34.419609, 1.080124, 72.059111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {34.419609, 1.080124, 71.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {34.419609, 1.080124, 71.059111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {34.419609, 1.080124, 70.659111}, 13, 0.25, -90, 90);
  //pinkBrush (6.5) ROSA LADO DIREITO 5 DIREITOS
  castle::createSphereMesh(finalVerts, {41.419609, 1.080124, 74.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {41.419609, 1.080124, 74.059111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {41.419609, 1.080124, 73.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {41.419609, 1.080124, 73.059111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {41.419609, 1.080124, 72.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {41.419609, 1.080124, 72.059111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {41.419609, 1.080124, 71.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {41.419609, 1.080124, 71.059111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {41.419609, 1.080124, 70.659111}, 13, 0.25, -90, 90);
  //pinkbrush (7.2) ROSA LADO DIREITO 2
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 74.659111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 74.059111}, 13, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.419609, 1.080124, 73.659111}, 13, 0.25, -90, 90);

  //orangeBrush (1.8) LARANJA LADO ESQUERDO
  castle::createSphereMesh(finalVerts, {23.083124, 1.080124, 75.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {21.083124, 1.080124, 75.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {23.083124, 1.080124, 73.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {21.083124, 1.080124, 73.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {23.083124, 1.080124, 70.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {21.083124, 1.080124, 70.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {23.083124, 1.080124, 67.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {21.083124, 1.080124, 67.088188}, 12, 0.25, -912, 90);

  //orangeBrush (2.4) LARANJA LADO DIREITO
  castle::createSphereMesh(finalVerts, {36.419609, 1.080124, 70.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {36.419609, 1.080124, 73.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {39.419609, 1.080124, 70.088188}, 12, 0.25, -912, 90);
  castle::createSphereMesh(finalVerts, {39.419609, 1.080124, 73.088188}, 12, 0.25, -912, 90);

  //Intervalo porta
  //de
  castle::createSphereMesh(finalVerts, {29.144434, 1.668955, 55.511642}, 0, 0.25, -90, 90);
  //ate
  castle::createSphereMesh(finalVerts, {30.944407, 1.668955, 55.502167}, 0, 0.25, -90, 90);



  //Posiçoes Caldeiroes Hall Principal
  castle::createSphereMesh(finalVerts, {27.722569, 1.135493, 32.801510}, 11, 1.25f, -90, 80.f);
  castle::createSphereMesh(finalVerts, {32.322334, 1.135493, 32.760098}, 11, 1.25f, -90, 80.f);
  castle::createSphereMesh(finalVerts, {35.004704, 1.135493, 36.335636}, 11, 1.25f, -90, 80.f);
  castle::createSphereMesh(finalVerts, {25.055120, 1.135493, 36.425213}, 11, 1.25f, -90, 80.f);

  // Pilastras
  castle::createCylinderMesh(finalVerts, {24.795633, 1.135493, 40.927158}, 1, .5f, 3.f);
  castle::createCylinderMesh(finalVerts, {21.595804, 1.135493, 40.955967}, 1, .5f, 3.f);
  castle::createCylinderMesh(finalVerts, {19.645908, 1.135493, 40.973522}, 1, .5f, 3.f);
  castle::createCylinderMesh(finalVerts, {41.595100, 1.135493, 40.831280}, 1, .5f, 3.f);
  castle::createCylinderMesh(finalVerts, {38.545147, 1.135493, 40.831280}, 1, .5f, 3.f);
  castle::createCylinderMesh(finalVerts, {35.445194, 1.135493, 40.831280}, 1, .5f, 3.f);

  //cilindro com fogo central

  castle::createSphereMesh(finalVerts, {29.142780, 1.135493, 43.930962}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {30.892754, 1.135493, 43.935902}, 0, 0.25, -90, 90);

  //Bases menores
  castle::createSphereMesh(finalVerts, {32.571838, 1.135493, 51.336071}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.578049, 1.135493, 49.137447}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.582989, 1.135493, 47.388542}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {32.587364, 1.135493, 45.839512}, 0, 0.25, -90, 90);

  castle::createSphereMesh(finalVerts, {27.637440, 1.135493, 51.336071}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {27.637440, 1.135493, 49.137447}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {27.637440, 1.135493, 47.388542}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {27.637440, 1.135493, 45.839512}, 0, 0.25, -90, 90);

  //pontos da escada central
  castle::createSphereMesh(finalVerts, {29.137383, 1.050000, 30.380959}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {30.837314, 1.050000, 30.380959}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {29.137383, 1.050000, 33.380802}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {30.837314, 1.050000, 33.380802}, 0, 0.25, -90, 90);
  //ponta da escada central
  castle::createSphereMesh(finalVerts, {30.151457, 1.050000, 31.871279}, 0, 0.25, -90, 90);

  //pontas da escada da esqueda
  castle::createSphereMesh(finalVerts, {18.689657, 1.050000, 35.979023}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {17.189726, 1.050000, 35.979023}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {18.689657, 1.050000, 38.380802}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {17.189726, 1.050000, 38.380802}, 0, 0.25, -90, 90);
  //ponto central da escada esquerda
  castle::createSphereMesh(finalVerts, {17.915050, 1.050000, 36.449825}, 0, 0.25, -90, 90);

  //pontos da escada da direita
  castle::createSphereMesh(finalVerts, {39.193424, 1.050000, 36.285858}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {40.693356, 1.050000, 36.285858}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {39.193424, 1.050000, 39.571725}, 0, 0.25, -90, 90);
  castle::createSphereMesh(finalVerts, {40.693356, 1.050000, 39.571725}, 0, 0.25, -90, 90);
  //ponto central da escada direita
  castle::createSphereMesh(finalVerts, {39.813301, 1.050000, 36.730663}, 0, 0.25, -90, 90);
  
  glm::mat4 projection = glm::perspective(glm::radians(45.f), 1366.f / 768.f,
                                          0.01f, 32.f * 100.f);
  glm::mat4 viewCamera, obj, viewproj;

  // init GL
  GLuint mapVao, mapVbo;

  glGenVertexArrays(1, &mapVao);
  glGenBuffers(1, &mapVbo);

  glBindVertexArray(mapVao);
  glBindBuffer(GL_ARRAY_BUFFER, mapVbo);

  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * finalVerts.size(),
               finalVerts.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)(4 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)(7 * sizeof(float)));
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)(9 * sizeof(float)));
  glEnableVertexAttribArray(3);

  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  std::vector<float> door1Verts, door2Verts;
  int color[2] = {9, 8};
  addCubeMatrix(0, {0, 0}, color, 1, 1, door1Verts);
  addCubeMatrix(0, {0, 0}, color, 1, 1, door2Verts);

  glm::mat4 door1Ojb, door2Ojb;
  float door1Degrees = 0;
  bool door1Open = false, door1Opening = false;

  GLuint door1Vao, door1Vbo, door2Vao, door2Vbo;

  glGenVertexArrays(1, &door1Vao);
  glGenBuffers(1, &door1Vbo);

  glBindVertexArray(door1Vao);
  glBindBuffer(GL_ARRAY_BUFFER, door1Vbo);

  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * door1Verts.size(),
               door1Verts.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)(4 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)(7 * sizeof(float)));
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)(9 * sizeof(float)));
  glEnableVertexAttribArray(3);
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);


  glGenVertexArrays(1, &door2Vao);
  glGenBuffers(1, &door2Vbo);
  
  glBindVertexArray(door2Vao);
  glBindBuffer(GL_ARRAY_BUFFER, door2Vbo);

  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * door2Verts.size(),
               door2Verts.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)(4 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)(7 * sizeof(float)));
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE,
                        sizeof(float) * 10, (GLvoid*)(9 * sizeof(float)));
  glEnableVertexAttribArray(3);

  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  castle::OGLTexture texLeaves{"leaves.jpg"};
  castle::OGLTexture texTrunks{"treetrunks.jpg"};
  castle::OGLTexture texWalls{"walls.jpg"};

  castle::OGLTexture texGrass{"grass.jpg"};
  castle::OGLTexture texFlag{"flag.jpg"};
  castle::OGLTexture texBlueInt{"blueinternalfloor.jpg"};
  
  castle::OGLTexture texRedCap{"redcarpet.jpg"};
  castle::OGLTexture texGreenFloor{"greenfloor.jpg"};
  castle::OGLTexture texExternalWall{"externalwall.jpg"};
  castle::OGLTexture texCeilling{"ceiling.jpg"};
  castle::OGLTexture texFrontDoor{"frontDoor.png"};
  castle::OGLTexture texIron{"iron.png"};
  castle::OGLTexture texOrangebrush{"orangebrush.jpg"};
  castle::OGLTexture texpinkbrush{"pinkbrush.png"};

  castle::OGLShader shader{{"shaders/simpleshader.vert.glsl", GL_VERTEX_SHADER}
                          ,{"shaders/simpleshader.frag.glsl", GL_FRAGMENT_SHADER}};

  bool exitGame = false;
  SDL_Event event;

  auto unfLocProjView = glGetUniformLocation(shader.program(), "projviewobj");
  auto unfLocModel = glGetUniformLocation(shader.program(), "modelmat");
  auto lightPosLoc = glGetUniformLocation(shader.program(), "lightPos");
  auto viewPosLoc = glGetUniformLocation(shader.program(), "viewPos");

  auto tex2D0Loc = glGetUniformLocation(shader.program(), "tex2D0");
  auto tex2D1Loc = glGetUniformLocation(shader.program(), "tex2D1");
  auto tex2D2Loc = glGetUniformLocation(shader.program(), "tex2D2");
  auto tex2D3Loc = glGetUniformLocation(shader.program(), "tex2D3");
  auto tex2D4Loc = glGetUniformLocation(shader.program(), "tex2D4");
  auto tex2D5Loc = glGetUniformLocation(shader.program(), "tex2D5");
  auto tex2D6Loc = glGetUniformLocation(shader.program(), "tex2D6");
  auto tex2D7Loc = glGetUniformLocation(shader.program(), "tex2D7");
  auto tex2D8Loc = glGetUniformLocation(shader.program(), "tex2D8");
  auto tex2D9Loc = glGetUniformLocation(shader.program(), "tex2D9");
  auto tex2D10Loc = glGetUniformLocation(shader.program(), "tex2D10");
  auto tex2D11Loc = glGetUniformLocation(shader.program(), "tex2D11");
  auto tex2D12Loc = glGetUniformLocation(shader.program(), "tex2D12");
  auto tex2D13Loc = glGetUniformLocation(shader.program(), "tex2D13");

  std::vector<std::pair<bool, glm::vec3>> keyPress;
  keyPress.resize(4);

  keyPress[0] = std::make_pair(false, glm::vec3(0.0f, 0.0f, -0.1f));
  keyPress[1] = std::make_pair(false, glm::vec3(-0.1f, 0.0f, 0.0f));
  keyPress[2] = std::make_pair(false, glm::vec3(0.0f, 0.0f, 0.1f));
  keyPress[3] = std::make_pair(false, glm::vec3(0.1f, 0.0f, 0.0f));

  glEnable(GL_DEPTH_TEST);

  glm::vec3 cameraPos = glm::vec3(31.924185, 2.267336, 100.613564);//glm::vec3(31.848383, 5.424970, 105.850555); //vec3(0.0f, 0.0f, 3.0f);
  glm::vec3 cameraFront = glm::vec3(-0.009420, -0.014922, -0.999844);//vec3(0.0f, 0.0f, -1.0f);
  glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
  //vec3(31.848383, 5.424970, 105.850555) 
  //vec3(-0.009420, -0.014922, -0.999844) 
  //vec3(0.000000, 1.000000, 0.000000) 
  
  glm::vec2 mouseOffset(0.0f, 0.0f);
  glm::vec2 mouseFirstPos;

  bool firstMousePress = false;

  GLfloat pitch, yaw;
  pitch = 0.0f, yaw = -90.0f;

  float fpsCont = 0;

  door1Ojb = glm::translate(glm::vec3{33
                            , 1, 82}) *
             glm::scale(glm::vec3{-6, 6, 1}) * 
             glm::rotate(glm::radians(0.f), glm::vec3{0, 1, 0});

 /* door2Ojb = glm::translate(glm::vec3{28, 1, 82}) *
             glm::scale(glm::vec3{3, 6, 1}) *
             glm::rotate(glm::radians(0.f), glm::vec3{0, 1, 0});*/

  bool rotating = false;

  //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
  while(! exitGame)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        exitGame = true;
      }
      else if(event.type == SDL_KEYDOWN)
      {
        if(event.key.keysym.sym == SDLK_w)
          keyPress[0].first = true;
        if(event.key.keysym.sym == SDLK_d)
          keyPress[1].first = true;
        if(event.key.keysym.sym == SDLK_s)
          keyPress[2].first = true;
        if(event.key.keysym.sym == SDLK_a)
          keyPress[3].first = true;
      }
      else if(event.type == SDL_KEYUP)
      {
        if(event.key.keysym.sym == SDLK_w)
          keyPress[0].first = false;
        if(event.key.keysym.sym == SDLK_d)
          keyPress[1].first = false;
        if(event.key.keysym.sym == SDLK_s)
          keyPress[2].first = false;
        if(event.key.keysym.sym == SDLK_a)
          keyPress[3].first = false;

        if(event.key.keysym.sym == SDLK_SPACE)
          std::cout << glm::to_string(cameraPos) << " " << glm::to_string(cameraFront) << " " << glm::to_string(cameraUp)<< std::endl;
        if(event.key.keysym.sym == SDLK_1)
        {
          if(!rotating)
          {
            rotating = true;
            door1Opening = true;
          }
        }
      }
      else if(event.type == SDL_MOUSEBUTTONDOWN)
      {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
          firstMousePress = true;
          mouseFirstPos = glm::vec2{event.motion.x, event.motion.y};
        }
      }
      else if((event.type == SDL_MOUSEMOTION) && (firstMousePress))
      {
        glm::vec2 deltaPos;
        glm::vec2 mousePos{event.motion.x, event.motion.y};

        deltaPos.x = static_cast<float>(mousePos.x - mouseFirstPos.x);
        deltaPos.y = static_cast<float>(mousePos.y - mouseFirstPos.y);

        if(deltaPos.x != 0 || deltaPos.y != 0)
        {
          deltaPos = 0.005f * deltaPos;

          yaw += deltaPos.x;
          pitch += deltaPos.y;

          glm::vec3 front;
          front.x = std::cos(glm::radians(yaw)) * std::cos(glm::radians(pitch));
          front.y = std::sin(glm::radians(pitch));
          front.z = std::sin(glm::radians(yaw)) * std::cos(glm::radians(pitch));
          cameraFront = glm::normalize(front);

        }
      }
      else if((event.type == SDL_MOUSEBUTTONUP) &&
              (event.button.button == SDL_BUTTON_LEFT))
        firstMousePress = false;
    }

    if(door1Opening)
    {
      if(((int)fpsCont) % 2 == 0 && rotating)
      {
        door1Degrees += (door1Open ? 1 : -1);
        door1Ojb = glm::translate(glm::vec3{27, 1, 82}) *
                   glm::scale(glm::vec3{6, 6, 1}) *
                   glm::rotate(glm::radians(door1Degrees),
                               glm::vec3{0, 1, 0});

        /*door2Ojb = glm::translate(glm::vec3{28, 1, 82}) *
          glm::scale(glm::vec3{3, 6, 1}) *
          glm::rotate(glm::radians(door1Degrees),
                      glm::vec3{0, 1, 0});*/
      }
      if(rotating && (door1Degrees == 90.f || (door1Degrees == 0 && !door1Open)))
      {
        rotating = false;
        door1Open = !door1Open;
      }

    }

    glm::vec3 moveOffset;
    if(keyPress[0].first)
      moveOffset += (0.5f * cameraFront);
    else if(keyPress[2].first)
      moveOffset -= (0.5f * cameraFront);

    if(keyPress[1].first)
      moveOffset += 0.5f * glm::normalize(glm::cross(cameraFront, cameraUp));
    else if(keyPress[3].first)
      moveOffset += 0.5f * glm::normalize(glm::cross(cameraUp, cameraFront));

    cameraPos += moveOffset;

    viewCamera = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    //END HERE
    viewproj = glm::mat4();

    viewproj = projection * viewCamera * obj;

    glClearColor(0.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shader.program());

      //TEXTURAS
    glActiveTexture(GL_TEXTURE0);
    texLeaves.bind();
    glUniform1i(tex2D0Loc, 0);

    glActiveTexture(GL_TEXTURE1);
    texTrunks.bind();
    glUniform1i(tex2D1Loc, 1);

    glActiveTexture(GL_TEXTURE3);
    texWalls.bind();
    glUniform1i(tex2D3Loc, 3);

    //falta definir na matriz os pontos onde for grama, brush laranja e rosa
    glActiveTexture(GL_TEXTURE4);
    texGrass.bind();
    glUniform1i(tex2D4Loc, 4);

    glActiveTexture(GL_TEXTURE5);
    texExternalWall.bind();
    glUniform1i(tex2D5Loc, 5);

    glActiveTexture(GL_TEXTURE6);
    texGreenFloor.bind();
    glUniform1i(tex2D6Loc, 6);

    glActiveTexture(GL_TEXTURE7);
    texRedCap.bind();
    glUniform1i(tex2D7Loc, 7);

    glActiveTexture(GL_TEXTURE8);
    texBlueInt.bind();
    glUniform1i(tex2D8Loc, 8);

    glActiveTexture(GL_TEXTURE9);
    texCeilling.bind();
    glUniform1i(tex2D9Loc, 9);

    glActiveTexture(GL_TEXTURE10);
    texFrontDoor.bind();
    glUniform1i(tex2D10Loc, 10);

    glActiveTexture(GL_TEXTURE11);
    texIron.bind();
    glUniform1i(tex2D11Loc, 11);

    glActiveTexture(GL_TEXTURE12);
    texOrangebrush.bind();
    glUniform1i(tex2D12Loc, 12);

    glActiveTexture(GL_TEXTURE13);
    texpinkbrush.bind();
    glUniform1i(tex2D12Loc, 13);

    glUniformMatrix4fv(unfLocProjView, 1, GL_FALSE, glm::value_ptr(viewproj));
    glUniformMatrix4fv(unfLocModel, 1, GL_FALSE, glm::value_ptr(obj));
    glUniform3f(lightPosLoc, 105, 5, 31);
    glUniform3f(viewPosLoc, cameraPos.x, cameraPos.y, cameraPos.z);

    glBindVertexArray(mapVao);
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)(finalVerts.size() / 10));
    glBindVertexArray(0);

    glUniformMatrix4fv(unfLocProjView, 1, GL_FALSE, glm::value_ptr(projection * viewCamera * door1Ojb));

    glBindVertexArray(door1Vao);
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)(door1Verts.size() / 10));
    glBindVertexArray(0);

    glUniformMatrix4fv(unfLocProjView, 1, GL_FALSE, glm::value_ptr(projection * viewCamera * door2Ojb));

    /*glBindVertexArray(door2Vao);
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)(door1Verts.size() / 10));
    glBindVertexArray(0);*/

    glUseProgram(0);

    SDL_GL_SwapWindow(window);
    fpsCont = (fpsCont == 60 ? 0 : fpsCont + 1);
  }

  glDeleteVertexArrays(1, &mapVao);
  glDeleteBuffers(1, &mapVbo);

  glDeleteVertexArrays(1, &door1Vao);
  glDeleteBuffers(1, &door1Vbo);

  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);

  return 0;
}
