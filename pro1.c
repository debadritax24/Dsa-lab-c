//FIND WHETHER THERE IS ANY DUPLICATE ELEMENT PRESENT IN AN ARRAY OR NOT. IF FOUND, THEN DISPLAY THE CORRESPONDING POSITIONN OF THESE DUPLICATE ELEMENTS.//
#include <stdio.h>

int main() {
    int n, i, j, a[100], found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Duplicate elements and their positions:\n");

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                printf("Element %d found at positions %d and %d\n", a[i], i, j);
                found = 1;
            }
        }
    }

    if(!found)
        printf("No duplicate elements found.");

    return 0;
}