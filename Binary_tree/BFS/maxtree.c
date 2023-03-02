#include<stdio.h>
#include<stdlib.h>
typedef struct _tree{
    int data;
   struct _tree *left;
   struct _tree *right;
}tree;

tree * NEW (int data,tree * left,tree * right){
    tree * init = (tree *) malloc(sizeof(tree));
    init->data = data;
    init->left = left;
    init->right = right;
    return init;
}

int max(int a, int b){
    return a > b ? a : b;
}

tree * handle(int a[],int l,int r){
    int m = (l+r)/2;
    tree * node = NEW(a[m],NULL,NULL);
    if(l==r) return node;
    node->left = handle(a,l,m);
    node->right = handle(a,m+1,r);
    node->data = max(node->left->data,node->right->data);
    return node;
}

int main(){
    int A[] = {1,5,8,6,4,3};
    tree * root=handle(A,0,5);
    printf("%d",root->data);
    return 0;
}