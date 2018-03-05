#include "render.h"
#include <SDL.h>
#include "overhead.h"
#include "texture.h"
#include "sprite.h"
#include "editor.h"

//renders one sprite per function call
void render(Editor &editor, Overhead &overhead, Texture &texture, Sprite &sprite) {
    int x = sprite.attributes.x - editor.cameraX;
    int y = sprite.attributes.y - editor.cameraY;
    SDL_Rect renderQuad = { x, y, sprite.attributes.w, sprite.attributes.h };
    SDL_RenderCopy(overhead.renderer, texture.texture[sprite.textureIndex], &overhead.attributes, &renderQuad);
}
