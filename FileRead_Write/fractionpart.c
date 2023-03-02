#include<stdio.h>

void tach(double a,int *nguyen, double *thuc){
    int b = (int) a;
    *nguyen = b;
    *thuc = a-b;
    // printf("%d\n", b);
    // printf("%g\n", a-b);
}

int main(){
    double a;
    int nguyen;
    double thuc;
    scanf("%le", &a);
    tach(a,&nguyen,&thuc);
    printf("%d\n", nguyen);
    printf("%g\n", thuc);
    return 0;
}