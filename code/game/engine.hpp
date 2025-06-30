#pragma once
#ifndef enginehpp
#define enginehpp

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include<iostream>

//-------------------
#include"shader/shader_class.hpp"

#include"inc/camera.hpp"
#include"inc/texture.hpp"
#include"inc/game_obj.hpp"

 


class Engine {
public:
	///////////////////////////////////////////////////////////////////////////////FUNC-->
	Engine(); ~Engine();
	
	void InitGlObj();
	void InitGameObj();

	void  Draw3Angle(Shader* , unsigned int);  void  Draw3Angle_Ex(Shader*, unsigned int,const int);
	void  DrawSquare(Shader*, unsigned int);  void  DrawSquare_Ex(Shader*, unsigned int, const int);
	void  DrawSquareTexture(Shader* shader_ptr, unsigned int EBO_ptr, unsigned int tex_);
	void  DrawSquareTexture_Ex(Shader* shader_ptr, unsigned int EBO_ptr, const int mode, unsigned int tex_);

	void InPut(GLFWwindow* window_);
	
	////////////////////////////////////////////////////////////////////////////////DATA-->

	GLFWwindow* window;

	Textures* Texture; Camera* camera; GameObj* gameobj; Param* param;


	//--
	int KEY_STATE = NULL; 
	
	
	//--------------------------------GL DATA -->
	
	                                  //GL тестовый шейдер
	                        Shader* shader_test;

	unsigned int VAO, VBO;
	const float vertices_3[9] = {
		// positions         
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	//-
	                       Shader* shader_texture;
 
	 unsigned int VAO_tex; unsigned int VBO_tex; unsigned int EBO_tex;
	 float vertices_tex[28] = {
		 // positions          // colors           // texture coords
			0.5f,  0.5f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
			0.5f, -0.5f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
		   -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
		   -0.5f,  0.5f,    1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
	 };
	 unsigned int indices_tex[6] = {  // note that we start from 0!
		 0, 1, 3,   // first triangle
		 1, 2, 3    // second triangle
	 };


	                                  //GL 





	 //GAME OBJ DATA ->GAME OBJ DATA ->GAME OBJ DATA ->GAME OBJ DATA ->GAME OBJ DATA ->GAME OBJ DATA ->GAME OBJ DATA ->

	

	//====================================================
private:
};




















//callback->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void viewport_size_callback(GLFWwindow* window, int width, int height);

















#endif // !enginehpp

