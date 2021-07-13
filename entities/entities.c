#include <stdlib.h>
#include <stdio.h>
#include "entities.h"
#include "raylib.h"
#include <math.h>

void unload_character(Character *character)
{
    UnloadTexture(character->texture);
    free(character);
}

void draw_character(Character *character)
{
    DrawTextureRec(character->texture, character->frame, character->position, WHITE);
}

void move_character(Character *character)
{
    float speed = 3.0f;
    float vector_magnitude = sqrt(pow(speed * character->direction.x, 2) +
                                  pow(speed * character->direction.y, 2));

    if (character->direction.x != 0 && character->direction.y != 0)
    {
        character->position.x += character->direction.x * (speed * speed / vector_magnitude);
        character->position.y += character->direction.y * (speed * speed / vector_magnitude);
    }
    else
    {
        character->position.x += character->direction.x * speed;
        character->position.y += character->direction.y * speed;
    }
}

