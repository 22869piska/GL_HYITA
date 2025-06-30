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

#include"texture.hpp"

#include"C:\Users\PROPER069\Desktop\vs\code\game\shader\shader_class.hpp"

struct Param
{
public:
	Param(); ~Param();

	void SetParam(Shader* shader_,  unsigned int texture_,  unsigned int EBO_,   glm::vec3 set_pos_ );
	void SetParam(Shader* shader_,  unsigned int texture_,  unsigned int EBO_);
	void SetParam(Shader* shader_,  unsigned int texture_);
	void SetParam(Shader* shader_ );


	Shader* shader = nullptr;  unsigned int texture = 0;  unsigned int EBO = 0;
	
	glm::vec3 set_pos = glm::vec3(0.f, 0.f,0.f);
	glm::vec2 set_size = glm::vec2(100.f, 100.f);
};


class GameObj
{
public:


	GameObj(); ~GameObj();

	//--------------------

	void Box(Shader* shader_, const unsigned int texture_, const unsigned int EBO_, const glm::vec3 set_pos_, const glm::vec2 set_size);
	void Box(Param* param);

	void SetCollisionPos(glm::vec2 set_pos_);
	
	//data
	

	glm::vec2 size = glm::vec2(100.0f, 100.0f); 
	glm::vec2 collision_pos; glm::vec2 collision_size;

private:
};
//-------------------------------------------------------------------------------------------------------





#endif
