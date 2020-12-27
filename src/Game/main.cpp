
#include "State.h"

int main()
{
	
	GameState state;
	
	while (state.window.isOpen())
	{

		state.PollEvents();

		state.window.clear();
		
		state.UpdateAndRender();

		state.window.display();

	}


	return 0;
}