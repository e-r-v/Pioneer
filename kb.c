#include "kb.h"

ALLEGRO_KEYBOARD_STATE keyboard;

static int keystate[5] = {0, 0, 0, 0, 0};

int get_keystate(int key)
{
   return keystate[key];
}

void reset_keystate_table()
{
   keystate[KEY_UP] = 0;
   keystate[KEY_DOWN] = 0;
   keystate[KEY_LEFT] = 0;
   keystate[KEY_RIGHT] = 0;
   keystate[KEY_ESCAPE] = 0;
}

void update_keystate_table()
{
   al_get_keyboard_state(&keyboard);

   reset_keystate_table(keystate);

   if (al_key_down(&keyboard, ALLEGRO_KEY_UP))
      keystate[KEY_UP] = 1;

   if (al_key_down(&keyboard, ALLEGRO_KEY_DOWN))
      keystate[KEY_DOWN] = 1;

   if (al_key_down(&keyboard, ALLEGRO_KEY_LEFT))
      keystate[KEY_LEFT] = 1;

   if (al_key_down(&keyboard, ALLEGRO_KEY_RIGHT))
      keystate[KEY_RIGHT] = 1;

   if (al_key_down(&keyboard, ALLEGRO_KEY_ESCAPE))
      keystate[KEY_ESCAPE] = 1;
}
