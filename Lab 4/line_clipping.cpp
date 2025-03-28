//c Program for line clipping  
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#define Round(val) ((int)(val + 0.5))

int maxx = 400, maxy = 300, minx = 100, miny = 100;

void clipping(int xa, int ya, int xb, int yb);

int main() {
    int gd = DETECT, gm;
    int xa = 120, ya = 150, xb = 380, yb = 280;

    initgraph(&gd, &gm, "");
    
    rectangle(minx, miny, maxx, maxy);
    line(xa, ya, xb, yb);
    outtextxy(310, 310, "Madhav Paudel");
    
    getch();
    closegraph();
    return 0;
}

void clipping(int xa, int ya, int xb, int yb) {
    int Dx = xb - xa, Dy = yb - ya, steps, k;
    int visible1 = 0, visible2 = 0;
    float xin, yin, x = xa, y = ya;
    
    if (abs(Dx) > abs(Dy))
        steps = abs(Dx);
    else
        steps = abs(Dy);
    
    xin = Dx / (float) steps;
    yin = Dy / (float) steps;
    putpixel(Round(x), Round(y), 2);
    
    for (k = 0; k < steps; k++) {
        x += xin;
        y += yin;
        if ((y > miny && y < maxx)) {
            visible1 = 1;
            putpixel(Round(x), Round(y), 2);
        } else {
            visible2 = 1;
        }
    }
    
    if (visible1 == 0)
        outtextxy(20, 200, "completely visible");
    if (visible1 == 1 && visible2 == 1)
        outtextxy(20, 20, "partially visible");
    if (visible1 == 1 && visible2 == 0)
        outtextxy(20, 20, "completely visible");
}

// for algorithm copy the link https://chatgpt.com/share/67e64c40-5c0c-800d-a272-469165b2bbb6 and give the given code to it 