#pragma once

#include <array>
#include <glm/glm.hpp>

namespace castle
{

constexpr int floor[76*104] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,8,8,8,8,8,2,2,2,2,2,2,2,2,2,2,2,0,2,8,8,2,0,2,2,2,2,2,2,2,2,2,2,2,2,8,8,2,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,8,8,8,8,8,2,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,6,6,6,6,6,6,6,6,6,2,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,8,8,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,8,8,6,6,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,8,8,6,6,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,6,6,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,2,8,6,6,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,6,2,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,2,2,2,2,2,6,6,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2,2,2,2,2,0,2,2,2,6,6,2,2,2,2,2,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,2,8,8,2,6,6,6,6,2,8,2,2,2,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,2,2,0,0,2,6,6,2,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,2,8,8,2,2,6,6,2,2,8,2,2,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,2,0,0,2,6,6,2,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,2,8,8,8,2,6,6,2,8,8,2,2,8,8,8,2,2,2,2,2,2,2,2,8,8,2,2,2,2,2,2,2,2,8,8,8,2,0,0,2,6,6,2,8,8,8,8,8,8,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,2,8,8,8,2,6,6,2,8,8,2,2,8,8,8,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,8,8,8,2,2,0,2,6,6,2,8,8,8,8,8,8,8,8,8,8,8,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,2,8,8,8,2,6,6,2,8,8,2,8,8,8,8,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,8,8,8,8,2,0,2,6,6,2,2,2,8,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,2,8,8,8,2,6,6,2,8,8,8,8,8,8,8,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,8,8,8,8,2,0,2,6,6,8,8,2,8,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,2,8,8,8,2,6,6,2,8,8,8,8,8,8,8,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,8,8,8,8,2,0,2,6,6,8,8,2,8,8,8,2,2,2,8,8,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,8,2,6,6,2,8,8,2,8,8,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,8,8,2,2,2,0,2,6,6,8,8,2,2,2,2,2,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,2,2,6,6,2,8,8,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,0,2,6,6,8,8,8,8,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,2,8,6,6,2,8,8,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,0,2,6,6,8,8,8,8,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,2,8,6,6,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,2,2,6,6,8,8,8,8,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,2,8,6,6,8,8,8,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,2,2,6,6,8,8,8,8,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,2,8,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,2,8,8,8,8,8,8,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8,8,8,8,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,2,8,8,8,8,8,8,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,2,8,8,8,8,8,2,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,2,2,8,8,8,8,8,2,2,2,2,2,2,2,8,8,8,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,2,8,8,8,8,8,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2,2,0,2,8,8,8,8,8,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,0,0,3,3,2,8,8,2,8,8,8,8,8,2,2,2,2,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,2,2,0,0,2,8,8,8,8,8,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,0,0,3,3,2,8,8,2,2,8,8,2,2,2,2,0,2,2,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,2,2,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,0,0,3,3,2,8,8,8,8,8,8,8,8,8,2,0,0,2,2,2,2,2,2,2,8,8,8,6,6,8,8,8,2,2,2,2,2,2,2,0,0,0,0,2,4,4,4,4,4,4,2,2,0,0,0,0,0,0,0,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,0,0,3,3,2,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,2,8,8,8,6,6,8,8,8,2,0,0,0,0,0,0,0,0,0,0,2,4,2,2,2,2,2,2,2,0,0,0,0,0,0,0,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,0,0,3,3,2,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,2,8,8,8,6,6,8,8,8,2,0,0,0,0,0,0,0,0,0,0,2,4,2,2,2,2,2,2,2,0,0,0,0,0,0,0,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,0,3,3,3,2,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,2,8,8,8,6,6,8,8,8,2,0,0,0,0,0,0,0,0,0,0,2,4,2,2,2,2,2,2,2,0,0,0,0,0,0,0,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,2,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,8,8,8,6,6,8,8,8,0,0,0,0,0,0,0,0,0,0,0,2,4,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,2,2,2,2,4,2,2,4,2,2,2,2,2,2,2,2,0,0,0,2,8,8,8,6,6,8,8,8,2,0,0,0,2,2,2,2,2,2,2,2,4,2,2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,4,0,0,4,4,4,4,4,4,4,4,2,0,0,0,2,8,8,8,6,6,8,8,8,2,0,0,0,2,4,4,4,4,4,4,4,4,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,4,2,0,0,0,2,8,8,8,6,6,8,8,8,2,0,0,0,2,4,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,4,2,2,2,2,2,2,2,4,2,2,4,2,2,2,2,2,2,2,4,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,3,3,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,2,2,0,0,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,0,0,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,2,2,0,0,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,0,0,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,5,5,5,5,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,5,5,5,5,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,5,5,5,5,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  0,0,3,3,3,3,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,5,5,5,5,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  0,0,3,3,3,3,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,5,5,5,5,5,5,4,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  0,0,3,3,3,3,3,3,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,5,5,5,5,5,5,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  0,0,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,4,4,5,5,5,5,4,4,0,0,0,0,2,2,2,2,0,0,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,4,3,3,3,3,3,3,4,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,2,0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,3,3,3,3,3,3,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,
  0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};

}