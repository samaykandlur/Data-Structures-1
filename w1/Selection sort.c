#include <stdio.h>

int main() {
    int i, j, len, minIdx, temp;

    printf("Enter the length of the array\n");
    scanf("%d", &len);

    int arr[len];

    printf("Enter the numbers in the array\n");
    for(i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < len - 1; i++) {
        minIdx = i;
        for(j = i + 1; j < len; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if(minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }

    printf("Sorted Array:\n");
    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
