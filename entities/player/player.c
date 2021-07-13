#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "../entities.h"

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
    player->frame.y = (float)(player->texture.height / 21) * 14;
    player->frame.width = (float)(player->texture.width / 13);
    player->frame.height = (float)(player->texture.height / 21);

    player->position.x = ((float)GetScreenWidth() / 2) - player->frame.width;
    player->position.y = ((float)GetScreenHeight() / 2) - player->frame.height;

    return player;
}

void set_player_direction(Character *player)
{
    player->direction.x = 0;
    player->direction.y = 0;

    if (IsKeyDown(KEY_RIGHT) && player->position.x < GetScreenWidth() - (int)player->texture.width / 13)
        player->direction.x = 1;
    if (IsKeyDown(KEY_LEFT) && player->position.x > 0)
        player->direction.x = -1;
    if (IsKeyDown(KEY_UP) && player->position.y > 0)
        player->direction.y = -1;
    if (IsKeyDown(KEY_DOWN) && player->position.y < GetScreenHeight() - (int)player->texture.height / 21)
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
            player->frame.y = (float)(player->texture.height / 21) * 11;
            player->frame.x = (float)player->animation.current_frame * (float)player->frame.width;
        }

        if (IsKeyDown(KEY_LEFT))
        {
            player->frame.y = (float)(player->texture.height / 21) * 9;
            player->frame.x = (float)player->animation.current_frame * (float)player->frame.width;
        }

        if (IsKeyDown(KEY_UP))
        {
            player->frame.y = (float)(player->texture.height / 21) * 8;
            player->frame.x = (float)player->animation.current_frame * (float)player->frame.width;
        }

        if (IsKeyDown(KEY_DOWN))
        {
            player->frame.y = (float)(player->texture.height / 21) * 10;
            player->frame.x = (float)player->animation.current_frame * (float)player->frame.width;
        }
    }
}
