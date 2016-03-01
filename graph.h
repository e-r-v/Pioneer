#ifndef GRAPH_H
#define GRAPH_H 

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

void init_graphics(ALLEGRO_DISPLAY *display, int width, int height);
void destroy_graphics(ALLEGRO_DISPLAY *display);
void draw_circle(float x, float y, int r, ALLEGRO_COLOR color);
void clear_circle(float x, float y, int r);

#endif
