// Q1)  Program for DDA Line Drawing Algorithm.
#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    if (graphresult() != grOk) {
        printf("Graphics initialization failed!\n");
        return 1;
    }

    float x, y, x1 = 100, y1 = 101, x2 = 200, y2 = 201, dx, dy, step;

    dx = x2 - x1;
    dy = y2 - y1;

    step = (fabs(dx) >= fabs(dy)) ? fabs(dx) : fabs(dy);
    dx /= step;
    dy /= step;

    x = x1;
    y = y1;

    for (int i = 0; i <= step; i++) {
        putpixel(round(x), round(y), WHITE);
        x += dx;
        y += dy;
    }

    // Display the user's name
    setcolor(WHITE);
    outtextxy(250, 50, "Dikesh Sapkota");

    getchar();  // Wait for key press
    closegraph();
    return 0;
}


// for algorithm copy the link https://chatgpt.com/share/67e64c40-5c0c-800d-a272-469165b2bbb6 and give the given code to it 