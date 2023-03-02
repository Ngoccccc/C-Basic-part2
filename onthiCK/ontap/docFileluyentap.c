#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _time{
    int h;
    int m;
}time;

typedef struct _lichtrinh{
    char address[40];
    time time;
    struct _lichtrinh *next;
}lichtrinh;

lichtrinh *root;

lichtrinh * llPrint(lichtrinh * root)
{
    for (lichtrinh *p = root; p != NULL; p = p->next)
        printf("%-50s %-10d %-10d\n", p->address,p->time.h,p->time.m);
    printf("\n");
    return root;
}

lichtrinh *createNewNode(char *address, int hour,int minute)
{
    lichtrinh *newNode = (lichtrinh *)malloc(sizeof(lichtrinh));
    if (newNode == NULL)
        return NULL;
    strcpy(newNode->address, address);
    newNode->time.h = hour;
    newNode->time.m = minute;
    newNode->next = NULL;
    return newNode;
}

lichtrinh* llInsertTail(lichtrinh* root, char *address,int hour, int minute)
{
    lichtrinh *pNewNode = createNewNode(address,hour,minute);

    if (root == NULL)
        return (lichtrinh*)pNewNode;

    lichtrinh *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
        ;
    p->next = pNewNode;
    return root;
}

void readData(){
    FILE * f = fopen("lichtrinh.txt","r");
    if(f == NULL){
        printf("Error opening data.txt file");
    }
    char addr[40];
    int hour;
    int minute;
    while(!feof(f)){
        fscanf(f,"%s %d %d",addr,&hour,&minute);
        root = llInsertTail(root, addr, hour, minute);
    }

}

void main(){
    readData();
    root = llPrint(root);
}