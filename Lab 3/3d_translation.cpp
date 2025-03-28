// Program to translate the 3d object 


#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int x1, x2, y1, y2, depth;

void draw();
void trans();

int main() {
    int gd = DETECT, gm;
    char driver_path[] = "C:\\TurboC3\\BGI";  // Path for Turbo C++ BGI driver

    initgraph(&gd, &gm, driver_path);

    // Fixed values for input
    x1 = 100, y1 = 100;
    x2 = 200, y2 = 200;
    depth = (x2 - x1) / 4;

    // Display your name
    setcolor(WHITE);
    outtextxy(30, 30, "Madhav Paudel");

    // Draw original figure
    setcolor(WHITE);
    draw();
    outtextxy(10, 30, "Original Figure"); // Display label for original figure
    getch(); // Wait for user input

    // Now perform translation and draw the translated figure
    cleardevice();  // Clear the screen before drawing the translated figure
    setcolor(WHITE);
    outtextxy(10, 10, "Madhav Paudel");  // Display your name again
    outtextxy(10, 30, "Original Figure"); // Display label for original figure

    draw(); // Redraw original figure
    trans(); // Draw the translated figure
    outtextxy(300, 250, "Translated Figure"); // Display label for translated figure
    getch(); // Wait for user input

    closegraph();
    return 0;
}

void draw() {
    bar3d(x1, y1, x2, y2, depth, 1); // Draw the original figure
}

void trans() {
    int a1, a2, b1, b2, dep;
    int tx = 100, ty = 60; // Increased translation distances

    // Perform translation
    a1 = x1 + tx;
    a2 = x2 + tx;
    b1 = y1 + ty;
    b2 = y2 + ty;
    dep = (a2 - a1) / 4;

    // Draw translated figure with a different color
    setcolor(YELLOW);
    bar3d(a1, b1, a2, b2, dep, 1); // Draw the translated figure
}
