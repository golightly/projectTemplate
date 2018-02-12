#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "texAttribute.h"

void setupTexAttribute(TexAttribute &texAttribute) {
	glGenVertexArrays(1, &texAttribute.vao);
	glBindVertexArray(texAttribute.vao);
	glGenBuffers(1, &texAttribute.vbo);
	texAttribute.vertices = new GLfloat[16]{
		-1.0f,  1.0f, 0.0f, 0.0f, // Top-left, texture bottom left
		1.0f,  1.0f, 1.0f, 0.0f, // Top-right, texture bottom right
		1.0f, -1.0f, 1.0f, 1.0f, // Bottom-right, texture top right
		-1.0f, -1.0f, 0.0f, 1.0f  // Bottom-left, texture top right
	};
	glBindBuffer(GL_ARRAY_BUFFER, texAttribute.vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, texAttribute.vertices, GL_STATIC_DRAW);
	glGenBuffers(1, &texAttribute.ebo);
	texAttribute.elements = new GLuint[6]{
		0,1,2,
		2,3,0
	};
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, texAttribute.ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 6, texAttribute.elements, GL_STATIC_DRAW);
}