#include <graphics.h>
#include <stdio.h>
#include <conio.h>
/*
Input to be given
Enter first vertex (x1, y1): 100 100
Enter second vertex (x2, y2): 200 100
Enter third vertex (x3, y3): 150 200
*/
int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // User input for triangle vertices
    printf("Enter first vertex (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter second vertex (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter third vertex (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // Draw triangle using three lines
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Wait for user to see the triangle
    getch();
    closegraph();

    return 0;
}
