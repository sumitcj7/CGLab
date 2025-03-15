#include <graphics.h>
#include <stdio.h>
#include <conio.h>
/*
Input to be given:
Enter top-left corner (x1, y1): 100 100
Enter bottom-right corner (x2, y2): 300 200
*/
int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // User input for rectangle coordinates
    printf("Enter top-left corner (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter bottom-right corner (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw the rectangle
    rectangle(x1, y1, x2, y2);

    // Wait for user to see the rectangle
    getch();
    closegraph();

    return 0;
}
