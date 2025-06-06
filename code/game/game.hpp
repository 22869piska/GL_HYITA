#pragma once
#ifndef gamehpp
#define gamehpp

#include"engine.hpp"


//-----------

class Game:Engine
{
public:

	Game(GLFWwindow*); ~Game();

	void Start();
	void GameInit();
	
	



//game_proc->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 private:

};
void viewport_size_callback(GLFWwindow* window, int width, int height);






#endif 
//----------------------------
	// GLFWwindow* window; //указатель на указатель указателя окна

