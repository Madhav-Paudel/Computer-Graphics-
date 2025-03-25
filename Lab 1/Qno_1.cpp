// Q.No.1) Write a program for creating line shapes.
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int roll_number = 15;  
    initgraph(&gd, &gm, "");

    line(100, 100, 150, 150);
    line(250, 250, 250, 200);
    line(180, 180, 225, 180);

    outtextxy(roll_number * 10, roll_number * 10, "Dikesh Sapkota");


    getch();

    closegraph();

    return 0;
}
