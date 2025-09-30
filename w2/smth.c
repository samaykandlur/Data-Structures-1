#include <stdio.h>
#include <stdlib.h>


int main(){

    int a = 50;
    int *p = &a;
    printf("%p",p);
    int g = 0;
    printf("\n%d",*p);

return 0;
}
