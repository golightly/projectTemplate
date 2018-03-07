#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SDL.h>
#include <SDL_ttf.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "overhead.h"
#include "texAttribute.h"
#include "shader.h"
#include "texture.h"
#include <iostream>


int main(int argc, char* args[]) {
	Overhead overhead;
	setupOverhead(overhead);
	TTF_Init();
	TexAttribute texAttribute;
	setupTexAttribute(texAttribute);
	Shader shader(getVertexSource(), getFragmentSource());
	setupShader(shader);
	TTF_Font *font;
	font = TTF_OpenFont("HOMOARAK.ttf", 10);
	SDL_Surface* surface;
	SDL_Color color = { 0, 0, 0 };
	surface = TTF_RenderText_Blended(font, "testing", color);
	int surfaceWidth = surface->w;
	int surfaceHeight = surface->h;
	Uint8 red, green, blue, alpha;
	float* textImage = new float[(surfaceWidth * surfaceHeight) * 3]; //ignore alpha for now
	int countText = 0;
	SDL_LockSurface(surface);
	Uint8* p = (Uint8*)surface->pixels;
	//Uint32* pixels = (Uint32*)surface->pixels;
	char input;
	for (int x = 0; x < surfaceWidth; ++x) {
		for (int y = 0; y < surfaceHeight; ++y) {
			Uint32 pixel = p[(y * surface->w) + x];
			SDL_GetRGBA(pixel, surface->format, &red, &green, &blue, &alpha);
			if (red != 0) {
				std::cout << "found a valid value! red = " << (int)red << std::endl;
				//std::cin >> input;
			}
			textImage[countText] = ((float)red / 255.0f);
			++countText;
			textImage[countText] = ((float)green / 255.0f);
			++countText;
			textImage[countText] = ((float)blue / 255.0f);
			++countText;
			//ignore alpha channel for now
		}
	}
	SDL_UnlockSurface(surface);
	SDL_FreeSurface(surface);
	for (int a = 0; a < (surfaceWidth * surfaceHeight) * 3; ++a) {
		if (textImage[a] != 0) {
			std::cout << "valid value found! image[" << a << "] = " << textImage[a] << std::endl;
			//std::cin >> input;
			//this works now!
		}
		if ((a + 1) == (surfaceWidth * surfaceHeight) * 3) {
			std::cout << "size of text box: " << a; //this prints about 1900ish
			std::cin >> input;
		}
	}
	GLuint texture;
	float* image;
	int width = 1000, height = 1000;
	int textX = width - (int)(width / 1.5);
	int textY = height - (int)(height / 1.5);
	//use new setupTexture function
	setupTexture(texture, shader, width, height, image, textImage, surfaceWidth, surfaceWidth, textX, textY);
	//setupTexture(texture, shader, width, height, image);
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
		//updateTexture(texture, shader, width, height, image);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		SDL_GL_SwapWindow(overhead.window);
	}
	delete[] image;
	shutdown(overhead, texture, shader, texAttribute);
	return 0;
}