/*
    Author:Trần Tiến Ngọc 20205009
    Date: 17/11/2022
    Target: Student Manage
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

root_t llInsert(root_t root, Student_t data)
{

    node_t *pNewNode = createNewNode(data);

    root_t prev = NULL;
    root_t p = root;
    if (root == NULL)
    {
        return pNewNode;
    }
    else if (data.grade >= root->data.grade)
    {
        pNewNode->next = root;
        return pNewNode;
    }
    else
    {
        for (p = root; p != NULL; p = p->next)
        {
            if (p->next->data.grade <= data.grade)
            {
                pNewNode->next = p->next;
                p->next = pNewNode;
                return p;
            }
            else if (p->next == NULL)
            {
                printf("adu");
                p->next = pNewNode;
                return pNewNode;
            }
        }
    }
}

void SortList(root_t list)
{
    // for loop thứ nhất
    for (root_t p = list; p != NULL; p = p->next)
    {
        // for loop thứ hai
        for (root_t q = p->next; q != NULL; q = q->next)
        {
            if (p->data.grade < q->data.grade) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
            {
                Student_t tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
}

root_t llFindStudent(root_t root, char id[])
{

    root_t pTmp=root;
    while (pTmp != NULL)
    {
        if (strcmp(pTmp->data.id,id)==0){
            printf("tim thay");
            break;      
        } 
        pTmp = pTmp->next;
    }
    return pTmp;
    
}

root_t llDeleteStudent(root_t root, char id[])
{
    root_t prev = NULL;
    root_t p = root;
    while (strcmp(p->data.id, id) != 0)
    {
        prev = p;
        p = p->next;
    }
    if (p == NULL)
    {
    }
    else if (p == root)
    {
        root = root->next;
        return root;
        free(p);
    }
    else
    {
        prev->next = p->next;
        return root;
        free(p);
    }
}

root_t llChangeGrade(root_t root, char id[], int newGrade)
{
    root_t p = NULL;
    for (p = root; p != NULL; p = p->next)
    {
        if (strcmp(p->data.id, id) == 0)
        {

            p->data.grade = newGrade;
        }
    }
    SortList(root);
    return root;
}

int main()
{
    root_t root = llInit();

    Student_t sv[] = {{"001", "sv1", 3}, {"002", "sv2", 5}, {"003", "sv3", 6}, {"004", "sv4", 1}, {"005", "sv5", 10}};
    Student_t sv1 = {"001", "sv1", 3};
    Student_t sv2 = {"002", "sv2", 5};
    Student_t sv3 = {"003", "sv3", 6};
    Student_t sv4 = {"004", "sv4", 1};
    Student_t sv5 = {"005", "sv5", 10};

    for (int i = 0; i < 5; i++)
    {
        root = llInsertHead(root, sv[i]);
        SortList(root);
    }
    llPrint(root);

    root_t finded = llFindStudent(root, "001");

    printf("----%s--%s--%d-\n", finded->data.name, finded->data.id, finded->data.grade);
    root = llChangeGrade(root,"002",9);
    llPrint(root);
    root = llDeleteStudent(root,"001");
    llPrint(root);
    free(root);
    return 0;
}