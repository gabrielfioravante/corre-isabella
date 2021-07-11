#include "raylib.h"
#include"stdlib.h"
#include "entities/entities.h"

int main()
{
    // Initialization
    const int screenWidth = 922;
    const int screenHeight = 519;

    InitWindow(screenWidth, screenHeight, "Corre, Isabella!");

    Character * player = load_player();

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        move_character(player, set_player_direction(player));
        animate_player(player, 60);

        BeginDrawing();
        DrawFPS(10, 10);
        draw_character(player);
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    
    unload_character(player);
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
