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
    const int screenWidth = 1024;
    const int screenHeight = 576;
    game_screen current_screen = GAMEPLAY;

    InitWindow(screenWidth, screenHeight, "Corre, Isabella!");
    init_gameplay();

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
                update_gameplay();
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
                draw_gameplay();
                break;
            case ENDING:
                DrawText("Você não correu o bastante! :(", 220, GetScreenHeight() / 2, 30, RED);
                break;
        }

        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    // De-Initialization
    unload_gameplay();
    CloseWindow();

    return 0;
}
