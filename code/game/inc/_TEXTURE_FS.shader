#version 330 core
out vec4 FragColor;
  
  
  in vec3 rgb_color;
  in vec2 texture_pos;

  uniform sampler2D my_texture;

void main()
{
   
   FragColor = texture(my_texture,texture_pos);
   // FragColor = vec4(1.0f,0.3f,0.5f, 1.0f);
     
} 