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
void set_player_position_to_initial(Character *player);

// Player
Character *load_player(void);
void player_movement(Character *player);

// Mob
Character *load_mob(void);
void mob_movement(Character *mob, Vector2 target_position);
void set_mob_position_to_initial(Character *mob);

// Collision
bool are_characters_colliding(Character *player, Character *mob);

// Background
Texture2D load_background(const char* file_path);
void unload_background(Texture2D background);
#endif
