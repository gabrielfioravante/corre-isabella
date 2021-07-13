#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "../entities.h"

#define PLAYER_BOX_SIZE 64.0

Character *load_player(void)
{
    Character *player = (Character *)malloc(sizeof(Character));

    player->texture = LoadTexture("./resources/player.png");

    player->animation.current_frame = 0;
    player->animation.frames_counter = 0;
    player->animation.frame_speed = 10;

    player->direction.x = 0;
    player->direction.y = 0;

    player->frame.x = 0.0f;
    player->frame.y = PLAYER_BOX_SIZE * 14;
    player->frame.width = PLAYER_BOX_SIZE;
    player->frame.height = PLAYER_BOX_SIZE;

    player->position.x = ((float)GetScreenWidth() / 2) - PLAYER_BOX_SIZE;
    player->position.y = ((float)GetScreenHeight() / 2) - PLAYER_BOX_SIZE;

    return player;
}

void set_player_direction(Character *player)
{
    player->direction.x = 0;
    player->direction.y = 0;

    if (IsKeyDown(KEY_RIGHT) && player->position.x < GetScreenWidth() - PLAYER_BOX_SIZE)
        player->direction.x = 1;
    if (IsKeyDown(KEY_LEFT) && player->position.x > 0)
        player->direction.x = -1;
    if (IsKeyDown(KEY_UP) && player->position.y > 0)
        player->direction.y = -1;
    if (IsKeyDown(KEY_DOWN) && player->position.y < GetScreenHeight() - PLAYER_BOX_SIZE)
        player->direction.y = 1;
}

void animate_player(Character *player, int FPS)
{
    player->animation.frames_counter++;

    if (player->animation.frames_counter >= (FPS / player->animation.frame_speed))
    {
        player->animation.frames_counter = 0;
        player->animation.current_frame++;

        if (player->animation.current_frame == 7)
            player->animation.current_frame = 0;

        if (IsKeyDown(KEY_RIGHT))
        {
            player->frame.y = PLAYER_BOX_SIZE * 11;
            player->frame.x = (float)player->animation.current_frame * PLAYER_BOX_SIZE;
        }

        if (IsKeyDown(KEY_LEFT))
        {
            player->frame.y = PLAYER_BOX_SIZE * 9;
            player->frame.x = (float)player->animation.current_frame * PLAYER_BOX_SIZE;
        }

        if (IsKeyDown(KEY_UP))
        {
            player->frame.y = PLAYER_BOX_SIZE * 8;
            player->frame.x = (float)player->animation.current_frame * PLAYER_BOX_SIZE;
        }

        if (IsKeyDown(KEY_DOWN))
        {
            player->frame.y = PLAYER_BOX_SIZE * 10;
            player->frame.x = (float)player->animation.current_frame * PLAYER_BOX_SIZE;
        }
    }
}
