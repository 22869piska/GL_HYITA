#include"engine.hpp"
//-------------
Engine::~Engine()
{

}
Engine::Engine()
{
#ifdef _DEBUG
	std::cout << "CREATE_ENGINE_CLASS \n";
#endif // _DEBUG
	Texture = new Textures;
}

//------------
void Engine::InitGlObj()
{

	shader_test = new Shader("code/game/shader/VERTEX_TEST.shader", "code/game/shader/FRAGMENT_TEST.shader");

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_3), vertices_3, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//-------------------------------------texture 

	shader_texture = new Shader("code/game/inc/_TEXTURE_VS.shader", "code/game/inc/_TEXTURE_FS.shader");

	glGenVertexArrays(1, &VAO_tex);
	glGenBuffers(1, &VBO_tex);
	glGenBuffers(1, &EBO_tex);

	glBindVertexArray(VAO_tex);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_tex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_tex), vertices_tex, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_tex);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_tex), indices_tex, GL_STATIC_DRAW);
	//pos->
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//rgb->
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(2 * sizeof(float)) );
	glEnableVertexAttribArray(1);
	//texture pos->
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(5 * sizeof(float)) );
	glEnableVertexAttribArray(2);

	
}
//----------------------------------------------------------------------------------------------------------------------
void Engine::InitGameObj()
{
	Texture->LoadAllTexture();
}
//----------------------------------------------------------------------------------------------------------------------
void Engine::Draw3Angle(Shader* shader_ptr,unsigned int VAO_ptr)
{

	shader_ptr->use();
	glBindVertexArray(VAO_ptr);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
//->ex
void Engine::Draw3Angle_Ex(Shader* shader_ptr, unsigned int VAO_ptr,const int mode)
{

	shader_ptr->use();
	glBindVertexArray(VAO_ptr);
	glDrawArrays(mode, 0, 3);
}
//-->
void Engine::DrawSquare(Shader* shader_ptr, unsigned int EBO_ptr)
{
	shader_ptr->use();
	glBindVertexArray(EBO_ptr);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

};
//->ex
void Engine::DrawSquare_Ex(Shader* shader_ptr, unsigned int EBO_ptr,const int mode)
{
	shader_ptr->use();
	glBindVertexArray(EBO_ptr);
	glDrawElements(mode, 6, GL_UNSIGNED_INT, 0);
}
//----------------------------------------------------------------------------------------------------------------------
void Engine::DrawSquareTexture(Shader* shader_ptr, unsigned int EBO_ptr,Textures* texture)
{

	shader_ptr->use();
	glBindTexture(GL_TEXTURE_2D, texture->texture);
	glBindVertexArray(EBO_ptr);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

};
//->ex
void Engine::DrawSquareTexture_Ex(Shader* shader_ptr, unsigned int EBO_ptr, const int mode, Textures* texture)
{
	shader_ptr->use();
	glBindTexture(GL_TEXTURE_2D, texture->texture);
	glBindVertexArray(EBO_ptr);
	glDrawElements(mode, 6, GL_UNSIGNED_INT, 0);
}
//----------------------------------------------------------------------------------------------------------------------





















