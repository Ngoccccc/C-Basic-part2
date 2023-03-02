/*  
    Name: Tran Tien Ngoc 20205009
    Date: 22/12/2022
    commemt: Em thấy code thầy hơi khó hiểu nên em tìm hiểu và làm theo ý hiểu của em hihi
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phoneAddr_s {
  char name[20];
  char tel[12];
  union {
    char email[28];
    char key[28];
  };
} phoneAddr_t;

typedef struct node_s {
  phoneAddr_t data;
  struct node_s *left;
  struct node_s *right;
} node_t;

void showData(phoneAddr_t data)
{
    printf("Name: %s | Tel: %s| Email: %s  ", data.name, data.tel, data.email);
    printf("\n");
}

node_t *makeNode(phoneAddr_t data){
    node_t *p = (node_t *)malloc(sizeof(node_t));
    strcpy(p->data.name, data.name);
    strcpy(p->data.tel, data.tel);
    strcpy(p->data.email, data.email);
    p->left = NULL;
    p->right = NULL;
    return p;
}

node_t * insert(node_t *node, phoneAddr_t data){
    if(node == NULL) return makeNode(data);
    int c = strcmp(node->data.key, data.key);
    if (c == 0) // không insert được nếu tên trùng nhau
    {
        printf("Email %s exists, do not insert\n", node->data.key);
        return node;
    }
    else if (c < 0) //  thì add node vừa insert vào rightChild
    {
        node->right = insert(node->right, data);
        return node;
    }
    else // thì add node vừa insert vào leftChild
    {
        node->left = insert(node->left,data);
        return node;
    }
}

node_t * find(node_t *r, char *key){
    if(r == NULL) return NULL;
    int c = strcmp(r->data.key, key);
    if(c == 0){
        return r;
    }
    if(c<0) return find(r->right,key);
    return find(r->left,key);
}

void freeTree(node_t *r)
{
    if (r == NULL)
        return;
    freeTree(r->left);
    freeTree(r->right);
    free(r);
}

void inOrder(node_t *r)
{
    if (r == NULL)
        return;
    inOrder(r->left);
    showData(r->data);
    inOrder(r->right);
}
int main(){
    node_t *root;
    phoneAddr_t A[5] ={{"Ngoc","sdf","Son"},{"Nadsoc","Adu","Ngoc"},{"jdfjgoc","Adu","Tuan"},{"affd","Adu","Tien"},{"Ngoc","Adu","Quan"}};
    
    for(int i = 0; i < 5; i++){
        root = insert(root,A[i]);
    }
    inOrder(root);

    node_t *finded = find(root,"Son");
    showData(finded->data);

    
    return 0;
}