#include <stdio.h>
#define NOT_FOUND (-1)
typedef int T;

int binarySearch(T a[], const int n, const T key) {
  int low = 0;
  int high = n - 1;
  int mid = (low + high) / 2;
  int count = 0;
  for (; low <= high; mid = (low + high) / 2) {
    printf("Mid is: %d\n", mid);
    count++;
    if (a[mid] == key){
        printf("count is: %d\n",count);
        return mid;
    }
      
    else if (a[mid] < key)  // <---
      low = mid + 1;
    else  // (key < a[mid]) // <---
      high = mid - 1;
  }
  printf("count is: %d\n",count);
  return NOT_FOUND; /* NotFound is defined as -1 */
}

int main() {
  int a[100];
  
  for (int i = 1; i <=100; i++) {
    a[i]= i;
  }

  printf("%d",binarySearch(a,100,77));

  return 0;
}