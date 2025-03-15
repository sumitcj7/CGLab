#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define MAX_VERTICES 10  // Maximum number of vertices for the polygon
/*
Input to be given;
Enter number of vertices: 4
Enter coordinates of the polygon:
Vertex 1 (x y): 100 100
Vertex 2 (x y): 200 50
Vertex 3 (x y): 300 150
Vertex 4 (x y): 150 200
*/
void scanlineFill(int x[], int y[], int n) {
    int i, j, k, temp;
    int yMax = y[0], yMin = y[0];

    // Find the maximum and minimum y-values of the polygon
    for (i = 1; i < n; i++) {
        if (y[i] > yMax) yMax = y[i];
        if (y[i] < yMin) yMin = y[i];
    }

    // Scan each horizontal line (y)
    for (int scanline = yMin; scanline <= yMax; scanline++) {
        int intersection[MAX_VERTICES], count = 0;

        // Find intersections of scanline with polygon edges
        for (i = 0; i < n; i++) {
            j = (i + 1) % n; // Next vertex

            if (y[i] != y[j]) {  // Ignore horizontal edges
                if ((scanline >= y[i] && scanline < y[j]) || (scanline >= y[j] && scanline < y[i])) {
                    intersection[count++] = x[i] + (scanline - y[i]) * (x[j] - x[i]) / (y[j] - y[i]);
                }
            }
        }

        // Sort intersection points in ascending order
        for (i = 0; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (intersection[i] > intersection[j]) {
                    temp = intersection[i];
                    intersection[i] = intersection[j];
                    intersection[j] = temp;
                }
            }
        }

        // Fill pixels between pairs of intersection points
        for (i = 0; i < count; i += 2) {
            for (j = intersection[i]; j <= intersection[i + 1]; j++) {
                putpixel(j, scanline, WHITE);
            }
        }
        delay(10); // Small delay for visualization
    }
}

int main() {
    int gd = DETECT, gm;
    int n, x[MAX_VERTICES], y[MAX_VERTICES];

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // User input for polygon vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 3) {
        printf("A polygon must have at least 3 vertices.\n");
        closegraph();
        return 0;
    }

    printf("Enter coordinates of the polygon:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d (x y): ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // Draw the polygon
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    // Apply scan line fill algorithm
    scanlineFill(x, y, n);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}
