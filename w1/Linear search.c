#include <stdio.h>

//linear search


void main (){
    int len;
    int flag=0;
    int i;
    int search;
    printf("Enter the length of the array\n");
    scanf("%d", &len);
    int arr[len];

    printf("Enter the numbers in the array\n");
    for(i=0; i<len; i++){
        scanf("%d", &arr[i]);
}

    printf("Enter a number to search\n");
    scanf("%d", &search);

    for(i=0; i<=len; i++){
        if (search == arr[i]){
            flag = 1;
                break;
        }
}
    if (flag == 1){
        printf("Number found");
}
    else {
        printf("Number not found");
}
}
