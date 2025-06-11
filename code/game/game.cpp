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
	
	glDisable(GL_DEPTH_TEST);
	
	player->player_pos = glm::vec2(200.f, 800.f);

	//------------------------------------parasha
	while (!glfwWindowShouldClose(window))
	{
		
		InPut(window);
		camera->SetDataInShader(shader_texture, width, height, camera->camera_pos,player);


		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		
		gameobj->shader = shader_texture;
		gameobj->texture = Texture->texture;
		gameobj->EBO = EBO_tex;
		

		for (int i=0; i !=12; i++ ) 
		{
			gameobj->set_pos = glm::vec2(100.f+(100.f*i), 400.f);
			gameobj->Box();

		}
		 
		gameobj->Box(shader_texture, Texture->stray228, EBO_tex, glm::vec2(200.f, 700.f));
		
		






		 //-------------------------endw
		 glfwSwapBuffers(window);
	     glfwPollEvents();
	}
	glfwTerminate();
}






//-------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------
void Game::GameInit()
{
	InitGlObj();
	InitGameObj();



	//--------------υσινÿ
	glfwSetFramebufferSizeCallback(window, viewport_size_callback);

	glfwSwapInterval(60);
}

//callback
void viewport_size_callback(GLFWwindow* window, int width_, int height_)
{
	glViewport(0, 0, width_, height_);
	width = width_;  height = height_;
	std::cout << width_<<"__" << height_<<"\n";
}








