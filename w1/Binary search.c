#include <stdio.h>

// Binary Search in C

int main() {
    int len;
    int search;
    int i;

    printf("Enter the length of the array:\n");
    scanf("%d", &len);

    int arr[len];

    printf("Enter the numbers in the array (sorted):\n");
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter a number to search:\n");
    scanf("%d", &search);

    int low = 0, high = len - 1, mid, flag = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == search) {
            printf("Element %d found at position %d (index %d)\n", search, mid + 1, mid);
            flag = 1;
            break;
        }
        else if (arr[mid] < search) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (flag == 0) {
        printf("Element %d not found in the array\n", search);
    }

    return 0;
}

