#pragma once
#ifndef playerhpp
#define playerhpp

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include<iostream>

struct Player
{
public:

	Player(); ~Player();

	void PlayerMove();


	//DATA	

	glm::vec2 player_pos = glm::vec2(0.0f, 0.0f);

private:

};




#endif 
