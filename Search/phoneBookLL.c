#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char name[20];
    char tel[20];
    char email[32];
} phoneAddr_t;

typedef struct node{
    phoneAddr_t data;
    struct node *next;
}node_t;

node_t *llInit (){return NULL;}

node_t *createNode (phoneAddr_t data){
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if(newNode == NULL){
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void showData(phoneAddr_t data)
{
    printf("name: %s | tel: %s| email: %s  ", data.name, data.tel, data.email);
    printf("\n");
}

node_t *llInsertHead(node_t *node,phoneAddr_t data){
    node_t *newNode = createNode(data);
    newNode->next = node;
    return newNode;
}

node_t * llFindByName(node_t * root, char name[])
{

    node_t * pTmp=root;
    while (pTmp != NULL)
    {
        if (strcmp(pTmp->data.name,name)==0){
            printf("tim thay");
            break;      
        } 
        pTmp = pTmp->next;
    }
    return pTmp;
    
}

int main(){
    node_t * root = llInit();
    phoneAddr_t list[]= {
        {"A","1","1@"},
        {"B","2","2@"},
        {"C","3","3@"},
        {"D","4","4@"},
        {"E","5","5@"}
    };

    for (int i = 0; i < 5; i++)
    {
        root = llInsertHead(root, list[i]);
    }

    node_t * findRoot = llFindByName(root, "E");
    showData(findRoot->data);
    return 0;
}