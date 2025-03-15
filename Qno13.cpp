#include <graphics.h>
#include <stdio.h>
#include <conio.h>
/*
Input to be given 
Enter the coordinates of the triangle:
Vertex 1 (100, 100)
Vertex 2 (150, 150)
Vertex 3 (200, 100)

Enter shearing factor along X-axis (shX): 1.5
Enter shearing factor along Y-axis (shY): 0.5
*/
// Function to apply shearing transformation
void shearTransform(int x[], int y[], int shearedX[], int shearedY[], int n, float shX, float shY) {
    for (int i = 0; i < n; i++) {
        shearedX[i] = x[i] + shX * y[i];  // X-Shear
        shearedY[i] = y[i] + shY * x[i];  // Y-Shear
    }
}

int main() {
    int gd = DETECT, gm;
    int x[3], y[3], shearedX[3], shearedY[3];
    float shX, shY;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // Input original triangle coordinates
    printf("Enter the coordinates of the triangle:\n");
    for (int i = 0; i < 3; i++) {
        printf("Vertex %d (x, y): ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // Input shearing factors
    printf("Enter shearing factor along X-axis (shX): ");
    scanf("%f", &shX);
    printf("Enter shearing factor along Y-axis (shY): ");
    scanf("%f", &shY);

    // Draw original triangle (White)
    setcolor(WHITE);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);

    // Apply shearing transformation
    shearTransform(x, y, shearedX, shearedY, 3, shX, shY);

    // Draw sheared triangle (Red)
    setcolor(RED);
    line(shearedX[0], shearedY[0], shearedX[1], shearedY[1]);
    line(shearedX[1], shearedY[1], shearedX[2], shearedY[2]);
    line(shearedX[2], shearedY[2], shearedX[0], shearedY[0]);

    // Display coordinates
    printf("\nOriginal Triangle:\n");
    for (int i = 0; i < 3; i++)
        printf("(%d, %d) ", x[i], y[i]);

    printf("\nSheared Triangle:\n");
    for (int i = 0; i < 3; i++)
        printf("(%d, %d) ", shearedX[i], shearedY[i]);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}

