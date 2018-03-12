#pragma once
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "shader.h"

void setupTexture(GLuint &texture, Shader &shader, int &width, int &height, unsigned char* &image);

void updateTexture(GLuint &texture, Shader &shader, int &width, int &height, float* image);

void setupTexture(GLuint &texture, Shader &shader, int &width, int &height, unsigned char* &image, unsigned char* text, int textX, int textY, int textW, int textH);