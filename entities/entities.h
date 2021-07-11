#ifndef ENTITIES_H
#define ENTITIES_H

#include "raylib.h"

// Character
typedef struct Character
{
    Texture2D texture;
    Vector2 position;
    Rectangle frame; 
} Character;

void draw_character(Character * character);
void move_character(Character * character, Vector2 character_direction);
void unload_character(Character * character);

// Player
Character * load_player(void);
Vector2 set_player_direction(Character * player);
void animate_player(Character * player, int FPS);

// mob
//Character * load_mob(void);
#endif
