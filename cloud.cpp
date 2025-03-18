// Create an animation to simulate the movement of a cloud OpenGL
#include <GL/freeglut.h>
#include <cmath>

float cloudX = -1.0f;

void drawCloud() {
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(cloudX + 0.1f * cos(angle), 0.5f + 0.05f * sin(angle));
    }
    glEnd();
}

void update(int value) {
    cloudX += 0.01f;
    if (cloudX > 1.0f) cloudX = -1.0f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCloud();
    glutSwapBuffers();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Moving Cloud Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}

