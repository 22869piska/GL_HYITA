#pragma once
#ifndef texturehpp
#define texturehpp

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<iostream>


#include <stb_image.h>

class Textures
	// namespace Texture
{
public:

	unsigned int LoadTexture(const char*);
	void LoadAllTexture();

	//-------------
	unsigned int texture;


};


#endif // texturehpp

