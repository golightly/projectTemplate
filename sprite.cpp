#include <math.h>
#include "sprite.h"
void setupSprite(Sprite &sprite, int xo, int yo, int ang, bool rot) {
	sprite.angle = ang;
	sprite.xOrigin = xo;
	sprite.yOrigin = yo;
	sprite.rotate = rot;
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
	if (sprite.rotate) {
		sprite.positionSize = (int)sqrt((sprite.width * 2) + (sprite.height * 2));
		if (sprite.positionSize % 2 == 0)
			++sprite.positionSize;
		sprite.position = new Position*[sprite.positionSize];
		for (int a = 0; a < sprite.positionSize; ++a) {
			sprite.position[a] = new Position[sprite.positionSize];
		}
		//calculate rotated position of every pixel in rgba and place them in position
	}
}
