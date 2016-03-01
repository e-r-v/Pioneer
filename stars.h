#ifndef STARS_H
#define STARS_H

#include "main.h"

typedef struct star_type
{
	float x, y;
	float xv, yv;
	float xa, ya;
	int r;
	
	float red, green, blue;
	
	struct star_type *next;
} star;


star *create_stars(int count);

void destroy_stars(star *first);

void move_stars(star *first);

void display_stars(star *first);

void erase_stars(star *first);

#endif
