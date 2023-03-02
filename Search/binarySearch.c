#include<stdio.h>

int binary_search(int A[],int low,int high,int key){
    static int count = 0;
    count++;
    int mid = (high + low)/2;
    printf("mid = %d\n",mid);
    if(A[mid] == key) {
        printf("count = %d",count);
        return mid;}
    else if(A[mid]>key) return binary_search(A,low,mid,key);
    else return binary_search(A,mid+1,high,key);
    return 0;
}

int main(){
    int A[101];
    for(int i=1;i<=100;i++){
        A[i] = i;
    }
    printf("%d\n",binary_search(A,1,100,77));
    return 0;
}