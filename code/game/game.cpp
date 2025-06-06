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

	//------------------------------------parasha
	while (!glfwWindowShouldClose(window))
	{
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);



		glm::mat4 view = glm::mat4(1.0f); 
		glm::mat4 projection = glm::mat4(1.0f);

		projection = glm::ortho(0.0f, width, 0.0f, height, -1.0f, 100.0f);

		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));
		
		shader_texture->setMat4("projection", projection); 
		shader_texture->setMat4("view", view);


			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(200,300,0));
			model = glm::scale(model, glm::vec3(150.0f, 150.0f, 1.0f)); 
			shader_texture->setMat4("model", model);

		   DrawSquareTexture(shader_texture, EBO_tex, Texture);

		    model = glm::mat4(1.0f);
		    model = glm::translate(model, glm::vec3(400, 300, 1));
		    model = glm::scale(model, glm::vec3(200.0f, 150.0f, 1.0f)); 
			model = glm::rotate(model, glm::radians(-55.0f * (float)glfwGetTime() ), glm::vec3(1.0f, -1.0f, -1.0f));
		    shader_texture->setMat4("model", model);

		   DrawSquareTexture(shader_texture, EBO_tex, Texture);
		

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








