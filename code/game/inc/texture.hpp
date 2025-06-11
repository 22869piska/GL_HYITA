#pragma once
#ifndef texturehpp
#define texturehpp
#define uint unsigned int

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<iostream>


#include <stb_image.h>

class Textures
	// namespace Texture
{
public:

	unsigned int LoadTextureRGB(const char*);
	unsigned int LoadTextureRGBA(const char*);
	void LoadAllTexture();

	//-------------
	unsigned int texture;
	uint stray228;

};


#endif // texturehpp

