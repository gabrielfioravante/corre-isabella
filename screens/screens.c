#include "../entities/entities.h"
#include "screens.h"
#include <stdlib.h>

static const int MOB_QUANTITY = 1;

Character *player;
Character **mob;
Texture2D background;

// INTRO
void draw_intro(void)
{
    DrawTexture(background, 0, 0, RAYWHITE);
    DrawText("Corre, Isabella!", 280, GetScreenHeight() / 2.2, 60, PINK);
    DrawText("Pressione ENTER para iniciar ou ESC para sair.", 310, GetScreenHeight() / 1.75, 18, PINK);
}

// GAMEPLAY
void init_gameplay(void)
{
    background = load_background("resources/gameplay-bg.png");
    player = load_player();
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
    draw_character(player);

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        draw_character(*(mob + i));
    }
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

        return false;
}

// ENDING
void draw_ending(void)
{
    DrawTexture(background, 0, 0, RAYWHITE);
    DrawText("Você não correu o bastante! :(", 200, GetScreenHeight() / 2.2, 40, PINK);
    DrawText("Pressione ENTER para jogar novamente", 310, GetScreenHeight() / 1.8, 20, PINK);
}
