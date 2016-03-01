#ifndef KB_H
#define KB_H

#include <allegro5/allegro.h>

#define KEY_UP 0
#define KEY_DOWN 1
#define KEY_LEFT 2
#define KEY_RIGHT 3
#define KEY_ESCAPE 4

int get_keystate(int key);
void update_keystate_table();

#endif
