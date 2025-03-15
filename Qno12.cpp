#include <graphics.h>
#include <stdio.h>
#include <conio.h>
/*
Enter the coordinates of the triangle:
Vertex 1 (x1, y1): 100 100
Vertex 2 (x2, y2): 200 50
Vertex 3 (x3, y3): 250 150
*/
int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;  // Original triangle coordinates
    int x1_new, y1_new, x2_new, y2_new, x3_new, y3_new;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL); // Use "C:\\TURBOC3\\BGI" if using Turbo C++

    // Get screen height for reflection calculation
    int screenHeight = getmaxy();

    // User input for original triangle coordinates
    printf("Enter the coordinates of the triangle:\n");
    printf("Vertex 1 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Vertex 2 (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Vertex 3 (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // Draw the original triangle (White)
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Apply reflection about the X-axis
    int y_reflect_axis = screenHeight / 2;  // Midpoint of the screen

    x1_new = x1;
    y1_new = 2 * y_reflect_axis - y1;
    x2_new = x2;
    y2_new = 2 * y_reflect_axis - y2;
    x3_new = x3;
    y3_new = 2 * y_reflect_axis - y3;

    // Draw the reflected triangle (Red)
    setcolor(RED);
    line(x1_new, y1_new, x2_new, y2_new);
    line(x2_new, y2_new, x3_new, y3_new);
    line(x3_new, y3_new, x1_new, y1_new);

    // Display coordinates
    printf("Original Triangle: (%d, %d), (%d, %d), (%d, %d)\n", x1, y1, x2, y2, x3, y3);
    printf("Reflected Triangle: (%d, %d), (%d, %d), (%d, %d)\n", x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}
