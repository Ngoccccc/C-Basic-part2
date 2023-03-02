#include <stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int i=-1;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    int *p = (int*)malloc(n*sizeof(int));
    
    do{
        i++;
        scanf("%d",&p[i]);
    }
    while(p[i]!=0);
    return 0;
}