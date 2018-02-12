#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

void loadTexture(SDL_Renderer* &renderer, SDL_Texture* &texture, std::string &path) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

int main(int argc, char* args[]) {
	int width = 800; int height = 600;
	SDL_Window* window = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Trashviolent SDK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	int imgLoad = IMG_INIT_PNG; IMG_Init(imgLoad);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_Texture* texture = NULL;
	std::string path = "testImage.png";
	loadTexture(renderer, texture, path);
	bool quit = false;
	SDL_Event event;
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_WINDOWEVENT:
				switch(event.window.event) {
				case SDL_WINDOWEVENT_CLOSE:
					quit = true;
					event.type = SDL_QUIT;
					std::cout << "window close triggered" << std::endl;
					break;
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					width = event.window.data1;
					height = event.window.data2;
					std::cout << "width: " << width << std::endl;
					std::cout << "height: " << height << std::endl;
					break;
				}
				break;
			}
		}
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	return 0;
}