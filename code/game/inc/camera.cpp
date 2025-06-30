#include "camera.hpp"

Camera::Camera()
{

}
Camera::~Camera()
{

}
void Camera::SetDataViewInShader(Shader* shader_ptr, const float width_, const float  height_, const glm::vec3 camera_pos_, const glm::vec2 player_pos)
{
    shader_ptr->use();

    glm::mat4 projection = glm::ortho(
        -width_  / 2 + player_pos.x,      // ����� �������
        width_   / 2 + player_pos.x,      // ������ �������
        -height_ / 2 + player_pos.y,      // ������ �������
        height_  / 2 + player_pos.y,      // ������� �������
        -10.0f, 10.0f                                 // ������� � ������� 
    );
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, camera_pos_ );

    shader_ptr->setMat4("projection", projection);
    shader_ptr->setMat4("view", view);
}
//---------------------------
void Camera::SetDataViewInShader(Shader* shader_ptr,const float width_, const float height_, const glm::vec2 player_pos)
{
    shader_ptr->use();

    glm::mat4 projection = glm::ortho(
        -width_ / 2 + player_pos.x,      // ����� �������
        width_ / 2 + player_pos.x,      // ������ �������
        -height_ / 2 + player_pos.y,      // ������ �������
        height_ / 2 + player_pos.y,      // ������� �������
        -10.0f, 10.0f                                 // ������� � ������� 
    );
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, camera_pos );

    shader_ptr->setMat4("projection", projection);
    shader_ptr->setMat4("view", view);
}
