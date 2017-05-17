#version 330 core

layout(location = 0)in vec4  aVertices;
layout(location = 1)in vec3  aNormal;
layout(location = 2)in vec2  aTexCoord;
layout(location = 3)in float aTexUse;

uniform mat4 projviewobj;
uniform mat4 modelmat;

out vec3 fragPos;
out vec3 normal;
out vec2 texCoord;
out float texUse;

void main()
{
  gl_Position = projviewobj * aVertices;
  vec4 finalNorm = (modelmat * aVertices);
  vec3 normalLast = mat3(transpose(inverse(modelmat))) * vec3(finalNorm.xyz * finalNorm.w);
  normal = normalLast;
  texCoord = aTexCoord;
  texUse = aTexUse;
}