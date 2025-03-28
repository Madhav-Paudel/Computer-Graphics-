// Q4) Program for Ellipse Generation Algorithm
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void disp(int, int);

int xc = 250, yc = 250;  // Fixed center of ellipse

int main() {
    int gd = DETECT, gm;
    int rx = 100, ry = 60;  // Fixed radii
    float p1, p2;

    initgraph(&gd, &gm, (char*)"C:\\TURBOC3\\BGI");  // Ensure this path exists

    int x = 0, y = ry;
    disp(x, y);

    // Region 1
    p1 = (ry * ry) - (rx * rx * ry) + (rx * rx) / 4;
    while ((2.0 * ry * ry * x) <= (2.0 * rx * rx * y)) {
        x++;
        if (p1 <= 0)
            p1 += (2.0 * ry * ry * x) + (ry * ry);
        else {
            y--;
            p1 += (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (ry * ry);
        }
        disp(x, y);
    }

    // Region 2
    x = rx;
    y = 0;
    disp(x, y);

    p2 = (rx * rx) + 2.0 * (ry * ry * rx) + (ry * ry) / 4;
    while ((2.0 * ry * ry * x) > (2.0 * rx * rx * y)) {
        y++;
        if (p2 > 0)
            p2 += (rx * rx) - (2.0 * rx * rx * y);
        else {
            x--;
            p2 += (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (rx * rx);
        }
        disp(x, y);
    }

    // Display name
    outtextxy(180, 180, (char*)"Dikesh Sapkota");

    getch();  // Pause until key press
    closegraph();
    return 0;  // Corrected main return type
}

// Function to plot ellipse points
void disp(int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}


// for algorithm copy the link https://chatgpt.com/share/67e64c40-5c0c-800d-a272-469165b2bbb6 and give the given code to it 