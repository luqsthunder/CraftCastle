#version 330 core

out vec4 color;

in vec3 fragPos;
in vec2 texCoord;
in vec3 normal;
in float texUse;

uniform vec3 lightPos;
uniform vec3 viewPos;

uniform sampler2D tex2D0;
uniform sampler2D tex2D1;
uniform sampler2D tex2D2;
uniform sampler2D tex2D3;
uniform sampler2D tex2D4;
uniform sampler2D tex2D5;
uniform sampler2D tex2D6;
uniform sampler2D tex2D7;
uniform sampler2D tex2D8;
uniform sampler2D tex2D9;
uniform sampler2D tex2D10;
uniform sampler2D tex2D11;
uniform sampler2D tex2D12;
uniform sampler2D tex2D13;

void main()
{    
  vec3 lightColor = vec3(1.0, 1.0, 1.0);
  // Ambient
  float ambientStrength = 0.1f;
  vec3 ambient = ambientStrength * lightColor;

  // Diffuse 
  vec3 norm = normalize(normal);
  vec3 lightDir = normalize(lightPos - fragPos);
  float diff = max(dot(norm, lightDir), 0.0);
  vec3 diffuse = diff * lightColor;

  // Specular
  float specularStrength = 0.5f;
  vec3 viewDir = normalize(viewPos - fragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
  vec3 specular = specularStrength * spec * lightColor;

  vec3 tex;
  if(texUse == 0)
    tex = texture(tex2D0, texCoord).rgb;
  else if(texUse == 1)
    tex = texture(tex2D1, texCoord).rgb;
  else if(texUse == 2)
    tex = texture(tex2D2, texCoord).rgb;
  else if(texUse == 3)
    tex = texture(tex2D3, texCoord).rgb;
  else if(texUse == 4)
    tex = texture(tex2D4, texCoord).rgb;
  else if(texUse == 5)
    tex = texture(tex2D5, texCoord).rgb;
  else if(texUse == 6)
    tex = texture(tex2D6, texCoord).rgb;
  else if(texUse == 7)
    tex = texture(tex2D7, texCoord).rgb;
  else if(texUse == 8)
    tex = texture(tex2D8, texCoord).rgb;
  else if(texUse == 9)
    tex = texture(tex2D9, texCoord).rgb;
  else if(texUse == 10)
    tex = texture(tex2D10, texCoord).rgb;
  else if(texUse == 11)
    tex = texture(tex2D11, texCoord).rgb;
  else if(texUse == 12)
    tex = texture(tex2D12, texCoord).rgb;
  else if(texUse == 13)
    tex = texture(tex2D13, texCoord).rgb;
  else
    tex = vec3(0, 1., 0);

  vec3 result = tex;
  color = vec4(result, 1.0f);
}