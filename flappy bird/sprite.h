#pragma once

struct Point {
	int x, y;
};

struct Sprite {
	float** rgba;
	Point** position; /*a rectangle: x relative to positionOrigin, 
					  y relative to positionOrigin. each pixel is in the same [a][b] index
					  as in the image, and contains the rotated position*/
	Point rOrigin, origin, positionOrigin;
	bool rotate;
	int width, height, layer, positionSpan;
	double angle;
	//add stuff for retrieving from hard drive, ie. start location in file and size
};

void setupSprite(Sprite &sprite, int xo, int yo, int ang, bool rot, int lay);

void rotateSprite(Sprite &sprite);