#pragma once

#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

struct TexAttribute {
	GLuint vao, vbo, ebo;
	GLfloat* vertices;
	GLuint* elements;
};

void setupTexAttribute(TexAttribute &texAttribute);