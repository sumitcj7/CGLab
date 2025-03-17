#include <graphics.h>
#include <stdio.h>

#define MAX_VERTICES 10
/*
Enter number of vertices: 4
Enter vertex 1 (x y): 100 100
Enter vertex 2 (x y): 200 50
Enter vertex 3 (x y): 250 150
Enter vertex 4 (x y): 120 200
*/

// Structure to store polygon vertices
typedef struct {
    int x, y;
} Point;

Point polygon[MAX_VERTICES];
int n; // Number of vertices

// Function to fill polygon using Scan Line Algorithm
void scanLineFill() {
    int i, j, k, x1, y1, x2, y2, temp;
    int ymin = polygon[0].y, ymax = polygon[0].y;

    // Find ymin and ymax
    for (i = 1; i < n; i++) {
        if (polygon[i].y < ymin) ymin = polygon[i].y;
        if (polygon[i].y > ymax) ymax = polygon[i].y;
    }

    // Scan each line from ymin to ymax
    for (int y = ymin; y <= ymax; y++) {
        int intersectionX[MAX_VERTICES], intersections = 0;

        // Find intersections with polygon edges
        for (i = 0; i < n; i++) {
            j = (i + 1) % n;
            y1 = polygon[i].y;
            y2 = polygon[j].y;
            x1 = polygon[i].x;
            x2 = polygon[j].x;

            if (y1 > y2) { // Swap to ensure y1 < y2
                temp = y1; y1 = y2; y2 = temp;
                temp = x1; x1 = x2; x2 = temp;
            }

            // Check if scan line intersects edge
            if (y >= y1 && y < y2) {
                float x = x1 + ((float)(y - y1) / (y2 - y1)) * (x2 - x1);
                intersectionX[intersections++] = (int)x;
            }
        }

        // Sort intersection points
        for (i = 0; i < intersections - 1; i++) {
            for (j = 0; j < intersections - i - 1; j++) {
                if (intersectionX[j] > intersectionX[j + 1]) {
                    temp = intersectionX[j];
                    intersectionX[j] = intersectionX[j + 1];
                    intersectionX[j + 1] = temp;
                }
            }
        }

        // Fill pixels between pairs of intersections
        for (i = 0; i < intersections; i += 2) {
            for (k = intersectionX[i]; k <= intersectionX[i + 1]; k++) {
                putpixel(k, y, WHITE);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // User input for polygon
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter vertex %d (x y): ", i + 1);
        scanf("%d %d", &polygon[i].x, &polygon[i].y);
    }

    // Draw polygon
    for (int i = 0; i < n; i++) {
        line(polygon[i].x, polygon[i].y, polygon[(i + 1) % n].x, polygon[(i + 1) % n].y);
    }

    // Apply Scan Line Algorithm
    scanLineFill();

    printf("Scan Line Algorithm Applied. Press any key to exit.");
    getch();
    closegraph();

    return 0;
}
