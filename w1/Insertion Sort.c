#include <stdio.h>

// Insertion sort
int main() {
    int i, j, len, temp;

    printf("Enter the length of the array\n");
    scanf("%d", &len);

    int arr[len];

    printf("Enter the numbers in the array\n");
    for(i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }


    for(i = 1; i < len; i++) {
        temp = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    printf("Sorted Array:\n");
    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

