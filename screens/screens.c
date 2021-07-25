#include "../entities/entities.h"
#include "screens.h"
#include <stdlib.h>

static const int MOB_QUANTITY = 1;

Character *player;
Character **mob;
Texture2D background;

// GAMEPLAY
void init_gameplay(void)
{
    player = load_player();
    background = load_background("resources/gameplay-bg.png");
    mob = (Character **)malloc((float)(MOB_QUANTITY) * sizeof(Character));

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        *(mob + i) = load_mob();
    }
}

void update_gameplay(void)
{
    player_movement(player);

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        mob_movement(*(mob + i), player->position);
    }

}

void reset_gameplay(void)
{
    set_player_position_to_initial(player);

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        set_mob_position_to_initial(*(mob + i));
    }
}

void draw_gameplay(void)
{
    DrawTexture(background, 0, 0, RAYWHITE);

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        draw_character(*(mob + i));
    }

    draw_character(player);
}

void unload_gameplay(void)
{
    unload_character(player);
    unload_background(background);

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        unload_character(*(mob + i));
    }
}

bool gameplay_should_end(void)
{
    static int collision_count = 0;
    const int COLLISION_LIMIT = 10;

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        if(are_characters_colliding(player, *(mob + i)))
            collision_count++;
    }

    if(collision_count >= COLLISION_LIMIT)
    {
        collision_count = 0;
        return true;
    }
    else
    { 
        return false;
    }
}

// ENDING
void draw_ending(void)
{
    DrawTexture(background, 0, 0, RAYWHITE);
    DrawText("Você não correu o bastante! :(", 280, GetScreenHeight() / 2.2, 30, RED);
}
