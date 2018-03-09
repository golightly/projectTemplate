#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "shader.h"

void setupTexture(GLuint &texture, Shader &shader, int &width, int &height, float* &image) {
	glGenTextures(1, &texture);
	image = new float[(width * height) * 3];
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
}

void setupTexture(GLuint &texture, Shader &shader, int &width, int &height, float* &image, float* text, int textX, int textY, int textW, int textH) {
	glGenTextures(1, &texture);
	image = new float[(width * height) * 3];
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
	int startpos1, startpos2;
	for(int y = 0; y < textH; ++y) {
		for(int x = 0; x < textW; ++x) {
			startpos1 = (((y + textY) * width) * 3) + ((x + textX) * 3);
			startpos2 = ((y * textW) *4) + (x * 4);
			if (text[startpos2 + 3] != 0.0) {
				image[startpos1] = text[startpos2];
				image[startpos1 + 1] = text[startpos2 + 1];
				image[startpos1 + 2] = text[startpos2 + 2];
			}
		}
	}
	glActiveTexture(GL_TEXTURE0);
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_FLOAT, image);
	glUniform1i(glGetUniformLocation(shader.shaderProgram, "texSampler"), 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void updateTexture(GLuint &texture, Shader &shader, int &width, int &height, float* image) {
	for (int a = 0; a < (width * height) * 3; ) {
		if (a < ((width * height) * 3) / 2) {
			image[a] += 0.1f;
			if (image[a] > 1.0f)
				image[a] = 0.0f;
			++a;
			image[a] += 0.2f;
			if (image[a] > 1.0f)
				image[a] = 0.0f;
			++a;
			image[a] += 0.3f;
			if (image[a] > 1.0f)
				image[a] = 0.0f;
			++a;
		}
		else {
			image[a] += 0.1f;
			if (image[a] > 1.0f)
				image[a] = 0.0f;
			++a;
			image[a] += 0.5f;
			if (image[a] > 1.0f)
				image[a] = 0.0f;
			++a;
			image[a] += 0.7f;
			if (image[a] > 1.0f)
				image[a] = 0.0f;
			++a;
		}
	}
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGB, GL_FLOAT, image);
}
