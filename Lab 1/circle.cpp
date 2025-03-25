// Program to draw circle 

#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    
    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Draw a circle (x, y, radius)
    circle(250, 200, 100);

    // Wait for a key press
    getch();

    // Close graphics mode
    closegraph();

    return 0;
}
