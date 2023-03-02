#include <stdio.h>
#include <stdlib.h>

// #include "ll.h"

// Must Adapt to new problem
typedef struct
{
    char id[10];
    char name[64];
    int grade;
} Student_t;

typedef struct node_s
{
    Student_t data;
    struct node_s *next;
} node_t, *root_t;

// Must Adapt to new problem
void showData(const Student_t data);

root_t llPrint(root_t root);

root_t llInit() { return NULL; }
node_t *llSeek(root_t root, int index);

root_t llInsertHead(root_t root, const Student_t data);
root_t llInsertTail(root_t root, const Student_t data);
root_t llInsertAfter(root_t root, node_t *pAElem, const Student_t data);

root_t llDeleteHead(root_t root);
root_t llDeleteTail(root_t root);
root_t llDeleteAfter(root_t root, node_t *pA);
root_t llDeleteAll(root_t root);

// Tools
int llLength(root_t root);
root_t reversell(root_t root);

void showData(Student_t data) { printf("id: %s | name: %s| grade: %d  ", data.id, data.name, data.grade);
    printf("show"); }

// Traversing a list and show
root_t llPrint(root_t root)
{
    for (node_t *p = root; p != NULL; p = p->next)
        showData(p->data);
    printf("\n");
    return root;
}

// Create a new Node
// return:
//  - on SUCCESS: return a pointer to new Node
//  - on FAIL   : return a NULL pointer
node_t *createNewNode(Student_t data)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}



node_t *llSeek(root_t root, int index)
{
    node_t *p;
    for (p = root; index > 0 && (p != NULL); index--)
        p = p->next;
    return p;
}

/* === Insert ============================================== */

root_t llInsertHead(root_t root, Student_t data)
{
    node_t *pNewNode = createNewNode(data);
    pNewNode->next = root;
    return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, Student_t data)
{
    node_t *pNewNode = createNewNode(data);

    if (root == NULL)
        return (root_t)pNewNode;

    node_t *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
        ;
    p->next = pNewNode;
    return root;
}

root_t llInsertAfter(root_t root, node_t *pAElem, const Student_t data)
{
    if (pAElem == NULL)
        return root;

    node_t *pNewNode = createNewNode(data);
    pNewNode->next = pAElem->next;
    pAElem->next = pNewNode;

    return root;
}

/* === Delete ============================================== */

root_t llDeleteHead(root_t root)
{
    if (root == NULL)
        return NULL;

    node_t *p = root->next;
    free(root);
    return (root_t)p;
}

root_t llDeleteTail(root_t root)
{
    if (root == NULL)
        return NULL;
    if (root->next == NULL)
    {
        free(root);
        return NULL;
    }

    node_t *p;
    // Find previous node of Tail
    for (p = root; p->next->next != NULL; p = p->next)
        ;

    free(p->next);
    p->next = NULL;
    return (root_t)root;
}

root_t llDeleteAfter(root_t root, node_t *pA)
{
    if ((pA == NULL) || (pA->next == NULL))
        return root;

    node_t *pToDelElem = pA->next;
    pA->next = pA->next->next;

    free(pToDelElem);
    return root;
}

root_t llDeleteAll(root_t root)
{
    node_t *p = NULL;
    for (; root != NULL; root = p)
    {
        p = root->next;
        free(root);
    }
    return NULL;
}

/* === Tools ========================================= */
int llLength(root_t root)
{
    int count;
    for (count = 0; root; count++)
        root = root->next;
    return count;
}

// to check
root_t reverseLL(root_t root)
{
    node_t *cur, *prev;

    for (cur = prev = NULL; root != NULL;)
    {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    // to check
    return root;
}




int main()
{
    root_t lst = llInit();
    Student_t sv1 = {"20205009", "Ngoc", 2};
    Student_t sv2 = {"20205012", "Tuan", 3};
    Student_t sv3 = {"2020123", "Quan", 4};
    lst = llInsertHead(lst, sv1);
    lst = llInsertTail(lst, sv3);
    // llInsertHead(lst, sv2);
    // llInsertHead(lst, sv3);

     llPrint(lst);

    // node_t *p;

    // p = llSeek(lst, 1);

    // llPrint(lst);
    lst = llDeleteAll(lst);
    return 0;
}