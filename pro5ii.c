//write a c program to merge and display two sorted arrays //
#include <stdio.h>

int main() {
    int size1, size2, i, j, k;
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    int arr1[size1], arr2[size2], merged[size1 + size2];

    printf("Enter elements of the first array: ");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements of the second array: ");
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merge the arrays
    i = 0;
    j = 0;
    k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements
    while (i < size1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    // Display the merged array
    printf("Merged array: ");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}