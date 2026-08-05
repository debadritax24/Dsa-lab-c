// insert a number at a given location in an array and display the array before and after insertion //
#include <stdio.h>

int main() {
    int n, i, pos, num;
    int a[100];

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position where you want to insert element: ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &num);

    // Shift elements to the right
    for(i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }

    // Insert the new element
    a[pos] = num;
    n++; // Increment the size of the array

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}