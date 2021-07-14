#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "../entities.h"
#include "../../utils/utils.h"

#define MOB_BOX_SIZE 64.0

Character *load_mob(void)
{
    Character *mob = (Character *)malloc(sizeof(Character));

    mob->texture = LoadTexture("./resources/mob.png");

    mob->animation.current_frame = 0;
    mob->animation.frames_counter = 0;
    mob->animation.frame_speed = 10;

    mob->direction.x = 0;
    mob->direction.y = 0;

    mob->frame.x = 0.0f;
    mob->frame.y = MOB_BOX_SIZE * 14;
    mob->frame.width = MOB_BOX_SIZE;
    mob->frame.height = MOB_BOX_SIZE;

    mob->position.x = generate_random_int((GetScreenWidth() - MOB_BOX_SIZE), MOB_BOX_SIZE);
    mob->position.y = generate_random_int((GetScreenHeight() - MOB_BOX_SIZE), MOB_BOX_SIZE);
    return mob;
}

void set_mob_direction(Character *mob)
{
    if (mob->position.x <= MOB_BOX_SIZE * 2 || mob->position.x >= (float)GetScreenWidth() - (MOB_BOX_SIZE * 2))
    {
        mob->direction.x = mob->direction.x * -1;
    }
    else
    {
        mob->direction.x = generate_random_int(1, -1);
    }

    if (mob->position.y <= MOB_BOX_SIZE * 2 || mob->position.y >= (float)GetScreenHeight() - (MOB_BOX_SIZE * 2))
    {
        mob->direction.y = mob->direction.y * -1;
    }
    else
    {
        mob->direction.y = generate_random_int(1, -1);
    }
}

void animate_mob(Character *mob, int FPS)
{
    mob->animation.frames_counter++;

    if (mob->animation.frames_counter >= (FPS / mob->animation.frame_speed))
    {
        mob->animation.frames_counter = 0;
        mob->animation.current_frame++;

        if (mob->animation.current_frame == 7)
            mob->animation.current_frame = 0;

        if (mob->direction.x > 0)
        {
            mob->frame.y = MOB_BOX_SIZE * 11;
            mob->frame.x = (float)mob->animation.current_frame * MOB_BOX_SIZE;
        }

        if (mob->direction.x < 0)
        {
            mob->frame.y = MOB_BOX_SIZE * 9;
            mob->frame.x = (float)mob->animation.current_frame * MOB_BOX_SIZE;
        }

        if (mob->direction.y < 0)
        {
            mob->frame.y = MOB_BOX_SIZE * 8;
            mob->frame.x = (float)mob->animation.current_frame * MOB_BOX_SIZE;
        }

        if (mob->direction.y > 0)
        {
            mob->frame.y = MOB_BOX_SIZE * 10;
            mob->frame.x = (float)mob->animation.current_frame * MOB_BOX_SIZE;
        }
    }
}

void change_mob_direction_over_time(Character *mob)
{
    static int frames_counter = 0;

    if (frames_counter > 60)
    {
        set_mob_direction(mob);
        frames_counter = 0;
    }
    else
    {
        frames_counter++;
    }
}

void assemble_mob_movement(Character *mob)
{
    change_mob_direction_over_time(mob);
    animate_mob(mob, 60);
    move_character(mob);
}
