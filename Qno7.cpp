#include <graphics.h>
#include <stdio.h>
#include <conio.h>
/*
Input to be given:
Enter the center of the ellipse (xc, yc): 250 250
Enter the radii (rx, ry): 150 100
*/
void drawEllipse(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void midPointEllipse(int xc, int yc, int rx, int ry) {
    float dx, dy, d1, d2;
    int x = 0, y = ry;

    // Region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy) {
        drawEllipse(xc, yc, x, y);
        if (d1 < 0) {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + (ry * ry);
        } else {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + (ry * ry);
        }
        delay(5);
    }

    // Region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0) {
        drawEllipse(xc, yc, x, y);
        if (d2 > 0) {
            y--;
            dy -= 2 * rx * rx;
            d2 += (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + (rx * rx);
        }
        delay(5);
    }
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, rx, ry;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // User input for ellipse center and radii
    printf("Enter the center of the ellipse (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the radii (rx, ry): ");
    scanf("%d %d", &rx, &ry);

    // Draw the ellipse using Mid-Point Algorithm
    midPointEllipse(xc, yc, rx, ry);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}
