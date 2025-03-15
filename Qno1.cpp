/*
Input to be given
Enter the starting point of the line (x1, y1): 100 100
Enter the ending point of the line (x2, y2): 300 100
*/
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL); // Using NULL instead of (char*)"" 

    // Taking input from user
    printf("Enter the starting point of the line (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter the ending point of the line (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw the line using user input
    line(x1, y1, x2, y2);

    // Wait for user input before closing
    getch();
    closegraph();
    
    return 0;
}
