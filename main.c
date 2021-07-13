#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "entities/entities.h"

#define MAX_BATCH_ELEMENTS  5000

int main()
{
    srand(time(NULL));
    // Initialization
    const int screenWidth = 922;
    const int screenHeight = 519;
    const int MOB_QUANTITY = 7;

    InitWindow(screenWidth, screenHeight, "Corre, Isabella!");

    Character *player = load_player();
    Character **mob = (Character **)malloc((float)(MOB_QUANTITY) * sizeof(Character));

    for (int i = 0; i < MOB_QUANTITY; i++)
    {
        printf("%d ", i);
        *(mob + i) = load_mob();
    }

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        set_player_direction(player);
        move_character(player);
        animate_player(player, 60);

        for (int i = 0; i < MOB_QUANTITY; i++)
        {
            mob_ai(*(mob + i));
        }

        // if (is_mob_colliding(player, mob[0]))
        // {
        //     printf("col");
        // }

        BeginDrawing();
        DrawFPS(10, 10);
        draw_character(player);

        for (int i = 0; i < MOB_QUANTITY; i++)
        {
            draw_character(*(mob + i));
        }

        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    unload_character(player);
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
