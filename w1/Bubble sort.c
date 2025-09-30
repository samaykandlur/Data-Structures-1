#include <stdio.h>

//Bubble sort

void main(){
    int len;
    int i,j;
    int search, temp;
    printf("Enter the length of the array\n");
    scanf("%d", &len);
    int arr[len];

    printf("Enter the numbers in the array\n");
    for(i=0; i<len; i++){
        scanf("%d", &arr[i]);
}

    printf("Sorted Array:\n");

    for(i = 0; i < len - 1; i++) {
    for(j = 0; j < len - i - 1; j++) {
        if(arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}


    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
}
printf("\n");

}
