#include <stdio.h>
#include "raylib.h"
#include "window.h"


Color BACKGROUND_COLOR = (Color) {0x4d, 0xa6, 0xa8, 0xff};


Window test = {
    .posX = 20,
    .posY = 100,
    .width = 350,
    .height = 200,
    .title = "my cool window"
};

Window test2 = {
    .posX = 400,
    .posY = 500,
    .width = 300,
    .height = 85,
    .title = "super different window"
};


int main(void)
{
    InitWindow(800, 600, "Test window");

    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BACKGROUND_COLOR);

            DrawWindow(&test);
            DrawWindow(&test2);

        EndDrawing();
    }

    CloseWindow();


    return 0;
}
