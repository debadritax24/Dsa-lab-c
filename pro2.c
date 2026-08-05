//find whether a key element is presnt in the array or not. if present then display the corresponding position of the key element.//
#include <stdio.h>

int main() {
    int n, i, key, found = 0;
    int a[100];

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Element %d found at position %d\n", key, i);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Element %d not found in the array.", key);

    return 0;
}