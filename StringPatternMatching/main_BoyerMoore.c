#define _DEBUG_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "strMatching.h"

#define MAX (2000)

// output co kich thuoc n+1 ki tu
// n so ki tu co nghia trong output
// output[n] chua ki tu '\0' de tien viec hien thi
void iniStr(const char setOfChar[], const int setLen, char output[], int n) {
  static int initialized = 0;
  if (!initialized) {
    srand(time(0));
    initialized = 1;
  }

  for (int i = 0, j = 0; i < n; i++) {
    j = rand() % setLen;
    output[i] = setOfChar[j];
  }
  output[n] = '\0';
}





// L có kích thước 256 phần tử, mỗi phần tử kiểu số nguyên
void LastOccurenceFunc(const char P[], const char setOfChar[], int L[]) {
  const int lenSetOfChar = strlen(setOfChar);
  const int m = strlen(P);

  memset(L, -1, 256);

  for (int i = 0; i < lenSetOfChar; i++) {
    int j;
    char c = setOfChar[i];
    for (j = m - 1; (j >= 0) && (P[j] != c); j--)
      ;
    L[c] = (j == -1) ? -1 : j;  // not found = -1,
                                // found = largest index i such that P[i] == c
  }

#ifdef _DEBUG_
  printf("L vector: ");
  for (int i = 'a'; i <= 'z'; i++)
    if (L[i] != -1) printf("%c:%d ", i, L[i]);
#endif
}


int min(int x, int y) { return x < y ? x : y; }

int BoyerMooreMatch(const char T[], const char P[], const char setOfChar[]) {
  static int L[256];
  const int lenSetOfChar = strlen(setOfChar);
  LastOccurenceFunc(P, setOfChar, L);

  const int n = strlen(T);
  const int m = strlen(P);

  int i;  // chỉ số quét T
  int j;  // chỉ số quét P
  for (i = j = m - 1; i < n;) {
    if (T[i] == P[j]) {
      if (j == 0) {
        return i;  // match at i
      } else
        i--, j--;
    } else {
      // character jump
      int l = L[T[i]];
      i += m - min(j, l + 1);  // update chỉ số quét T
      j = m - 1;               // reset chỉ số quét P
    }
  }
  return -1;
}




int main() {
  // ==============================================
  // Boyer Moore Match
  // ==============================================

  // Example
  char setOfChar[] = "abcdefghijklmnopqrstuvwxyz";
  const int N = strlen(setOfChar);
  char t[MAX + 1] = "a pattern matching algorithm";
  char p[50] = "rithm";

  // Exercise 13.2
  // char setOfChar[] = "abcdef";
  // const int N = strlen(setOfChar);
  // char t[MAX + 1];
  // char p[5];
  // iniStr(setOfChar, strlen(setOfChar), t, MAX);
  // iniStr(setOfChar, strlen(setOfChar), p, sizeof(p) - 1);

  printf("\nText   :%s\n", t);
  printf("Pattern: %s\n", p);

  int retVal = BoyerMooreMatch(t, p, setOfChar);

  if (retVal == -1)
    printf("\nSubString not found\n");
  else
    printf("\nfound: '%d %s'\n", retVal, &t[retVal]);

  return 0;
}