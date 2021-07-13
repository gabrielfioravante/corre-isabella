#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "entities/entities.h"
#include "screens/screens.h"

#define MAX_BATCH_ELEMENTS  5000

int main()
{
    srand(time(NULL));

    // Initialization
    const int screenWidth = 922;
    const int screenHeight = 519;

    InitWindow(screenWidth, screenHeight, "Corre, Isabella!");

    init_characters();

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        move_characters();

        BeginDrawing();

        DrawFPS(10, 10);
        draw_characters();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

//    unload_character(player);
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
