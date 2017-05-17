#include <fstream>
#include <iostream>
#include <string>

#include "oglshader.h"

using namespace castle;

std::istream& safeGetline(std::istream& is, std::string& t)
{
  t.clear();

  // The characters in the stream are read one-by-one using a std::streambuf.
  // That is faster than reading them one-by-one using the std::istream.
  // Code that uses streambuf this way must be guarded by a sentry object.
  // The sentry object performs various tasks,
  // such as thread synchronization and updating the stream state.

  std::istream::sentry se(is, true);
  std::streambuf* sb = is.rdbuf();

  for(;;) {
    int c = sb->sbumpc();
    switch (c) {
      case '\n':
        return is;
      case '\r':
        if(sb->sgetc() == '\n')
          sb->sbumpc();
        return is;
      case EOF:
        // Also handle the case when the last line has no line ending
        if(t.empty())
          is.setstate(std::ios::eofbit);
        return is;
      default:
        t += (char)c;
    }
  }
}

std::string
oglLoadShaderSource(const std::string &resourcePath)
{
  std::ifstream fileStream;
  std::string content;

  fileStream.open(resourcePath.c_str(), std::ios::in);

  if(! fileStream.good())
    throw std::invalid_argument("resource Path:" + resourcePath);

  std::string line;

  for(;! fileStream.eof(); content += '\n')
  {
    safeGetline(fileStream, line);

    content += line + '\n';
  }

  fileStream.close();

  return content;
}

OGLShader::~OGLShader()
{
  gl::glDeleteProgram(_program);
}

OGLShader::OGLShader(const std::initializer_list<std::pair<std::string,
                                                           gl::GLenum>> &ilist)
  : OGLShader(std::vector<std::pair<std::string, gl::GLenum>>{ilist.begin(),
                                                              ilist.end()})
{
}

OGLShader::OGLShader(const std::vector<std::pair<std::string,
                                                 gl::GLenum>> &path)
{
  using namespace gl;

  GLboolean success;
  GLchar infoLog[512];

  std::vector<GLuint> shaders;

  for(const auto &i : path)
  {
    GLuint shader = glCreateShader(i.second);
    shaders.push_back(shader);

    auto src = oglLoadShaderSource(i.first);
    const GLchar* cfragSrc = src.c_str();

    glShaderSource(shader, 1, &cfragSrc, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE)
    {
      glGetShaderInfoLog(shader, 512, NULL, infoLog);
      std::cout << cfragSrc << std::endl;
      std::cout << "ERROR::SHADER::COMPILATION_FAILED " << i.second << infoLog
                << std::endl;

      for(const auto &ii : shaders)
        glDeleteShader(ii);

      return;
    }

  }

  _program = glCreateProgram();
  for(const auto &i : shaders)
    glAttachShader(_program, i);

  glLinkProgram(_program);

  glGetProgramiv(_program, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(_program, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog
              << std::endl;
  }

  for(const auto &i : shaders)
    glDeleteShader(i);
}

gl::GLuint
OGLShader::program() const
{
  return _program;
}