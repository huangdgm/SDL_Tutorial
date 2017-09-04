// COMP710 GP 2D Framework 2017

// Library includes:
#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	// The window we'll be rendering to
	SDL_Window* window = NULL;

	// The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)	// Initialise SDL
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// The first argument sets the window's caption or this part of the window.
		// The next two arguments define the x and y position the window is created in.
		// Since we don't care where it is created, we just put SDL_WINDOWPOS_UNDEFINED for the x and y position.
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			// Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			// Update the surface
			// you've drawn something to the screen surface doesn't mean you'll see it.
			// After you've done all your drawing you need to update the window so it 
			// shows everything you drew. A call to SDL_UpdateWindowSurface will do this.
			SDL_UpdateWindowSurface(window);

			// To keep it from disappearing, we'll call SDL_Delay. SDL_Delay will wait for a given amount of milliseconds.
			// A millisecond is 1/1000 of a second. This means the code above will make the window wait for 2000 1/1000 of a second or 2 seconds.
			// An important thing to note is that when SDL is delaying, it cannot accept input from the keyboard or mouse.
			SDL_Delay(2000);
		}
	}

	// After the window has delayed there for 2 seconds, we'll destroy the window to free its memory.
	// This will also take care of the SDL_Surface we got from it.
	SDL_DestroyWindow(window);

	// Quit SDL subsystems.
	SDL_Quit();

	return (0);
}
