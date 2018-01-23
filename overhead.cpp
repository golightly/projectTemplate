#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "overhead.h"

void overhead(SDL_Window* &window, SDL_GLContext &context) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	context = SDL_GL_CreateContext(window);
	
	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	SDL_GL_SetSwapInterval(1);
}