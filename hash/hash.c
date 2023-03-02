#include <string.h>
#include "hash.h"

// ----------------------------------------------------------------------------
// Hash Code Maps: Component Sum
// ----------------------------------------------------------------------------
static const int transform(const char key[]) {
  int hk = 0;  // hash key
  for (int i = 0; key[i] != '\0'; i++) hk += key[i];
  return hk;
}

// ----------------------------------------------------------------------------
// Compression map
// ----------------------------------------------------------------------------
int hash(const char *key) { return (transform(key) % TABLE_SIZE); }





// ----------------------------------------------------------------------------
// init_table: Khoi tao hash table
// ----------------------------------------------------------------------------
void init_table(element_t ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) ht[i].key[0] = UNDEFINE;  // = NULL
}

// ----------------------------------------------------------------------------
// findElement: tim xem co phan tu co key trong hashtable ht hay khong
//    tra ve phan tu neu tim thay
//    tra ve phan tu dac biet NO_SUCH_KEY neu khong tim thay
// ----------------------------------------------------------------------------
element_t findElement(element_t ht[], char key[]) {
  static const element_t NO_SUCH_KEY = {"", ""};
  const int hash_value = hash(key);
  if (ht[hash_value].key[0] == UNDEFINE)  // strcmp(ht[hash_value].key, "") == 0
    return NO_SUCH_KEY;
  else
    return ht[hash_value];
}

// ----------------------------------------------------------------------------
// insertItem: them phan tu o vao ht
// ----------------------------------------------------------------------------
int insertItem(element_t ht[], element_t o) {
  int hash_value = hash(o.key);
  if (ht[hash_value].key[0] != UNDEFINE)
    return FALSE;  // Khong xet truong hop collision
  else {
    strcpy(ht[hash_value].key, o.key);
    strcpy(ht[hash_value].word, o.word);
    return TRUE;
  }
}

// ----------------------------------------------------------------------------
// remove Element
// ----------------------------------------------------------------------------
int removeElement(element_t *ht, char *key) {
  const int hash_value = hash(key);
  if (ht[hash_value].key[0] == UNDEFINE) {
    return -1;  // khong tim thay
  } else if (strcmp(ht[hash_value].key, key) !=
             0)  // tim thay nhung key khong khop: collision
    return FALSE;
  else {
    ht[hash_value].key[0] = UNDEFINE;  // remove
    return TRUE;
  }
}

// ----------------------------------------------------------------------------
// size - so phan tu hien co trong hash table
// ----------------------------------------------------------------------------
int size(element_t ht[]) {
  int count = 0;
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i].key[0] != UNDEFINE) count++;
  return count;
}

// ----------------------------------------------------------------------------
// isEmpty - hashTable is empty?
// ----------------------------------------------------------------------------
int isEmpty(element_t ht[]) {
  int i;
  for (i = 0; i < TABLE_SIZE; i++)
    if (ht[i].key[0] != UNDEFINE) return FALSE;
  if (i == TABLE_SIZE) return TRUE;
};

// ----------------------------------------------------------------------------
// Clear
// ----------------------------------------------------------------------------
void clear(element_t ht[]) { init_table(ht); }

// ----------------------------------------------------------------------------
// Duyet
// ----------------------------------------------------------------------------
void traverse(element_t ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i].key[0] != UNDEFINE)
      printf("(id, key, value) = (%d, %s, %s)\n", hash(ht[i].key), ht[i].key,
             ht[i].word);  // In this example value = key
}