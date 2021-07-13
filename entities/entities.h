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

// Mob
Character *load_mob(void);
void mob_ai(Character *mob);
void set_mob_direction(Character *mob);
void animate_mob(Character *mob, int FPS);

// Collision
bool is_mob_colliding(Character *player, Character *mob);
#endif
