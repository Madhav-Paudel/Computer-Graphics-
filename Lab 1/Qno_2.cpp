// Q.No.2) Write a program to create a man object.

#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int roll_number = 15; 
    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Draw a simple stick figure
    circle(150, 150, 35);   // Head
    line(150, 185, 150, 300); // Body
    line(150, 200, 120, 230); // Left hand
    line(150, 200, 180, 230); // Right hand
    line(150, 300, 120, 330); // Left leg
    line(150, 300, 180, 330); // Right leg

    // Display name at calculated position
    outtextxy(roll_number * 10, roll_number * 10, "Dikesh Sapkota");

    // Wait for key press
    getch();

    // Close graphics mode
    closegraph();

    return 0;
}
