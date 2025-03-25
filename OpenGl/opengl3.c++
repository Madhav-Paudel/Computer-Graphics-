#include <GL/freeglut.h>

float angle = 0.0f;  // Rotation angle
float posX = 0.0f, posY = 0.0f;  // Cube position
bool rotating = true;  // Rotation toggle

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(posX, posY, -5.0f);  // Move cube
    if (rotating)
        glRotatef(angle, 1.0f, 1.0f, 1.0f); // Rotate cube

    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    // Back face (green)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Left face (blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    // Right face (yellow)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);

    // Top face (cyan)
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    // Bottom face (magenta)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glEnd();
    glutSwapBuffers();
}

void update(int value) {
    if (rotating) {
        angle += 1.0f;  // Rotate only if enabled
        if (angle > 360) angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS update
}

// Handle keyboard input
void keyboard(int key, int x, int y) {
    float moveSpeed = 0.1f;  // Movement speed

    switch (key) {
        case GLUT_KEY_LEFT:  posX -= moveSpeed; break;
        case GLUT_KEY_RIGHT: posX += moveSpeed; break;
        case GLUT_KEY_UP:    posY += moveSpeed; break;
        case GLUT_KEY_DOWN:  posY -= moveSpeed; break;
    }
    glutPostRedisplay();
}

// Toggle rotation on Spacebar
void keyPress(unsigned char key, int x, int y) {
    if (key == ' ') rotating = !rotating;
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Interactive 3D Cube");

    glEnable(GL_DEPTH_TEST);  // Enable depth testing

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);
    glutSpecialFunc(keyboard); // Arrow keys
    glutKeyboardFunc(keyPress); // Spacebar toggle

    glutMainLoop();
    return 0;
}

