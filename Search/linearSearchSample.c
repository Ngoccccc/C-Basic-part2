#include <stdio.h>
#include <string.h>
typedef char T;

// return index of items where items[index] == key
int linearSearch(T items[], int siz, T key) {
  for (int i = 0; i < siz; i++)
    if (key == items[i]) return i;
  return -1;  // no match
}

int main(void) {
  char *str = "asdf";
  int index = linearSearch(str, strlen(str), 'd');
  printf("%d", index);

  return 0;
}