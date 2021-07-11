#include <stdlib.h> 
#include "raylib.h"
#include "../entities.h"

Character * load_player(void)
{
    Character * player = (Character *) malloc(sizeof(Character));

    player->texture = LoadTexture("./resources/player.png");

    player->frame.x = 0.0f;
    player->frame.y = (float) (player->texture.height/21) * 14; 
    player->frame.width = (float) (player->texture.width/13);
    player->frame.height = (float) (player->texture.height/21); 

    player->position.x = ((float) GetScreenWidth() / 2) - player->frame.width;
    player->position.y = ((float) GetScreenHeight() / 2) - player->frame.height;

    return player;
}

Vector2 set_player_direction(Character * player)
{
    Vector2 player_direction = {0, 0};

    if (IsKeyDown(KEY_RIGHT) && player->position.x <  GetScreenWidth() - (int) player->texture.width/13) player_direction.x = 1;
    if (IsKeyDown(KEY_LEFT) && player->position.x > 0) player_direction.x = -1;
    if (IsKeyDown(KEY_UP) && player->position.y > 0) player_direction.y = -1;
    if (IsKeyDown(KEY_DOWN) && player->position.y <  GetScreenHeight() - (int) player->texture.height/21) player_direction.y = 1;

    return player_direction;
}

void animate_player(Character * player, int FPS)
{
    static int current_frame = 0;
    static int frames_counter = 0;
    static int frame_speed = 10;

    frames_counter++;

    if(frames_counter >= (FPS/frame_speed))
    {
        frames_counter = 0;
        current_frame++;

        if(current_frame == 7) current_frame = 0;

        if (IsKeyDown(KEY_RIGHT)) {
            player->frame.y = (float) (player->texture.height/21) * 11; 
            player->frame.x = (float)current_frame*(float)player->frame.width;
        }

        if (IsKeyDown(KEY_LEFT)) {
            player->frame.y = (float) (player->texture.height/21) * 9; 
            player->frame.x = (float)current_frame*(float)player->frame.width;
        }

        if (IsKeyDown(KEY_UP)) {
            player->frame.y = (float) (player->texture.height/21) * 8; 
            player->frame.x = (float)current_frame*(float)player->frame.width;
        }

        if (IsKeyDown(KEY_DOWN)) {
            player->frame.y = (float) (player->texture.height/21) * 10; 
            player->frame.x = (float)current_frame*(float)player->frame.width;
        }
    }
}
