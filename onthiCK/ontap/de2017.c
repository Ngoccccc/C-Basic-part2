#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _FCclub{
    int id;
    char name[20];
    int point;
    int doithu[10];
    int sobanthang;
    int sobanthua;
    struct _FCclub *left;
    struct _FCclub *right;
}FCclub;

FCclub *root = NULL;

FCclub *makeNode (char name[20],int id){
    FCclub *p = (FCclub *) malloc(sizeof(FCclub));
    strcpy(p->name,name);
    p->id = id;
    p->point = 0;
    p->left = NULL;
    p->right = NULL;
    return p;
}


FCclub * insert(FCclub *node, char name[20],int id){
    if(node == NULL) return makeNode(name,id);
    
    if (node->id == id) // không insert được nếu tên trùng nhau
    {
        printf("Email %s exists, do not insert\n", node->name);
        return node;
    }
    else if (node->id < id) //  thì add node vừa insert vào rightChild
    {
        node->right = insert(node->right, name,id);
        return node;
    }
    else // thì add node vừa insert vào leftChild
    {
        node->left = insert(node->left,name,id);
        return node;
    }
}

FCclub * find(FCclub *r, int id){
    if(r == NULL) return NULL;
    
    if(r->id == id) {
        return r;
    }
    if(r->id < id) return find(r->right,id);
    return find(r->left,id);
}

void ReadData(){
    FILE * f = fopen("lichthidau.txt","r");
    if(f == NULL){
        printf("ko doc duoc file");
    }
    int sodoi;
    int id;
    char name[20];
    fscanf(f, "%d", &sodoi);
    for(int i = 0; i<sodoi;i++){
        fscanf(f,"%d %s",&id,name);
        root = insert(root,name,id);
    }
    char str[20];
    int vongdau;
    while(!feof(f)){
        fscanf(f,"%s %d",str,&vongdau);
        int id1,id2;
        for(int j =0; j<sodoi/2;j++){
            fscanf(f,"%d %d", &id1,&id2);
            FCclub *buff1 = find(root,id1);
            FCclub *buff2 = find(root,id2);
            buff1->doithu[j+1] = id2;
            buff2->doithu[j+1] = id1;
        }
    }
}

void inOrder(FCclub *r)
{

    if (r == NULL)
        return;
    inOrder(r->left);
    printf("%-5s   %d\n", r->name, r->point);
    inOrder(r->right);

}

void main(){
    ReadData();
    inOrder(root);
}