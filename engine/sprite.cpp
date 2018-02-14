#include "sprite.h"

void setupSprite(Sprite &sprite, int w, int h, int x, int y, int textureIndex) {
    sprite.textureIndex = textureIndex;
    sprite.attributes.w = w; sprite.attributes.h = h; 
    sprite.attributes.x = x; sprite.attributes.y = y;
}