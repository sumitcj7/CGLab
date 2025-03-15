#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

#define PI 3.14159265  // Define the value of PI
/*
Enter the coordinates of the triangle:
Vertex 1 (x1, y1): 100 100
Vertex 2 (x2, y2): 200 50
Vertex 3 (x3, y3): 250 150
Enter the rotation angle (in degrees): 45
*/
void rotatePoint(int x, int y, float angle, int *x_new, int *y_new) {
    float rad = angle * (PI / 180.0);  // Convert degrees to radians
    *x_new = round(x * cos(rad) - y * sin(rad));
    *y_new = round(x * sin(rad) + y * cos(rad));
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;  // Original triangle coordinates
    int x1_new, y1_new, x2_new, y2_new, x3_new, y3_new;
    float angle;  // Rotation angle

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // User input for original triangle coordinates
    printf("Enter the coordinates of the triangle:\n");
    printf("Vertex 1 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Vertex 2 (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Vertex 3 (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // User input for rotation angle
    printf("Enter the rotation angle (in degrees): ");
    scanf("%f", &angle);

    // Draw the original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Apply rotation
    rotatePoint(x1, y1, angle, &x1_new, &y1_new);
    rotatePoint(x2, y2, angle, &x2_new, &y2_new);
    rotatePoint(x3, y3, angle, &x3_new, &y3_new);

    // Draw the rotated triangle
    setcolor(RED);
    line(x1_new, y1_new, x2_new, y2_new);
    line(x2_new, y2_new, x3_new, y3_new);
    line(x3_new, y3_new, x1_new, y1_new);

    // Display results
    printf("Original triangle: (%d, %d), (%d, %d), (%d, %d)\n", x1, y1, x2, y2, x3, y3);
    printf("Rotated triangle: (%d, %d), (%d, %d), (%d, %d)\n", x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}
