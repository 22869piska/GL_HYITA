#include"game_obj.hpp"

GameObj::GameObj()
{
	 
}
GameObj::~GameObj()
{
}
//----------------------------
void GameObj::Box(Shader* shader_,const unsigned int texture_, const unsigned int EBO_ ,const glm::vec3 set_pos_,const glm::vec2 set_size)
{
	shader_->use();
	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(set_pos_) );
	model = glm::scale(model, glm::vec3(set_size, 1.0f));

	shader_->setMat4("model", model);

	glBindTexture(GL_TEXTURE_2D, texture_);
	glBindVertexArray(EBO_);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	collision_pos  = glm::vec2(set_pos_);
	collision_size = glm::vec2(set_size);
	size           = glm::vec2(set_size);
}
void GameObj::Box(Param* param)
{
	param->shader->use();
	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(param->set_pos) );
	model = glm::scale(    model, glm::vec3(param->set_size,1.f) ) ;

	param->shader->setMat4("model", model);

	glBindTexture(GL_TEXTURE_2D, param->texture);
	glBindVertexArray(param->EBO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	collision_pos  = glm::vec2(param->set_pos);
	collision_size = glm::vec2(param->set_size);
	size           = glm::vec2(param->set_size);
}
//----------------------------
void GameObj::SetCollisionPos(glm::vec2 set_pos_)
{

}
//----------------------------

//--------------------------------------------------------


//OBJ PARAMETR->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

Param::Param()
{

}
Param::~Param()
{
}
//-----------------------------
void Param::SetParam(Shader* shader_, unsigned int texture_, unsigned int EBO_, glm::vec3 set_pos_)
{
	shader = shader_; texture = texture_; EBO = EBO_; set_pos = set_pos_;
}
void Param::SetParam(Shader* shader_, unsigned int texture_, unsigned int EBO_)
{
	shader = shader_; texture = texture_; EBO = EBO_;
}
void Param::SetParam(Shader* shader_, unsigned int texture_)
{
	shader = shader_; texture = texture_;
}
void Param::SetParam(Shader* shader_ )
{
	shader = shader_;
}
//---------------------------------


