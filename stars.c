#include "stars.h"

#define KVADRANT_START               -1
#define KVADRANT_VALUE                2
#define SPEED_SRECISION             100
#define ACCELERATION_PERCENTAGE    0.02
#define BIG_STAR_SIZE                 2
#define SMALL_STAR_SIZE               1
#define STAR_SIZE_BORDER              5
#define STAR_BRITNESS               220
#define STAR_COLOR_RANGE             36
#define BLACK_CIRCLE_RADIUS         110


void init_star(star *new)
{
	new -> x = KVADRANT_START + rand() % KVADRANT_VALUE;
	new -> y = KVADRANT_START + rand() % KVADRANT_VALUE;

	new -> xv = (float)(rand() % SPEED_SRECISION) / SPEED_SRECISION;
	new -> yv = (float)(rand() % SPEED_SRECISION) / SPEED_SRECISION;

	if (new -> x < 0)
		new -> xv = - new -> xv;
		
	if (new -> y < 0)
		new -> yv = - new -> yv;

	new -> xa = new -> xv * ACCELERATION_PERCENTAGE;
	new -> ya = new -> yv * ACCELERATION_PERCENTAGE;
		
	new -> r = BIG_STAR_SIZE;
		
	if (abs( new -> xv * 10 ) <= STAR_SIZE_BORDER && abs( new -> yv * 10 ) <= STAR_SIZE_BORDER)
		new -> r = SMALL_STAR_SIZE;
		
	new -> red = STAR_BRITNESS + rand() % STAR_COLOR_RANGE;
	new -> green = STAR_BRITNESS + rand() % STAR_COLOR_RANGE;
	new -> blue = STAR_BRITNESS + rand() % STAR_COLOR_RANGE;
}


star *create_stars(int count)
{
	star *first_star = NULL;
	star *next = NULL;
	star *current = NULL;

	int index;
	for (index = 0; index < count; current = next, index++)
	{
		next = malloc(sizeof(star));
		next -> next = NULL;

		init_star(next);
		
		if (first_star == NULL)
		{
			first_star = next;
		}
		
		if (current != NULL)
		{
			current->next = next;
		}
	}

	return first_star;
}


void destroy_stars(star *first)
{
	star *t = first;
	star *next = NULL;
	for (; t != NULL; t = next)
	{
		next = t -> next;
		free(t);
	}
}


void move_stars(star *first)
{
	star *t = first;
	for (; t != NULL; t = t -> next)
	{
		t -> xv += t -> xa;
		t -> yv += t -> ya;
		
		t -> xa = t -> xv * ACCELERATION_PERCENTAGE;
		t -> ya = t -> yv * ACCELERATION_PERCENTAGE;

		t -> x += t -> xv;
		t -> y += t -> yv;
		
		if ((t -> x < -SCREEN_W_CENTER || t -> x > SCREEN_W_CENTER) ||
			(t -> y < -SCREEN_H_CENTER || t -> y > SCREEN_H_CENTER))
			{
				init_star(t);
			}
	}
}


void display_stars(star *first)
{
	star *t = first;
	for (; t != NULL; t = t -> next)
	{
		draw_circle(t -> x + SCREEN_W_CENTER, t -> y + SCREEN_H_CENTER, t -> r,
										al_map_rgb(t -> red, t -> green, t -> blue));
	}
	
	draw_circle(SCREEN_W_CENTER, SCREEN_H_CENTER, BLACK_CIRCLE_RADIUS, al_map_rgb(0, 0, 0));
	
	al_flip_display();
}


void erase_stars(star *first)
{
	star *t = first;
	for (; t != NULL; t = t -> next)
	{
		clear_circle(t -> x + SCREEN_W_CENTER, t -> y + SCREEN_H_CENTER, t -> r);
	}
}
