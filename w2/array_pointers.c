#include <stdio.h>
#include <stdlib.h>

int findSmallest(int *arr, int size) {
    int *ptr = arr;
    int min = *ptr;

    for (int i = 1; i < size; i++) {
        ptr++;
        if (*ptr < min) {
            min = *ptr;
        }
    }

    return min;
}

int main() {
    int n;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    int smallest = findSmallest(arr, n);
    printf("Smallest element is: %d\n", smallest);

    free(arr);

    return 0;
}
