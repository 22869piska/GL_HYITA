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

	
	//data

	//pl
	glm::vec2 player_pos = glm::vec2(0.0f, 0.0f);
	glm::vec2 player_size = glm::vec2(100.f, 100.f);
	glm::vec2 player_velocity = glm::vec2(0.f, 0.f);

	glm::vec2 player_next_pos = glm::vec2(0.f, 0.f);
	bool  player_collisionX_left = false; bool  player_collisionX_right = false; bool player_collisionX = false; bool  player_collisionY_bottom = false; bool  player_collisionY_top = false;
	bool jmp = 0;

	float player_speed = 10.5f;
	float player_jump_speed = 50.F; float player_jump_force = 0.1;
	float player_fall_speed = 15.F;
	
	//->



//game_proc->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 private:

	 void UpdCollisonParam();

	  void PlayerMove();
	  void PlayerCheckCollision(GameObj* pidr);


	 




};







#endif 
//----------------------------
	// GLFWwindow* window; //указатель на указатель указателя окна

