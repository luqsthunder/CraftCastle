#pragma once

#include <vector>
#include <map>
#include <glbinding/gl/gl.h>

namespace castle
{

class OGLShader
{
public:
  OGLShader(const std::vector<std::pair<std::string, gl::GLenum>> &path);
  OGLShader(const std::initializer_list<std::pair<std::string, 
                                                  gl::GLenum>> &ilist);
  ~OGLShader();

  gl::GLuint program() const;

protected:
  gl::GLuint _program;
};

}