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

// for algorithm copy the link https://chatgpt.com/share/67e64c40-5c0c-800d-a272-469165b2bbb6 and give the given code to it 