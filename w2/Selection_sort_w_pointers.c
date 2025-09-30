#include <stdio.h>

void swap(int *a, int *b){
    int t = *a; *a = *b; *b = t;
}

void sort(int *a, int i, int n){
    if(i >= n - 1) return;
    int min = i;
    for(int j = i + 1; j < n; j++){
        if(*(a + j) < *(a + min)) min = j;
    }
    if(min != i) swap(a + i, a + min);
    sort(a, i + 1, n);
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, 0, n);
    for(int i = 0; i < n; i++) printf("%d ", *(a + i));
    printf("\n");
    return 0;
}
