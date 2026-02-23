#ifndef WINDOW_H
#define WINDOW_H

#include <raylib.h>



typedef struct Window
{
    char title[256];
    int posX;
    int posY;
    int width;
    int height;
} Window;


void DrawWindow(Window* window);


#endif //WINDOW_H
