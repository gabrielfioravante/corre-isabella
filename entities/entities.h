#ifndef ENTITIES_H
#define ENTITIES_H

#include "raylib.h"

// Character
typedef struct Animation
{
    int current_frame;
    int frames_counter;
    int frame_speed;
} Animation;

typedef struct Character
{
    Texture2D texture;
    Vector2 position;
    Vector2 direction;
    Rectangle frame;
    Animation animation;
} Character;

void draw_character(Character *character);
void move_character(Character *character);
void unload_character(Character *character);

// Player
Character *load_player(void);
void set_player_direction(Character *player);
void animate_player(Character *player, int FPS);
void assemble_player_movement(Character *player);

// Mob
Character *load_mob(void);
void set_mob_direction(Character *mob);
void animate_mob(Character *mob, int FPS);
void change_mob_direction_over_time(Character *mob);
void assemble_mob_movement(Character *mob);

// Collision
bool are_characters_colliding(Character *player, Character *mob);
#endif
