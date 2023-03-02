// Exercise 14.1: Dictionary ADT
// Thu vien gioi thieu cach hoat dong cua hahsing
// Khong xu li truong hop trung (collision)

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR (11)
#define TABLE_SIZE (13)
#define UNDEFINE ('\0')

enum { FALSE, TRUE };

typedef struct {
  char key[MAX_CHAR];  
  char word[50];      /* other fields, ie. word */
} element_t;




int hash(const char *key);

void init_table(element_t ht[]);
element_t findElement(element_t ht[], char key[]);
int insertItem(element_t ht[], element_t o);
int removeElement(element_t *ht, char *key);

int size(element_t ht[]);
int isEmpty(element_t ht[]);
void clear(element_t ht[]);

void traverse(element_t ht[]);  // Duyet
