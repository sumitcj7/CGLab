#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

float phase = 0.0f;

void drawCircle(float x, float y, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * PI * i / segments;
        float dx = radius * cosf(angle);
        float dy = radius * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawMoonPhase(float x, float y, float radius, float shadowOffset) {
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(x, y, radius, 100);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(x + shadowOffset, y, radius, 100);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    float radius = 0.3f;
    float shadowOffset = radius * cosf(phase);
    
    drawMoonPhase(0.0f, 0.0f, radius, shadowOffset);
    
    glFlush();
}

void update(int value) {
    phase += PI / 30.0f;
    if (phase > 2 * PI) phase = 0.0f;
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Moon Phases Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}

