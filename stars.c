#include "stars.h"

void init_star(star *new)
{
	new -> x = -1 + rand() % 2;
	new -> y = -1 + rand() % 2;

	new -> xv = (float)(rand() % 100) / 100;
	new -> yv = (float)(rand() % 100) / 100;

	if (new -> x < 0)
		new -> xv = - new -> xv;
		
	if (new -> y < 0)
		new -> yv = - new -> yv;

	new -> xa = new -> xv * 0.02;
	new -> ya = new -> yv * 0.02;
		
	new -> r = 2;
		
	if (abs( new -> xv * 10 ) <= 5 && abs( new -> yv * 10 ) <= 5)
		new -> r = 1;
		
	new -> red = 220 + rand() % 36;
	new -> green = 220 + rand() % 36;
	new -> blue = 220 + rand() % 36;
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
		
		t -> xa = t -> xv * 0.02;
		t -> ya = t -> yv * 0.02;

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
	
	draw_circle(SCREEN_W_CENTER, SCREEN_H_CENTER, 110, al_map_rgb(0, 0, 0));
	
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
