#include <graphics.h>
#include <stdio.h>
#include <conio.h>
/*
Enter the coordinates of the triangle:
Vertex 1 (x1, y1): 100 100
Vertex 2 (x2, y2): 200 50
Vertex 3 (x3, y3): 250 150
Enter scaling factors (Sx, Sy): 2 2
*/
int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;  // Original triangle coordinates
    int x1_new, y1_new, x2_new, y2_new, x3_new, y3_new;
    float sx, sy;  // Scaling factors

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

    // User input for scaling factors
    printf("Enter scaling factors (Sx, Sy): ");
    scanf("%f %f", &sx, &sy);

    // Draw the original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Apply scaling transformation
    x1_new = x1 * sx;
    y1_new = y1 * sy;
    x2_new = x2 * sx;
    y2_new = y2 * sy;
    x3_new = x3 * sx;
    y3_new = y3 * sy;

    // Draw the scaled triangle
    setcolor(RED);
    line(x1_new, y1_new, x2_new, y2_new);
    line(x2_new, y2_new, x3_new, y3_new);
    line(x3_new, y3_new, x1_new, y1_new);

    // Display results
    printf("Original triangle: (%d, %d), (%d, %d), (%d, %d)\n", x1, y1, x2, y2, x3, y3);
    printf("Scaled triangle: (%d, %d), (%d, %d), (%d, %d)\n", x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}
