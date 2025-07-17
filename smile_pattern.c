#include <stdio.h>
#include <math.h>

int main() {
    int i, j;
    // Define the dimensions and center of the face
    int rows = 21, cols = 41;
    int center_row = rows / 2;
    int center_col = cols / 2;
    int radius = 9;
    for ( i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            double dist = sqrt((i - center_row) * (i - center_row) + (j - center_col) * (j - center_col));
            // Face outline
            if (dist >= radius - 0.7 && dist <= radius + 0.7) {
                printf("*");
            }
            // Eyes
            else if ((i == center_row - 3 && (j == center_col - 3 || j == center_col + 3))) {
                printf("*");
            }
            // Smile (arc)
            else if (i - center_row > 2 && i - center_row < 5) {
                double smile_dist = sqrt((i - (center_row + 3)) * (i - (center_row + 3)) + (j - center_col) * (j - center_col));
                if (smile_dist > 4.5 && smile_dist < 5.5 && j > center_col - 5 && j < center_col + 5) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
