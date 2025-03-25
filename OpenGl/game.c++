#include <GL/freeglut.h>
#include <cstdlib>
#include <ctime>

float playerX = 0.0f;  // Player position (X-axis)
const float playerSize = 0.1f;  
const float blockSize = 0.1f;
float blockX, blockY = 1.0f;  // Falling block position
float speed = 0.01f;  // Falling speed
bool gameOver = false;

void resetBlock() {
    blockX = ((rand() % 20) - 10) / 10.0f;  // Random X position
    blockY = 1.0f;  // Reset block to top
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (gameOver) {
        glColor3f(1, 0, 0);
        glRasterPos2f(-0.1f, 0.0f);
        const char* text = "Game Over!";
        for (int i = 0; text[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    } else {
        // Draw Player (Blue)
        glColor3f(0, 0, 1);
        glRectf(playerX - playerSize, -0.9f, playerX + playerSize, -0.85f);

        // Draw Falling Block (Red)
        glColor3f(1, 0, 0);
        glRectf(blockX - blockSize, blockY, blockX + blockSize, blockY - 0.1f);
    }

    glutSwapBuffers();
}

void update(int value) {
    if (!gameOver) {
        blockY -= speed;  // Move block down

        // Check if block reaches bottom
        if (blockY < -1.0f) {
            resetBlock();  // Reset block
            speed += 0.001f;  // Increase difficulty
        }

        // Collision Detection
        if (blockY < -0.85f && blockX > playerX - playerSize && blockX < playerX + playerSize) {
            gameOver = true;
        }

        glutPostRedisplay();
        glutTimerFunc(16, update, 0);
    }
}

// Player movement
void keyboard(int key, int, int) {
    if (!gameOver) {
        if (key == GLUT_KEY_LEFT && playerX > -0.9f) playerX -= 0.1f;
        if (key == GLUT_KEY_RIGHT && playerX < 0.9f) playerX += 0.1f;
        glutPostRedisplay();
    }
}

// Reset game on Spacebar press
void keyPress(unsigned char key, int, int) {
    if (key == ' ' && gameOver) {
        gameOver = false;
        speed = 0.01f;
        resetBlock();
        glutTimerFunc(16, update, 0);
    }
}

int main(int argc, char** argv) {
    srand(time(0));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Dodge the Falling Blocks");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutKeyboardFunc(keyPress);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}

