// Program for Rotation 2D rotation of a line
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set custom window size
    int width = 800, height = 600;
    initwindow(width, height, "2D Rotation");

    float x1, y1, x2, y2, x3, y3, x4, y4, angle, t;

    // Fixed values for input
    x1 = 200, y1 = 300;
    x2 = 400, y2 = 300;
    angle = 30; // Rotate by 30 degrees

    // Draw Original Line
    setcolor(RED);
    line(x1, y1, x2, y2);
    outtextxy(x2 + 10, y2 + 10, "Original Line");

    // Convert Angle to Radians
    t = angle * (M_PI / 180);

    // Rotation Transformation Around Origin
    x3 = (x1 * cos(t)) - (y1 * sin(t));
    y3 = (x1 * sin(t)) + (y1 * cos(t));
    x4 = (x2 * cos(t)) - (y2 * sin(t));
    y4 = (x2 * sin(t)) + (y2 * cos(t));

    // Draw Rotated Line
    setcolor(BLUE);
    line(x3, y3, x4, y4);
    outtextxy(x3 + 10, y3 + 10, "Rotated Line");

    // Wait for key press and close
    getch();
    closegraph();
    return 0;
}
