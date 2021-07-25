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
    game_screen current_screen = INTRO;

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
                if(IsKeyPressed(KEY_ENTER)) 
                {
                    current_screen = GAMEPLAY;
                }
                break;
            case GAMEPLAY:
                update_gameplay();
                if(gameplay_should_end()) current_screen = ENDING;
                break;
            case ENDING:
                if(IsKeyPressed(KEY_ENTER)) 
                {
                    reset_gameplay();
                    current_screen = GAMEPLAY;
                }
                break;
        }

        // Draw
        BeginDrawing();
        DrawFPS(10, 10);

        switch (current_screen)
        {
            case INTRO:
                draw_intro();
                break;
            case GAMEPLAY:
                draw_gameplay();
                break;
            case ENDING:
                draw_ending();
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
