#include <stdio.h>

#include "LL.h"
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


    LL* windowList = LL_init();

    LL_append(windowList, &test);
    LL_append(windowList, &test2);

    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BACKGROUND_COLOR);


            LLNode* windowNode = windowList->head;
            while(windowNode != NULL)
            {
                Window* window = windowNode->obj;
                DrawWindow(window);

                windowNode = windowNode->next;
            }

            // DrawWindow(&test);
            // DrawWindow(&test2);

        EndDrawing();
    }

    CloseWindow();

    LL_destroy(windowList);

    return 0;
}
