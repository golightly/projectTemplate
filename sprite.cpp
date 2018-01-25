#include <math.h>
#include "sprite.h"
void setupSprite(Sprite &sprite, int xo, int yo, int ang) {
	sprite.angle = ang;
	sprite.xOrigin = xo;
	sprite.yOrigin = yo;
	//temp code, will get data from hard drive later
	sprite.width = 800;
	sprite.height = 600;
	sprite.rgba = new float*[sprite.width * sprite.height];
	for (int a = 0; a < sprite.width; ++a) {
		sprite.rgba[a] = new float[4];
		for (int b = 0; b < 4; ) {
			sprite.rgba[a][b] = 0.5f;
			++b;
			sprite.rgba[a][b] = 0.7f;
			++b;
			sprite.rgba[a][b] = 0.1f;
			++b;
			sprite.rgba[a][b] = 1.0f;
		}
	}
	if (sprite.angle != 0) {
		sprite.position = new Position*[(int)sqrt((sprite.width * 2) + (sprite.height * 2))];
		for (int a = 0; a < (int)sqrt((sprite.width * 2) + (sprite.height * 2)); ++a) {
			sprite.position[a] = new Position[(int)sqrt((sprite.width * 2) + (sprite.height * 2))];
		}
		//calculate rotated position of every pixel in rgba and place them in position
	}
}
