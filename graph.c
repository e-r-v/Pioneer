#include "graph.h"

void init_graphics(ALLEGRO_DISPLAY *display, int width, int height)
{
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return;
	}

	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to install keyboard!\n");
		return;
	}

	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

	display = al_create_display(width, height);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		return;
	}

	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "failed to init primitives addon!\n");
		return;
	}

	if (!al_init_image_addon())
	{
		fprintf(stderr, "failed to init image addon!\n");
		return;
	}
}

void destroy_graphics(ALLEGRO_DISPLAY *display)
{
	al_destroy_display(display);
}

void draw_circle(float x, float y, int r, ALLEGRO_COLOR color)
{
	al_draw_filled_circle(x, y, r, color);
}

void clear_circle(float x, float y, int r)
{
	draw_circle(x, y, r, al_map_rgb(0, 0, 0));
}
