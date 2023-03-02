/*
    Author:Trần Tiến Ngọc 20205009
    Date: 8/12/2022
    Target: binary search using link list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[8];
    char name[50];
    int grade;
} Student_t;

typedef struct node
{
    Student_t data;
    struct node *next;
} node_t, *root_t;

root_t llInit() { return NULL; }

node_t *createNewNode(Student_t data)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void showData(Student_t data)
{
    printf("id: %s | name: %s| grade: %d  ", data.id, data.name, data.grade);
    printf("\n");
}

root_t llPrint(root_t root)
{
    for (node_t *p = root; p != NULL; p = p->next)
        showData(p->data);
    printf("\n");
    return root;
}

root_t llInsertHead(root_t root, Student_t data)
{
    node_t *pNewNode = createNewNode(data);
    pNewNode->next = root;
    return (root_t)pNewNode;
}

root_t middle(root_t start, root_t last){
    if(start == NULL){
        return NULL;
    }

    root_t slow = start;
    root_t fast = start->next;

    while (fast != last)
    {
        fast = fast->next;
        if(fast != last){
            slow = slow->next;

            fast = fast->next;
        }
    }
    
    return slow;

}

root_t binarySearchByGrade(root_t lst, const int key){
    root_t start = lst;
    root_t last = NULL;

    do{
        root_t mid = middle(start, last);

        if(mid == NULL){
            return NULL;
        }

        if(mid->data.grade == key){
            return mid;
        }

        else if(mid->data.grade < key){
            start = mid->next;
        }
        else last = mid;
    }
    while(last == NULL || last != start);

    return NULL;
}

root_t binarySearchByName(root_t lst, char *key){
    root_t start = lst;
    root_t last = NULL;

    do{
        root_t mid = middle(start, last);

        if(mid == NULL){
            return NULL;
        }

        if(strcmp(mid->data.name,key)==0){
            return mid;
        }

        else if(strcmp(mid->data.name,key)<0){
            start = mid->next;
        }
        else last = mid;
    }
    while(last == NULL || last != start);

    return NULL;
}

void SortListByGrade(root_t list)
{
    // for loop thứ nhất
    for (root_t p = list; p != NULL; p = p->next)
    {
        // for loop thứ hai
        for (root_t q = p->next; q != NULL; q = q->next)
        {
            if (p->data.grade > q->data.grade) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
            {
                Student_t tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
}

void SortListByName(root_t list){
    for (root_t p = list; p != NULL; p = p->next)
    {
        // for loop thứ hai
        for (root_t q = p->next; q != NULL; q = q->next)
        {
            if (strcmp(p->data.name,q->data.name)>0) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
            {
                Student_t tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
}

int main()
{
    root_t root = llInit();

    Student_t sv[] = {{"001", "a", 3}, {"002", "f", 5}, {"003", "c", 6}, {"004", "b", 1}, {"005", "z", 10}};

    for (int i = 0; i < 5; i++)
    {
        root = llInsertHead(root, sv[i]);
        SortListByName(root);
    }
    llPrint(root);
    // root_t finded = binarySearchByGrade(root, 6);
    // showData(finded->data);
    root_t finded = binarySearchByName(root, "b");
    showData(finded->data);
    free(root);
    return 0;
}