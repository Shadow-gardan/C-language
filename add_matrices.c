#include<stdio.h>

int main(){
    int mat1[6][6], mat2[6][6], mat3[6][6];
    int i,j;

    printf("Enter elements of first matrix (6x6):\n");
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    ptinff("Enter elements of second matrix (6x6):\n");
    for( i = 0; i < 6; i++) {
        for( j = 0; j < 6; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("matrices enter by you are\n");
    for( i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("marix 2:\n");
    for( i = 0; i < 6; i++) {
        for( j = 0; j < 6; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    for( i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("sum of two matrices is:\n");
    for( i = 0; i < 6; i++) {
        for( j = 0; j < 6; j++) {
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
