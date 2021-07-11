#include <stdlib.h>
#include <stdio.h>
#include "entities.h"
#include "raylib.h"
#include <math.h>

void unload_character(Character * character)
{
    UnloadTexture(character->texture);
    free(character);
}

void draw_character(Character * character)
{
    DrawTextureRec(character->texture, character->frame, character->position, WHITE); 
}

void move_character(Character * character, Vector2 character_direction)
{
    float speed = 3.0f;
    float vector_magnitude = sqrt(pow(speed * character_direction.x, 2) +
                                  pow(speed * character_direction.y, 2));

    if(character_direction.x != 0 && character_direction.y != 0) {
        character->position.x += character_direction.x * (speed * speed/vector_magnitude);
        character->position.y += character_direction.y * (speed * speed/vector_magnitude);
    } else {
        character->position.x += character_direction.x * speed;
        character->position.y += character_direction.y * speed;
    }
}
