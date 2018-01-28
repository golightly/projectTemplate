#pragma once

struct Position {
	int rgbaIndex, x, y;
};

struct Sprite {
	float** rgba;
	Position** position; /*a rectangle: index of rgba value (-1 means not part of the image)
					x relative to xOrigin, y relative to yOrigin. use the rotated
					attributes to navigate through array*/
	bool rotate;
	int angle, xOrigin, yOrigin, width, height, layer, positionSize;
	//add stuff for retrieving from hard drive, ie. start location in file and size
};

void setupSprite(Sprite &sprite, int xo, int yo, int ang);