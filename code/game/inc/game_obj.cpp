#include"game_obj.hpp"

GameObj::GameObj()
{
}

GameObj::~GameObj()
{
}

void GameObj::Box(Shader* shader_,const unsigned int texture_, const unsigned int EBO_ ,const glm::vec2 set_pos_ )
{
	shader_->use();
	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(set_pos_, 0));
	model = glm::scale(model, glm::vec3(100.0f, 100.0f, 1.0f));

	shader_->setMat4("model", model);

	glBindTexture(GL_TEXTURE_2D, texture_);
	glBindVertexArray(EBO_);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void GameObj::Box()
{
	shader->use();
	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(set_pos, 0));
	model = glm::scale(model, glm::vec3(100.0f, 100.0f, 1.0f));

	shader->setMat4("model", model);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(EBO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

//OBJ PARAMETR->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
