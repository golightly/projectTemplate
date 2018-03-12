#include "render.h"
#include <SDL.h>
#include "overhead.h"
#include "texture.h"
#include "sprite.h"
#include "editor.h"

void render(Editor &editor,Overhead &overhead Texture &texture, Sprite &sprite) {
    int x = sprite.attributes.x - editor.cameraX;
    int y = sprite.attributes.y - editor.cameraY;
    SDL_Rect renderQuad = { x, y, sprite.attributes.w, sprite.attributes.h };
    SDL_Rect sourceQuad = { 0, 0, texture.w[sprite.textureIndex], texture.h[sprite.textureIndex] };
    SDL_RenderCopy(overhead, renderer, texture.texture[sprite.textureIndex], &sourceQuad, &renderQuad);
}

//repurpose this one for ui
//renders one sprite per function call
void render(Overhead &overhead, Texture &texture, Sprite &sprite) {
    SDL_Rect renderQuad = { sprite.attributes.x, sprite.attributes.y, sprite.attributes.w, sprite.attributes.h };
    SDL_RenderCopy(overhead.renderer, texture.texture[sprite.textureIndex], &overhead.attributes, &renderQuad);
}
