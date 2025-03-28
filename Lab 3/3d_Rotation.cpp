// C Program for Rotation
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int x1, x2, y1_coord, y2, mx, my, depth;

void draw();
void rotate(float t);

int main() {
    int gd = DETECT, gm;
    float angle = 45.0; // Fixed rotation angle
    
    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");  // Update the path if needed
    
    // Fixed values for rectangle
    x1 = 100, y1_coord = 100;
    x2 = 200, y2 = 200;
    
    // Calculate midpoint
    mx = (x1 + x2) / 2;
    my = (y1_coord + y2) / 2;
    
    // Display name at the top
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(10, 10, "Madhav Paudel");
    
    // Draw original figure
    setcolor(WHITE);
    draw();
    outtextxy(10, 30, "Original Figure");
    
    delay(1000); // Wait for a second
    
    // Clear the screen
    cleardevice();
    
    // Display name again at the top
    outtextxy(10, 10, "Madhav Paudel");
    outtextxy(10, 30, "Original Figure");
    
    // Redraw original figure
    setcolor(WHITE);
    draw();
    
    // Perform and draw rotated figure
    setcolor(YELLOW);
    rotate(angle);
    outtextxy(250, 30, "Rotated Figure");
    
    getch();
    closegraph();
    return 0;
}

void draw() {
    // Draw original 3D bar (rectangle)
    bar3d(x1, y1_coord, x2, y2, 20, 1);  // Using a fixed depth for simplicity
}

void rotate(float t) {
    int a1, b1, a2, b2;
    
    // Convert angle to radians
    t = t * (3.14159 / 180.0);
    
    // Rotation calculations
    a1 = mx + (x1 - mx) * cos(t) - (y1_coord - my) * sin(t);
    a2 = mx + (x2 - mx) * cos(t) - (y2 - my) * sin(t);
    b1 = my + (x1 - mx) * sin(t) + (y1_coord - my) * cos(t);
    b2 = my + (x2 - mx) * sin(t) + (y2 - my) * cos(t);
    
    // Draw rotated 3D bar (rectangle)
    bar3d(a1, b1, a2, b2, 20, 1);  // Using a fixed depth for simplicity
}

// for algorithm copy the link https://chatgpt.com/share/67e64c40-5c0c-800d-a272-469165b2bbb6 and give the given code to it 

