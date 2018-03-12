#include "render.h"
#include <SDL.h>
#include "overhead.h"
#include "texture.h"
#include "sprite.h"

//renders one sprite per function call
void render(Overhead &overhead, Texture &texture, Sprite &sprite) {
    SDL_Rect renderQuad = { sprite.attributes.x, sprite.attributes.y, sprite.attributes.w, sprite.attributes.h };
    SDL_RenderCopy(overhead.renderer, texture.texture[sprite.textureIndex], &overhead.attributes, &renderQuad);
}