#include <graphics.h>
#include <stdio.h>
#include <conio.h>
/*
Input to be given
Enter the starting point of the line (x1, y1): 100 100
Enter the ending point of the line (x2, y2): 300 100
*/
void drawBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy; // Initial error value

    while (1) {
        putpixel(x1, y1, WHITE); // Draw the pixel

        if (x1 == x2 && y1 == y2)
            break; // Stop when endpoint is reached

        int e2 = 2 * err;

        if (e2 > -dy) { // Move in x direction
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) { // Move in y direction
            err += dx;
            y1 += sy;
        }
        delay(5); // Small delay for visualization
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // User input for line coordinates
    printf("Enter the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw the line using Bresenham's Algorithm
    drawBresenham(x1, y1, x2, y2);

    // Wait for user to press a key
    getch();
    closegraph();

    return 0;
}
