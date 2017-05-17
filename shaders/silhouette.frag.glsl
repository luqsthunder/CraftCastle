#version 330

uniform vec3 u_color1;

out vec4 o_FragColor;

void main(void)
{
   o_FragColor = vec4(u_color1, 1.0);
}