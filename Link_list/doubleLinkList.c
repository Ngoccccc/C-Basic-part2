
/*
    Author: Tran Tien Ngoc 20205009
    Date: 23-11-2022
    Muc tieu: cai dat Doule link list
    Updated:
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct {
  int id;
} data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
  struct node_s *prev;
} node_t, *root_t;

// Must Adapt to new problem
void showData(const data_t data);

root_t dllPrint(root_t root);

root_t dllInit();
node_t *dllSeek(root_t root, int index);

root_t dllInsertHead(root_t root, const data_t data);
root_t dllInsertTail(root_t root, const data_t data);
root_t dllInsertAfter(root_t root, node_t *pAElem, const data_t data);

root_t dllDeleteHead(root_t root);
root_t dllDeleteTail(root_t root);
root_t dllDeleteAfter(root_t root, node_t *pA);
root_t dllDeleteAll(root_t root);

// Tools
int dllLength(root_t root);




void showData(data_t data) { printf("%d ", data.id); }

// Traversing a list and show
root_t dllPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return root;
}

// Create a new Node
// return:
//  - on SUCCESS: return a pointer to new Node
//  - on FAIL   : return a NULL pointer
node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

root_t dllInit() { return NULL; }

node_t* dllSeek(root_t root, int index) {
  node_t* p;
  for (p = root; index > 0 && (p != NULL); index--) p = p->next;
  return p;
}

/* === Insert ============================================== */

root_t dllInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  root->prev = pNewNode;
  return (root_t)pNewNode;
}

root_t dllInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  pNewNode->prev = p;
  return root;
}

root_t dllInsertAfter(root_t root, node_t* pAElem, const data_t data) {
  if (pAElem == NULL) return root;

  node_t* pNewNode = createNewNode(data);
  pNewNode->next = pAElem->next;
  pAElem->next->prev = pNewNode;
  pAElem->next = pNewNode;
  pNewNode->prev = pAElem;

  return root;
}

root_t dllInsertBefore(root_t root, node_t* pAElem, const data_t data) {
  if (pAElem == NULL) return root;

  node_t* pNewNode = createNewNode(data);
  pNewNode->next = pAElem;
  pAElem->prev->next = pNewNode;
  pNewNode->prev = pAElem->prev;
  pAElem->prev = pNewNode;

  return root;
}

/* === Delete ============================================== */

root_t dllDeleteHead(root_t root) {
  if (root == NULL) return NULL;

  node_t* p = root->next;
  p->prev = NULL;
  free(root);
  return (root_t)p;
}

root_t dllDeleteTail(root_t root) {
  if (root == NULL) return NULL;
  if (root->next == NULL) {
    free(root);
    return NULL;
  }

  node_t* p;
  // Find previous node of Tail
  for (p = root; p->next->next != NULL; p = p->next)
    ;

  free(p->next);
  p->next = NULL;
  return (root_t)root;
}

root_t dllDelete(root_t root, node_t* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;

  node_t* pToDelElem = pA;
  pA->prev->next = pA->next;
  pA->next->prev = pA->prev;

  free(pToDelElem);
  return root;
}

root_t dllDeleteAfter(root_t root, node_t* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;

  node_t* pToDelElem = pA->next;
  pA->next = pA->next->next;
  pA->next->prev = pA;

  free(pToDelElem);
  return root;
}

root_t dllDeleteBefore(root_t root, node_t* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;

  node_t* pToDelElem = pA->prev;
  pA->prev->prev->next = pA;
  pA->prev= pA->prev->prev;

  free(pToDelElem);
  return root;
}

root_t dllDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

/* === Tools ========================================= */
int dllLength(root_t root) {
  int count;
  for (count = 0; root; count++) root = root->next;
  return count;
}

// to check
root_t reverseLL(root_t root) {
  node_t *cur, *prev;

  for (cur = prev = NULL; root != NULL;) {
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  // to check
  return root;
}


data_t convert(int i) {
  data_t data = {i};
  return data;
}





int main() {
  root_t lst = dllInit();
  for (int i = 0; i < 5; i++) {
    lst = dllInsertTail(lst, convert(i));
  }
  dllPrint(lst);

  node_t *p;

  p = dllSeek(lst, 2);
  
  lst = dllDeleteAfter(lst,p);
  lst = dllDeleteBefore(lst,p);

  dllPrint(lst);

  lst = dllDeleteAll(lst);

  return 0;
}