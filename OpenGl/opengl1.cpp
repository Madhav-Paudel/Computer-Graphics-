


#include <GL/glut.h>
#include <cmath>

void drawLine() {
    glBegin(GL_LINES);
    glVertex2f(-0.8, 0.8);  // Start point
    glVertex2f(0.8, -0.8);  // End point
    glEnd();
}

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
}

void drawRectangle() {
    glBegin(GL_QUADS);
    glVertex2f(-0.6, -0.4);
    glVertex2f(0.6, -0.4);
    glVertex2f(0.6, 0.4);
    glVertex2f(-0.6, 0.4);
    glEnd();
}

void drawPolygon() {  // Pentagon
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.5);
    glVertex2f(0.2, -0.5);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.4, 0.0);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);  // Center of the circle
    for (int i = 0; i <= num_segments; i++) {
        float angle = 2.0f * M_PI * i / num_segments;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);  // Red color
    drawLine();

    glColor3f(0.0, 1.0, 0.0);  // Green color
    drawTriangle();

    glColor3f(0.0, 0.0, 1.0);  // Blue color
    drawRectangle();

    glColor3f(1.0, 1.0, 0.0);  // Yellow color
    drawPolygon();

    glColor3f(1.0, 0.0, 1.0);  // Purple color
    drawCircle(0.0, -0.7, 0.3, 50);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Shapes");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
