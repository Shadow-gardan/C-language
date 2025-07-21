#include <stdio.h>
#include <math.h>

// Function prototypes
float distance(int x1, int y1, int x2, int y2);
float triarea(float a, float b, float c);
float check_point_in_triangle();

int main() {
    int x1, y1, x2, y2;
    float dist, tri_area;

    printf("Enter the coordinates of two points (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    dist = distance(x1, y1, x2, y2);
    printf("Distance between points: %.2f\n", dist);

    tri_area = check_point_in_triangle();
    printf("Area of the triangle: %.2f\n", tri_area);

    return 0;
}

// Function to calculate distance between two points
float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate area of a triangle using Heron's formula
float triarea(float a, float b, float c) {
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to get triangle and a point, calculate triangle area and check if point lies inside
float check_point_in_triangle() {
    int x1, y1, x2, y2, x3, y3, xp, yp;
    float a, b, c, area_main, area1, area2, area3, total_area;

    printf("Enter coordinates of triangle vertices (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("Enter coordinates of the point to check (x y): ");
    scanf("%d %d", &xp, &yp);

    // Triangle side lengths
    a = distance(x1, y1, x2, y2);
    b = distance(x2, y2, x3, y3);
    c = distance(x3, y3, x1, y1);

    // Area of the original triangle
    area_main = triarea(a, b, c);

    // Areas of sub-triangles with the point
    area1 = triarea(distance(x1, y1, x2, y2), distance(x2, y2, xp, yp), distance(xp, yp, x1, y1));
    area2 = triarea(distance(x2, y2, x3, y3), distance(x3, y3, xp, yp), distance(xp, yp, x2, y2));
    area3 = triarea(distance(x3, y3, x1, y1), distance(x1, y1, xp, yp), distance(xp, yp, x3, y3));

    total_area = area1 + area2 + area3;

    // Compare with small margin of error
    if (fabs(total_area - area_main) < 0.0001) {
        printf("The point (%d, %d) lies INSIDE the triangle.\n", xp, yp);
    } else {
        printf("The point (%d, %d) lies OUTSIDE the triangle.\n", xp, yp);
    }

    return area_main;
}

