// Q.No.4) Write a program to create a car shape.

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void drawCar() {
    // Car body
    rectangle(100, 200, 300, 400);
    // Car upper body
    rectangle(125, 100, 275, 200);
    // Wheels
    circle(150, 400, 25);
    circle(250, 400, 25);
}

int main() {
    int gd = DETECT, gm;
    int roll_number = 15; 

   
    initgraph(&gd, &gm, "");

    // Draw car
    drawCar();


    outtextxy(roll_number * 10, roll_number * 10, "Dikesh Sapkota");

    // Wait for 5 seconds
    delay(5000);

    // Wait for key press before closing
    getch();
    closegraph();

    return 0;
}
