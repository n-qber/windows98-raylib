//
// Created by Nicolas on 2/23/2026.
//
#include "window.h"
#include "raylib.h"

int WINDOW_HEADER_SIZE = 30;
int WINDOW_PADDING = 4;

Color WINDOW_BG_COLOR = (Color) {0xd3, 0xd3, 0xd3, 0xff};
Color WINDOW_HEADER_BG_COLOR = (Color) {0x4d, 0x4d, 0xa6, 0xff};


void DrawShadyRectangle(int posX, int posY, int width, int height, Color color, int upper, int right, int bottom)
{
    Color light = ColorBrightness(color, 0.7f);
    Color dark = ColorBrightness(color, -0.5f);
    DrawRectangle(posX, posY, width, height, color);

    // upper
    DrawRectangle(posX, posY, width, upper, light);

    // bottom
    DrawRectangle(posX, posY + height - bottom, width, bottom, dark);

    // right
    DrawRectangle(posX + width - right, posY, right, height, dark);



}

void DrawWindow(Window* window)
{
    // background rectangle
    int fullHeight = window->height + WINDOW_HEADER_SIZE;
    DrawShadyRectangle(window->posX, window->posY, window->width, fullHeight, WINDOW_BG_COLOR, 1, 2, 2);

    // header rectangle
    DrawShadyRectangle(window->posX + WINDOW_PADDING, window->posY + WINDOW_PADDING, window->width - 2*WINDOW_PADDING, WINDOW_HEADER_SIZE - 2*WINDOW_PADDING, WINDOW_HEADER_BG_COLOR, 1, 2, 2);

    // title
    int fontSize = 14;
    Vector2 windowTitleSize = MeasureTextEx(GetFontDefault(), window->title, fontSize, 1.0f);
    int textPadding = (WINDOW_HEADER_SIZE - 2*WINDOW_PADDING - (int) windowTitleSize.y) / 2;
    DrawText(window->title, window->posX + WINDOW_PADDING + textPadding, window -> posY + WINDOW_PADDING + textPadding, fontSize, WHITE);


    // minize, maximize, quit header buttons
    int btnPadding = 3;
    int btnSize = WINDOW_HEADER_SIZE - 2*WINDOW_PADDING - 2*btnPadding;

    int betweenBtnPadding = 3;
    DrawShadyRectangle(window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize, window->posY + WINDOW_PADDING + btnPadding, btnSize, btnSize, WINDOW_BG_COLOR, 1, 1, 1);

    // draw cross
    int btnIconPadding = 3;
    DrawLine(window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize + btnIconPadding, window->posY + WINDOW_PADDING + btnPadding + btnIconPadding, window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize - btnIconPadding + btnSize, window->posY + WINDOW_PADDING + btnPadding - btnIconPadding + btnSize, BLACK);
    DrawLine(window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize + btnIconPadding, window->posY + WINDOW_PADDING + btnPadding - btnIconPadding + btnSize, window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize - btnIconPadding + btnSize, window->posY + WINDOW_PADDING + btnPadding + btnIconPadding, BLACK);

    DrawShadyRectangle(window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize - betweenBtnPadding - btnSize, window->posY + WINDOW_PADDING + btnPadding, btnSize, btnSize, WINDOW_BG_COLOR, 1, 1, 1);

    // maximize
    DrawRectangle(window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize - betweenBtnPadding - btnSize + btnIconPadding, window->posY + WINDOW_PADDING + btnPadding + btnIconPadding, btnSize - 2*btnIconPadding, btnSize - 2*btnIconPadding, BLACK);
    int iconHeaderSize = 3;
    int iconMaximizePadding = 1;
    DrawRectangle(window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize - betweenBtnPadding - btnSize + btnIconPadding + iconMaximizePadding, window->posY + WINDOW_PADDING + btnPadding + btnIconPadding + iconHeaderSize, btnSize - 2*btnIconPadding - 2*iconMaximizePadding, btnSize - 2*btnIconPadding - iconMaximizePadding - iconHeaderSize, WINDOW_BG_COLOR);

    // minimize
    DrawShadyRectangle(window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize - 2*betweenBtnPadding - 2*btnSize, window->posY + WINDOW_PADDING + btnPadding, btnSize, btnSize, WINDOW_BG_COLOR, 1, 1, 1);

    int minimizePadding = 1;
    int minimizeHeight = 3;
    DrawRectangle(window->posX + window->width - WINDOW_PADDING - btnPadding - btnSize - 2*betweenBtnPadding - 2*btnSize + btnIconPadding + minimizePadding, window->posY + WINDOW_PADDING - btnPadding + btnSize, btnSize - 2*btnIconPadding - 2*minimizePadding, minimizeHeight, BLACK);

}