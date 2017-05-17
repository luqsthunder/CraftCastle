#version 330

// vertex attributes 
layout(location = 0) in vec4  i_position;
layout(location = 1) in vec3  i_normal;
layout(location = 2) in vec2  i_texcoord1;
layout(location = 3) in float i_texNum;

uniform mat4 u_viewProj_mat; // view-projection matrix
uniform mat4 u_model_mat; // model matrix
uniform mat3 u_normal_mat; // normal matrix

uniform vec3 u_light_position; 
uniform vec3 u_camera_position;

// inputs for fragment shader
out vec3 v_normal;
out vec2 v_texcoord1;
out vec3 v_directionToLight;
out vec3 v_directionToCamera;
out float v_texNum;

void main(void)
{
   vec4 worldPos = u_model_mat * vec4(i_position);
   v_normal = u_normal_mat * i_normal;
   v_texcoord1 = i_texcoord1;

   vec3 vectorToLight = u_light_position - worldPos.xyz;
   v_directionToLight = normalize( vectorToLight);
   v_directionToCamera = normalize( u_camera_position - worldPos.xyz );

   gl_Position = u_viewProj_mat * worldPos; 
   v_texNum = i_texNum;
}