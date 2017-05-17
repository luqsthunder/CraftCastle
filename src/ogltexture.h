#pragma once

#include <string>

namespace castle
{
class OGLTexture
{
public:
  //!
  //! \param pathImage path to a file
  OGLTexture(const std::string &pathImg);
  ~OGLTexture();

  void bind() const;
  void unbind() const;

private:
  unsigned _texture;
};
}
