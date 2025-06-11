#pragma once

#pragma once
#ifndef gameobjpp
#define gameobjhpp

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include<iostream>

#include"player.hpp"
#include"texture.hpp"

#include"C:\Users\PROPER069\Desktop\vs\code\game\shader\shader_class.hpp"

class GameObj
{
public:
	GameObj(); ~GameObj();


	void Box(Shader* shader_, const unsigned int texture_, const unsigned int EBO_, const glm::vec2 set_pos_ );
	void Box();






	//data
	Shader* shader;  unsigned int texture;  unsigned int EBO;   glm::vec2 set_pos;

private:
};
//-------------------------------------------------------------------------------------------------------





#endif
