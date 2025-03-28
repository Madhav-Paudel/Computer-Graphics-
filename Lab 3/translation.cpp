// C program to translate the line 

#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set custom window size
    int width = 800, height = 600;
    initwindow(width, height, "2D Translation");

    float x1, y1, x2, y2, x3, y3, x4, y4;
    float tx = 100, ty = 50; // Translation factors

    // Fixed values for input
    x1 = 200, y1 = 300;
    x2 = 400, y2 = 300;

    // Draw Original Line
    setcolor(RED);
    line(x1, y1, x2, y2);
    outtextxy(x2 + 10, y2 + 10, "Original Line");

    // Translation Transformation
    x3 = x1 + tx;
    y3 = y1 + ty;
    x4 = x2 + tx;
    y4 = y2 + ty;

    // Draw Translated Line
    setcolor(BLUE);
    line(x3, y3, x4, y4);
    outtextxy(x3 + 10, y3 + 10, "Translated Line");
    setcolor(WHITE);
    outtextxy(200, 250, "By Madhav Paudel");

    // Wait for key press and close
    getch();
    closegraph();
    return 0;
}
