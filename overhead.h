#pragma once

#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "texAttribute.h"
#include "shader.h"
#include "texture.h"

struct Overhead {
	SDL_Window * window;
	SDL_GLContext context;
};

void setupOverhead(Overhead &overhead);

void shutdown(Overhead &overhead, GLuint &texture, Shader &shader, TexAttribute &texAttribute);