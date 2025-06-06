#include "MAIN.hpp"

GLFWwindow* main_window;

int main()
{
	main_window = pidrinit(main_window);

	Game game(main_window);
	game.Start();
	




	return 0;
}