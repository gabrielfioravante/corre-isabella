#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "entities/entities.h"
#include "screens/screens.h"

#define MAX_BATCH_ELEMENTS  5000

typedef enum game_screen { INTRO, GAMEPLAY, ENDING } game_screen;

int main()
{
    srand(time(NULL));

    // Initialization
    const int screenWidth = 922;
    const int screenHeight = 519;
    game_screen current_screen = GAMEPLAY;

    InitWindow(screenWidth, screenHeight, "Corre, Isabella!");
    init_characters();

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        switch (current_screen)
        {
            case INTRO:
                break;
            case GAMEPLAY:
                move_characters();
                if(gameplay_should_end()) current_screen = ENDING;
                break;
            case ENDING:
                break;
        }

        // Draw
        BeginDrawing();
        DrawFPS(10, 10);

        switch (current_screen)
        {
            case INTRO:
                break;
            case GAMEPLAY:
                draw_characters();
                break;
            case ENDING:
                DrawText("Você não correu o bastante! :(", 220, GetScreenHeight() / 2, 30, RED);
                break;
        }

        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    // De-Initialization
    unload_characters();
    CloseWindow();

    return 0;
}
