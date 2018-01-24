// Headers

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "overhead.h"
#include "texAttribute.h"
#include "shader.h"


int main(int argc, char* args[])
{
	Overhead overhead;

	setupOverhead(overhead);

	TexAttribute texAttribute;

	setupTexAttribute(texAttribute);

	Shader shader(getVertexSource(), getFragmentSource());
	setupShader(shader);
	// Load textures
	GLuint texture;
	glGenTextures(1, &texture);

	int width = 800, height = 600;
	float* image = new float[(width * height) * 3];
	for (int a = 0; a < (width * height) * 3; ) {
		if (a < ((width * height) * 3) / 2) {
			image[a] = 0.5f;
			++a;
			image[a] = 1.0f;
			++a;
			image[a] = 0.3f;
			++a;
		}
		else {
			image[a] = 0.0f;
			++a;
			image[a] = 0.5f;
			++a;
			image[a] = 0.7f;
			++a;
		}
	}

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_FLOAT, image);
	glUniform1i(glGetUniformLocation(shader.shaderProgram, "texSampler"), 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	SDL_Event e;
	bool quit = false;

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		// Clear the screen to black
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw a rectangle from the 2 triangles using 6 indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Swap buffers
		SDL_GL_SwapWindow(overhead.window);
	}

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

	return 0;
}