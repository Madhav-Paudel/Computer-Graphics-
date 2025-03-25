// Q3) Program for Midpoint Circle Generation Algorithm
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void draw_circle(int, int, int);
void symmetry(int, int, int, int);

int main() {
    int xc = 100, yc = 100, R = 50; // Initialized radius to a default value
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    if (graphresult() != grOk) {
        printf("Graphics initialization failed!\n");
        return 1;
    }

    draw_circle(xc, yc, R);
    outtextxy(250, 50, "Dikesh Sapkota");

    getch();
    closegraph();
    return 0;
}

void draw_circle(int xc, int yc, int rad) {
    int x = 0, y = rad;
    int p = 1 - rad;
    symmetry(x, y, xc, yc);

    while (x < y) {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        symmetry(x, y, xc, yc);
        delay(50);
    }
}

void symmetry(int x, int y, int xc, int yc) {
    putpixel(xc + x, yc + y, GREEN);
    putpixel(xc - x, yc + y, GREEN);
    putpixel(xc + x, yc - y, GREEN);
    putpixel(xc - x, yc - y, GREEN);
    putpixel(xc + y, yc + x, GREEN);
    putpixel(xc - y, yc + x, GREEN);
    putpixel(xc + y, yc - x, GREEN);
    putpixel(xc - y, yc - x, GREEN);
}
