#include "ogltexture.h"

#include <glbinding/gl/gl.h>
#include <SFML/Graphics/Image.hpp>

using namespace gl;
using namespace castle;

OGLTexture::OGLTexture(const std::string &path)
{
  glGenTextures(1,&_texture);
  glBindTexture(GL_TEXTURE_2D, _texture);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
                  GL_LINEAR_MIPMAP_NEAREST);

  sf::Image im;
  im.loadFromFile(path);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, im.getSize().x, im.getSize().y, 0,
               GL_RGBA, GL_UNSIGNED_BYTE, im.getPixelsPtr());
  glGenerateMipmap(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, 0);
}

OGLTexture::~OGLTexture()
{
  glDeleteTextures(1, &_texture);
}

void
OGLTexture::bind() const
{
  glBindTexture(GL_TEXTURE_2D, _texture);
}

void
OGLTexture::unbind() const
{
  glBindTexture(GL_TEXTURE_2D, 0);
}