#include <stdio.h>
#include <string.h>

typedef char T;

// Vì áp dụng kĩ thuật Sentinel nên mảng a phải có kích thước siz+1
int linearSentinelSearch(T a[], int siz, T key) {
  int i = 0;
  for (a[siz] = key; a[i] != key; i++) ;
  if (i == siz) return -1;
  return i;
}

int main() {
  char str[20] = "asdf";
  int index = linearSentinelSearch(str, strlen(str), 'd');
  printf("%d", index);

  return 0;
}