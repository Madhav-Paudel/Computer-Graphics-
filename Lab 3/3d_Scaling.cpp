// Program for scaling:
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int x1, y1, x2, y2, mx, my;

void draw();
void scale();

int main() {
    int gd = DETECT, gm;
    
    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");  // Update the path if needed
    
    // Fixed values for rectangle (can change as needed)
    x1 = 100, y1 = 100;
    x2 = 200, y2 = 200;
    
    // Calculate midpoint for scaling
    mx = (x1 + x2) / 2;
    my = (y1 + y2) / 2;
    
    // Display name
    setcolor(WHITE);
    outtextxy(330, 330, "Madhav Paudel");
    
    // Draw the original rectangle
    setcolor(WHITE);
    draw();
    outtextxy(10, 30, "Original Figure"); // Label for original figure
    getch();  // Wait for user input
    
    // Clear the screen
    cleardevice();
    
    // Display name again
    setcolor(WHITE);
    outtextxy(300, 330, "Madhav paudel");
    outtextxy(100, 230, "Original Figure"); // Label for original figure
    
    // Redraw original figure
    draw();
    
    // Perform and draw scaled figure
    scale();
    outtextxy(300, 250, "Scaled Figure"); // Label for scaled figure
    
    getch();  // Wait for user input
    closegraph(); // Close the graphics window
    return 0;
}

void draw() {
    // Draw the original rectangle
    setcolor(RED);
    rectangle(x1, y1, x2, y2);
}

void scale() {
    int x_scale = 2, y_scale = 3;  // Hardcoded scaling factors
    int a1, a2, b1, b2;
    
    // Perform scaling around the midpoint (mx, my)
    a1 = mx + (x1 - mx) * x_scale;
    a2 = mx + (x2 - mx) * x_scale;
    b1 = my + (y1 - my) * y_scale;
    b2 = my + (y2 - my) * y_scale;
    
    // Draw the scaled rectangle in yellow
    setcolor(YELLOW);
    rectangle(a1, b1, a2, b2);
}