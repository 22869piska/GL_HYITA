#include"game.hpp"
Game::~Game()
{
  #ifdef _DEBUG
	std::cout << "GAME_DESTROY";
  #endif 

}
Game::Game(GLFWwindow* window_main_ptr)
{
	window = window_main_ptr;
	if (window == nullptr) { std::cout<<"WINDOW_NULLPTR  "<<window<<std::endl; }

}

//zalupa
float width = 1280; float height = 860;

//

void Game::Start()
{
  GameInit();
 
	//------------------------------------parasha
	 while (!glfwWindowShouldClose(window))
	 {
		
		PlayerMove();
		UpdCollisonParam();
		camera->SetDataViewInShader(shader_texture, width, height,glm::vec3(player_pos,0.0f)   );

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		param->EBO = EBO_tex;
		param->shader = shader_texture;
		param->texture = Texture->texture;

		param->set_size = player_size;
		param->set_pos = glm::vec3(player_pos, 0.0f);
		param->texture = Texture->stray228;

		gameobj->Box(param);//player


		param->set_size = glm::vec2(100.f, 100.f);
		param->texture = Texture->texture;

	
		for (int i = 0; i != 4; i++)
		{
			GameObj penis[4];

			param->set_pos = glm::vec3(i * 100.f +(1000*(float)std::sin(glfwGetTime())), 100.f, 0.f);

			penis[i].Box(param);
			PlayerCheckCollision(&penis[i]);
			penis[i].~GameObj();
		}
		for (int i = 0; i != 5; i++)
		{
			GameObj penis[5];

			param->set_pos = glm::vec3(  (i * 100.f), (i * 100.f)-500, 0.f);
			param->texture = Texture->MGE_sniper;

			penis[i].Box(param);
			PlayerCheckCollision(&penis[i]);
			penis[i].~GameObj();
		}
		for (int i = 0; i != 4; i++)
		{
			GameObj penis[4];

			param->set_pos = glm::vec3((i * 100.f), 100, 0.f);
			param->texture = Texture->MGE_sniper;

			penis[i].Box(param);
			PlayerCheckCollision(&penis[i]);
			penis[i].~GameObj();
		}



		//----
		

		 //-------------------------endw
		 glfwSwapBuffers(window);
	     glfwPollEvents();
	 }
	 glfwTerminate();
}

//-------------------------------------------------------------------------------------------------------------
void Game::GameInit()
{
	InitGlObj();
	InitGameObj();


	//->
	glDisable(GL_DEPTH_TEST);

	player_pos  = glm::vec2(100.f, 300.f);
	player_size = glm::vec2(100.f, 100.f);

	//--------------хуйня
	glfwSetFramebufferSizeCallback(window, viewport_size_callback);

	glfwSwapInterval(120);
}

//-------------------------------------------------------------------------------------------------------------

void Game::UpdCollisonParam()
{
	player_collisionX        = false;
	player_collisionX_left   = false;
	player_collisionX_right  = false;

	player_collisionY_bottom = false;
	player_collisionY_top    = false;

	//std::cout << "XL:" << player_collisionX_left << "XR:" << player_collisionX_left << "__";
	
}
void Game::PlayerMove()
{
	glm::vec2 next_pos = player_pos;


	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		 { next_pos.x -= (player_speed); }
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		 { next_pos.x  += (player_speed); }
	}
	if (player_collisionY_bottom == false)
	{
		   next_pos.y -= (player_fall_speed);
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && player_collisionY_top == false && player_collisionY_bottom == true)
	{
		jmp = 1;
	}
	//proc ny tipa
	if (jmp)
	{
		next_pos.y += (  (player_jump_speed * player_jump_force ) + player_fall_speed );
			if(player_jump_force >= 1 )
			{
				jmp = 0;
				player_jump_force = 0.1;
			}//говнокод кинг
			else
			{
				player_jump_force += 0.1;
			}
	}
	
	player_next_pos = next_pos;
}
void Game::PlayerCheckCollision(GameObj* pidr)
{
/*
	if (player_pos.x < pidr->collision_pos.x + pidr->collision_size.x && player_pos.x + player_size.x > pidr->collision_pos.x
		&& player_pos.y <= pidr->collision_pos.y + pidr->collision_size.y && player_pos.y + player_size.y >= pidr->collision_pos.y
	   )
	{
		player_collisionY_bottom = true;
		if (player_pos.y < pidr->collision_pos.y + pidr->collision_size.y)
		{
			player_pos.y = pidr->collision_pos.y + pidr->collision_size.y;
		}
	}
	
	*/

	bool collisionX = player_pos.x < pidr->collision_pos.x + pidr->collision_size.x &&
		              player_pos.x + player_size.x > pidr->collision_pos.x;

	bool collisionY = player_pos.y <= pidr->collision_pos.y + pidr->collision_size.y &&
		              player_pos.y + player_size.y >= pidr->collision_pos.y;
	//->
	if (collisionX && collisionY)
	{
		
		float overlapLeft   = (player_pos.x + player_size.x) - pidr->collision_pos.x;
		float overlapRight  = (pidr->collision_pos.x + pidr->collision_size.x) - player_pos.x;
		float overlapTop    = (player_pos.y + player_size.y) - pidr->collision_pos.y;
		float overlapBottom = (pidr->collision_pos.y + pidr->collision_size.y) - player_pos.y;
		
		float minOverlap = std::min({ overlapLeft, overlapRight, overlapTop, overlapBottom });
		
		 if (minOverlap == overlapLeft)
		 {
			player_next_pos.x = pidr->collision_pos.x - player_size.x;
		 }
		 else if (minOverlap == overlapRight)
		 {
			player_next_pos.x = pidr->collision_pos.x + pidr->collision_size.x;
		 }
		 else if (minOverlap == overlapTop)
		 {
			player_next_pos.y = pidr->collision_pos.y - player_size.y;
			player_collisionY_top = true;
		 }
		 else if (minOverlap == overlapBottom)
		 {
			player_next_pos.y = pidr->collision_pos.y + pidr->collision_size.y;
			player_collisionY_bottom = true;
		 }

	}
	//->
	player_pos = player_next_pos;
}

//-------------------------------------------------------------------------------------------------------------

//callback
void viewport_size_callback(GLFWwindow* window, int width_, int height_)
{
	glViewport(0, 0, width_, height_);
	width = width_;  height = height_;
	std::cout << width_<<"__" << height_<<"\n";
}








