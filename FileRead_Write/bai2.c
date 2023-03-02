#include<stdio.h>

int check(int A[],int B[], int lenA, int lenB){

    if(lenA != lenB) return 0;
    else for (int i = 0; i < lenA; i++)
    {
        if(A[i] != B[i]){
            return 0;
        }
    }
    return 1;
    
}

int main(){
    int A[5]={1,2,22,4,5};
    int B[5]={1,2,3,4,5};
    int lenA = sizeof(A)/sizeof(A[0]), lenB =sizeof(B)/sizeof(B[0]);
    printf("%d",lenA);
    printf("Check: %d\n",check(A,B,lenA,lenB));
}