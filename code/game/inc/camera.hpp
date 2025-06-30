#pragma once
#ifndef camerahpp
#define camerahpp


#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include<iostream>

//-------------------
#include"C:\Users\PROPER069\Desktop\vs\code\game\shader\shader_class.hpp"
#include"game_obj.hpp"


//CAMERA->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

struct Camera
{
public:
	Camera(); ~Camera();

	//CameraUpdate();

	void SetDataViewInShader(Shader*, const float, const float, const glm::vec3 camera_pos_,const glm::vec2 player_pos  );
	void SetDataViewInShader(Shader*, const float, const float, const glm::vec2 player_pos);


	//data
	glm::vec3 camera_pos = glm::vec3(0.0f, 0.0f,0.0f);




private:

};




#endif // !camerahpp

