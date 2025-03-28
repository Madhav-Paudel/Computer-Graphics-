// C program to remove hidden surface 

#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 640
#define HEIGHT 480
#define DEPTH_MAX 10000  

float zBuffer[WIDTH][HEIGHT]; 

void initZBuffer() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            zBuffer[x][y] = DEPTH_MAX;  
        }
    }
}

void putPixelZ(int x, int y, float z, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        if (z < zBuffer[x][y]) {  
            zBuffer[x][y] = z;   
            putpixel(x, y, color);  
        }
    }
}

void drawSquare3D(int x, int y, int size, float depth, int color) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            putPixelZ(i, j, depth, color);
        }
    }
}

int main() {
    
  

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "NULL");  

    initZBuffer(); 
    
    outtextxy(310, 310, "Roman Raut");  // Display user name on the screen
    
    drawSquare3D(200, 150, 100, 5.0, RED);  
    drawSquare3D(220, 170, 100, 10.0, BLUE); 
    
    getch();  
    closegraph(); 
    return 0;
}

// for algorithm copy the link https://chatgpt.com/share/67e64c40-5c0c-800d-a272-469165b2bbb6 and give the given code to it 