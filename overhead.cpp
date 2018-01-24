#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "overhead.h"
#include "texAttribute.h"
#include "shader.h"
#include "texture.h"

void setupOverhead(Overhead &overhead) {
	overhead.window = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	overhead.window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	overhead.context = SDL_GL_CreateContext(overhead.window);
	
	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	SDL_GL_SetSwapInterval(1);
}

void shutdown(Overhead &overhead, GLuint &texture, Shader &shader, TexAttribute &texAttribute) {
	glDeleteTextures(1, &texture);

	glDeleteProgram(shader.shaderProgram);
	glDeleteShader(shader.fragmentShader);
	glDeleteShader(shader.vertexShader);

	glDeleteBuffers(1, &texAttribute.ebo);
	glDeleteBuffers(1, &texAttribute.vbo);

	glDeleteVertexArrays(1, &texAttribute.vao);

	delete[] texAttribute.vertices;
	delete[] texAttribute.elements;

	SDL_DestroyWindow(overhead.window);
	overhead.window = NULL;

	SDL_Quit();
}