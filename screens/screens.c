#include "../entities/entities.h"
#include "screens.h"
#include <stdlib.h>

static const int MOB_QUANTITY = 7;

Character *player;
Character **mob;

void init_characters(void)
{
    player = load_player();
    mob = (Character **)malloc((float)(MOB_QUANTITY) * sizeof(Character));

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        *(mob + i) = load_mob();
    }
}

void move_characters(void)
{
    assemble_player_movement(player);

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        assemble_mob_movement(*(mob + i));
    }

}

void draw_characters(void)
{
    draw_character(player);

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        draw_character(*(mob + i));
    }
}
