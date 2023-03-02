#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _FCclub{
    char name[20];
    int point;
    struct _FCclub *left;
    struct _FCclub *right;
}FCclub;

FCclub *root = NULL;

FCclub *makeNode (char name[20]){
    FCclub *p = (FCclub *) malloc(sizeof(FCclub));
    strcpy(p->name,name);
    p->point = 0;
    p->left = NULL;
    p->right = NULL;
    return p;
}


FCclub * insert(FCclub *node, char name[20]){
    if(node == NULL) return makeNode(name);
    int c = strcmp(node->name, name);
    if (c == 0) // không insert được nếu tên trùng nhau
    {
        printf("Email %s exists, do not insert\n", node->name);
        return node;
    }
    else if (c < 0) //  thì add node vừa insert vào rightChild
    {
        node->right = insert(node->right, name);
        return node;
    }
    else // thì add node vừa insert vào leftChild
    {
        node->left = insert(node->left,name);
        return node;
    }
}

FCclub * find(FCclub *r, char name[20]){
    if(r == NULL) return NULL;
    int c = strcmp(r->name, name);
    if(c == 0){
        return r;
    }
    if(c<0) return find(r->right,name);
    return find(r->left,name);
}

void ReadData(){
    FILE * f = fopen("BongDa.txt","r");
    if(f == NULL){
        printf("ko doc duoc file");
    }
    char team1[20];
    char team2[20];
    int goal1;
    int goal2;
    while (!feof(f))
    {
        fscanf(f,"%s %s %d %d",team1,team2, &goal1,&goal2);
        FCclub * buff1 = find(root,team1);
        if(buff1 == NULL) root = insert(root,team1);
        FCclub * buff2 = find(root,team2);
        if(buff2 == NULL) root = insert(root,team2);
        if(goal1>goal2){
            FCclub * club1 = find(root,team1);
            club1->point += 3;
        }
        else if(goal1<goal2){
            FCclub * club2 = find(root,team2);
            club2->point += 3;
        }
        else{
            FCclub * club1 = find(root,team1);
            club1->point += 1;
            FCclub * club2 = find(root,team2);
            club2->point += 1;
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