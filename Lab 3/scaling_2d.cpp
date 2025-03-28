// C program to scaling the line #include <stdio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int width = 800, height = 600;
    initwindow(width, height, "Line Scaling");

    float x1 = 200, y1 = 300;
    float x2 = 400, y2 = 300;
    float sx = 2.0, sy = 1.5;  // Scaling factors
    float x3, y3, x4, y4;

    // Draw Original Line
    setcolor(RED);
    line(x1, y1, x2, y2);
    outtextxy(x2 + 10, y2 + 10, "Original Line");

    // Apply Scaling Transformation
    x3 = x1 * sx;
    y3 = y1 * sy;
    x4 = x2 * sx;
    y4 = y2 * sy;

    // Draw Scaled Line
    setcolor(BLUE);
    line(x3, y3, x4, y4);
    outtextxy(x3 + 10, y3 + 10, "Scaled Line");

    // Display author name
    setcolor(WHITE);
    outtextxy(300, 350, "By Roman Raut");

    getch();
    closegraph();
    return 0;
}
