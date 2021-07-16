#include "../entities/entities.h"
#include "screens.h"
#include <stdlib.h>

static const int MOB_QUANTITY = 7;

Character *player;
Character **mob;

void init_gameplay(void)
{
    player = load_player();
    mob = (Character **)malloc((float)(MOB_QUANTITY) * sizeof(Character));

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        *(mob + i) = load_mob();
    }
}

void update_gameplay(void)
{
    assemble_player_movement(player);

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        assemble_mob_movement(*(mob + i));
    }

}

void draw_gameplay(void)
{
    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        draw_character(*(mob + i));
    }

    draw_character(player);
}

void unload_gameplay(void)
{
    unload_character(player);

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

    return collision_count >= COLLISION_LIMIT;
}
