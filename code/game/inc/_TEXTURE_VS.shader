#version 330 core
  layout (location = 0) in vec2 aPos; 
  layout (location = 1) in vec3 aColor; 
  layout (location = 2) in vec2 aTex; 
 
  out vec2 position;
  out vec3 rgb_color;
  out vec2 texture_pos;

  uniform mat4 model;
  uniform mat4 view;
  uniform mat4 projection;



void main()
{
   //gl_Position = vec4(aPos,1.0f, 1.0); 
    gl_Position = projection * view * model * vec4(aPos,0.0f, 1.0f);
 
   rgb_color = aColor; 
   texture_pos = aTex; 

}