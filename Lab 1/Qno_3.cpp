// Q.No.3) Write a program to create House shape.

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int roll_number = 15;  // Change this to your actual roll number

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Draw a house shape
    rectangle(120, 160, 300, 320);  // House body
    rectangle(190, 280, 240, 320);  // Door
    line(120, 160, 200, 30);        // Left roof
    line(200, 30, 300, 160);        // Right roof

    // Display name at calculated position
    outtextxy(roll_number * 10, roll_number * 10, "Dikesh Sapkota");
    

    // Wait for key press
    getch();

    // Close graphics mode
    closegraph();

    return 0;
}
