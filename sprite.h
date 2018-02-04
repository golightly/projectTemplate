#pragma once

struct Point {
	int x, y;
};

struct Position {
	int rgbaIndex;
	Point point;
};

struct Sprite {
	float** rgba;
	Position** position; /*a rectangle: index of rgba value (-1 means not part of the image)
					x relative to xOrigin, y relative to yOrigin. use the rotated
					attributes to navigate through array*/
	Point rOrigin, origin;
	bool rotate;
	int width, height, layer, positionSpan;
	double angle;
	//add stuff for retrieving from hard drive, ie. start location in file and size
};

void setupSprite(Sprite &sprite, int xo, int yo, int ang, bool rot, int lay);

void rotateSprite(Sprite &sprite);