//write a c program to fill a square matrix with value 0 on the diagonals,1 onthe upper right triangle and -1 on the lower left triangle//
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int matrix[n][n];

    // Initialize the matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 0; // Diagonals
            } else if (i < j) {
                matrix[i][j] = 1; // Upper right triangle
            } else {
                matrix[i][j] = -1; // Lower left triangle
            }
        }
    }

    // Display the matrix
    printf("The filled matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}