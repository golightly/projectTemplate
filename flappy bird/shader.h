#pragma once

#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

const GLchar* getVertexSource();

const GLchar* getFragmentSource();

struct Shader {
	Shader(const GLchar* vertSource, const GLchar* fragSource) : vertexSource(vertSource), fragmentSource(fragSource) {}
	const GLchar* vertexSource;
	const GLchar* fragmentSource;
	GLuint vertexShader, fragmentShader, shaderProgram;
	GLint posAttrib, texAttrib;
};

void setupShader(Shader &shader);