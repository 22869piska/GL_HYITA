#include "camera.hpp"

Camera::Camera()
{

}
Camera::~Camera()
{

}
//---------------------------
void Camera::SetDataInShader(Shader* shader_ptr,const float width_, const float height_,const glm::vec3 camera_pos_,Player* player_)
{
    
    glm::mat4 projection = glm::ortho(
        -width_  / 2 +   player_->player_pos.x,      // лева€ граница
        width_   / 2 +   player_->player_pos.x,      // права€ граница
        -height_ / 2 +   player_->player_pos.y,      // нижн€€ граница
        height_  / 2 +   player_->player_pos.y,      // верхн€€ граница
        -1.0f, 1.0f                                 // ближн€€ и дальн€€ 
    );

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, camera_pos_ );

    shader_ptr->setMat4("projection", projection);
    shader_ptr->setMat4("view", view);


}
