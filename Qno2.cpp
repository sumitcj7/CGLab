#include <graphics.h>
#include <stdio.h>
#include <math.h>
/*
Input to be given
Enter the starting point of the line (x1, y1): 100 100
Enter the ending point of the line (x2, y2): 300 100
*/
void drawDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); // Determine number of steps
    float Xinc = (float)dx / steps;
    float Yinc = (float)dy / steps;

    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE); // Draw the pixel
        x += Xinc;
        y += Yinc;
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

    // Draw the line using DDA Algorithm
    drawDDA(x1, y1, x2, y2);

    // Wait for user to press a key
    getch();
    closegraph();
    
    return 0;
}
