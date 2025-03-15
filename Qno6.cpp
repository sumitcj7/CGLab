#include <graphics.h>
#include <stdio.h>
#include <conio.h>
/*
Input to be given:
Enter the center of the circle (xc, yc): 200 200
Enter the radius of the circle: 100
*/
void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void midPointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;  // Initial decision parameter

    drawCircle(xc, yc, x, y);

    while (x < y) {
        x++;

        if (p < 0)
            p += 2 * x + 1;  // Mid-point inside
        else {
            y--;
            p += 2 * (x - y) + 1;  // Mid-point outside
        }

        drawCircle(xc, yc, x, y);
        delay(10); // Small delay for visualization
    }
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // User input for circle center and radius
    printf("Enter the center of the circle (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    // Draw the circle using Mid-Point Algorithm
    midPointCircle(xc, yc, r);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}
