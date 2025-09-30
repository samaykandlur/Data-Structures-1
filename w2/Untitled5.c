#include <stdio.h>
#include <stdlib.h>

void read(int **m, int r, int c) {
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            scanf("%d", *(m + i) + j);
}

void disp(int **m, int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++)
            printf("%d ", *(*(m + i) + j));
        printf("\n");
    }
}

int **mul(int **a, int r1, int c1, int **b, int r2, int c2) {
    int **res = malloc(r1 * sizeof(int*));
    for(int i=0; i<r1; i++) res[i] = malloc(c2 * sizeof(int));

    for(int i=0; i<r1; i++)
        for(int j=0; j<c2; j++) {
            *(*(res + i) + j) = 0;
            for(int k=0; k<c1; k++)
                *(*(res + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
        }
    return res;
}

void freeM(int **m, int r) {
    for(int i=0; i<r; i++) free(m[i]);
    free(m);
}

int main() {
    int r1,c1,r2,c2, **m1,**m2,**p;

    printf("Enter rows and cols of matrix 1: ");
    scanf("%d%d", &r1,&c1);
    printf("Enter rows and cols of matrix 2: ");
    scanf("%d%d", &r2,&c2);

    if(c1!=r2) {
        printf("Matrix multiplication not possible\n");
        return 1;
    }

    m1=malloc(r1*sizeof(int*));
    m2=malloc(r2*sizeof(int*));
    for(int i=0;i<r1;i++) m1[i]=malloc(c1*sizeof(int));
    for(int i=0;i<r2;i++) m2[i]=malloc(c2*sizeof(int));

    printf("Enter matrix 1 elements:\n");
    read(m1,r1,c1);
    printf("Enter matrix 2 elements:\n");
    read(m2,r2,c2);

    p=mul(m1,r1,c1,m2,r2,c2);

    printf("Matrix 1:\n");
    disp(m1,r1,c1);
    printf("Matrix 2:\n");
    disp(m2,r2,c2);
    printf("Product matrix:\n");
    disp(p,r1,c2);

    freeM(m1,r1);
    freeM(m2,r2);
    freeM(p,r1);

    return 0;
}
