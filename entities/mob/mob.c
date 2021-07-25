#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "../entities.h"
#include "../../utils/utils.h"

#define MOB_BOX_SIZE 64.0

void set_mob_position_to_initial(Character *mob)
{
    mob->position.x = ((float)GetScreenWidth() / 2) - MOB_BOX_SIZE;
    mob->position.y = GetScreenHeight() - MOB_BOX_SIZE;
}

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

    set_mob_position_to_initial(mob);

    return mob;
}

static void set_mob_horizontal_direction(Character *mob, Vector2 target_position)
{
    if(target_position.x > mob->position.x)
    {
        mob->direction.x = 1;
    }
    else if (target_position.x < mob->position.x)
    {
        mob->direction.x = -1;
    }
    
    mob->direction.y = 0;
}

static void set_mob_vertical_direction(Character *mob, Vector2 target_position)
{
    if(target_position.y > mob->position.y)
    {
    mob->direction.y = 1;
    }
    else if (target_position.y < mob->position.y)
    {
    mob->direction.y = -1;
    }

    mob->direction.x = 0;
}

static void animate_mob(Character *mob, int FPS)
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

static void change_mob_direction_over_time(Character *mob, Vector2 target_position)
{
    static int frames_counter = 0;
    if (frames_counter > 20)
    {
        generate_random_int(1, 0) == 1 ? set_mob_horizontal_direction(mob, target_position) : set_mob_vertical_direction(mob, target_position);   
        frames_counter = 0;
    }
    else
    {
        frames_counter++;
    }
}

void mob_movement(Character *mob, Vector2 target_position)
{
    change_mob_direction_over_time(mob, target_position);
    animate_mob(mob, 60);
    move_character(mob);
}
