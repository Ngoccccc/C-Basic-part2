#include "hash.h"

#include <string.h>

element_t *D[TABLE_SIZE];  // <===

// Hash Code Maps
// Component Sum
static const int transform(const char *key) {
  int number;
  for (number = 0; (*key) != 0; key++) number += *key;
  return number;
}

// Compression map
int hash(const char *key) { return (transform(key) % TABLE_SIZE); }

// ====================================
//
// ====================================

void init_table(element_t *ht[]) {  // <===
  clear(ht);
}

void clear(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    clearbucket(ht, i);
  }
}

void clearbucket(element_t *ht[], int b) {
  element_t* p = NULL;
  for (; ht[b] != NULL; ht[b] = p) {
    p = ht[b]->next;
    free(ht[b]);
  }
}

element_t *findElement(element_t *ht[], char key[]) {
  const int hash_value = hash(key);
  if (ht[hash_value] == NULL)
    return NULL;
  else  {
    while(ht[hash_value]!=NULL){
      if(strcmp(ht[hash_value]->key,key)==0){
        printf("tim thay");
        return ht[hash_value];
      }
      ht[hash_value] = ht[hash_value]->next;
    }
    return NULL;
  }
}

int insertItem(element_t *ht[], element_t o) {
  int hash_value = hash(o.key);
  element_t *pNewElement = (element_t *)malloc(sizeof(element_t) * 1);
  strcpy(pNewElement->key, o.key);
  strcpy(pNewElement->word, o.word);
  pNewElement->next = NULL;

  if (ht[hash_value] == NULL) {
    ht[hash_value] = pNewElement;
    return TRUE;
  } else {
    for(element_t *e = ht[hash_value]; e->next != NULL; e=e->next);
    ht[hash_value]->next = pNewElement;
    return TRUE;
  }
}

int removeElement(element_t *ht[], char key[]) {
  int hash_value = hash(key);
  element_t *p1 = ht[hash_value];

  if (p1 == NULL)
    return -1;  // khong tim thay
  else {
    element_t * prev = NULL;
    element_t * p = ht[hash_value];
    while (strcmp(p->key, key) != 0)
    {
        prev = p;
        p = p->next;
    }
    if (p == NULL)
    {
      return -1;
    }
    else if (p == ht[hash_value])
    {
        ht[hash_value] = ht[hash_value]->next;
        return 1;
        free(p);
    }
    else
    {
        prev->next = p->next;
        return 1;
        free(p);
    }
  }
}

int isEmpty(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i] != NULL) return FALSE;
  return TRUE;
};

void traverse(element_t *ht[]) {
  for (int b = 0; b < TABLE_SIZE; b++) {
    printf("\nBucket %d\n", b);
    _traversebucket(ht, b);
  }
}

void _traversebucket(element_t *ht[], int b) {
  for (element_t *p = ht[b]; p != NULL; p = p->next){
    printf("key: %s | value: %s|", p->key, p->word);   
    printf("\n");
  }
    
}