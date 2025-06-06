#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include<iostream>





GLFWwindow* pidrinit(GLFWwindow* window)
{
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,1);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
 
    //----------------------------------
    window = glfwCreateWindow(X_WINDOW_SIZE, Y_WINDOW_SIZE, "SALT BOY", 0, 0);
    glfwMakeContextCurrent(window);

   //--
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "NO_GLAD" << std::endl;
        return nullptr;
    }//כמאה דכאה
    glViewport(0, 0, 1280, 840);

    //---------------------------------
  
   

    
    
    return window;
}