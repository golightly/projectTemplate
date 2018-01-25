#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "overhead.h"
#include "texAttribute.h"
#include "shader.h"
#include "texture.h"


int main(int argc, char* args[])
{
	Overhead overhead;
	setupOverhead(overhead);
	TexAttribute texAttribute;
	setupTexAttribute(texAttribute);
	Shader shader(getVertexSource(), getFragmentSource());
	setupShader(shader);
	GLuint texture;
	float* image;
	int width = 800, height = 600;
	setupTexture(texture, shader, width, height, image);
	SDL_Event e;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		updateTexture(texture, shader, width, height, image);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		SDL_GL_SwapWindow(overhead.window);
	}
	delete[] image;
	shutdown(overhead, texture, shader, texAttribute);
	return 0;
}