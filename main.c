#include "main.h"

void main ( void )
{
	ALLEGRO_DISPLAY *display = NULL;

	init_graphics(display, SCREEN_WIDTH, SCREEN_HEIGHT);

	star *star_list = create_stars(NUM_STARS);
	
	initializeTimer();
	
	while (!get_keystate(KEY_ESCAPE))
	{
		erase_stars(star_list);

		move_stars(star_list);

		display_stars(star_list);

		update_keystate_table();
		
		delayTimer(FRAMES40);
	}
	
	destroy_stars(star_list);

	destroy_graphics(display);
}
