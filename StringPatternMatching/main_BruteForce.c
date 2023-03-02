// #define _COUNT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int BruteForceMatch(const char T[], const char P[]) {
  int count = 0;
  const int n = strlen(T);
  const int m = strlen(P);

  int i;
  for (i = 0, count = 0; i < n - m; i++) {
    // test shift i of the pattern
    int j;
    count++;
    for (j = 0; (j < m) && (T[i + j] == P[j]); j++, count++)
      ;
    if (j == m) {
#ifdef _COUNT_
      printf("BruteForceMatch, number of compare: %d\n", count);
#endif
      return i;  // match at i
    }
  }
#ifdef _COUNT_
  printf("BruteForceMatch, number of compare: %d\n", count);
#endif
  return -1;
}

int main() {
  // ==============================================
  // Brute Force Matching
  // ==============================================

  char setOfChar[] = "abcdef";
  const int N = strlen(setOfChar);
  char t[MAX + 1];
  char p[6];
  iniStr(setOfChar, strlen(setOfChar), t, MAX);
  iniStr(setOfChar, strlen(setOfChar), p, sizeof(p) - 1);

  printf("\nText   :%s\n", t);
  printf("Pattern: %s\n", p);

  int retVal = BruteForceMatch(t, p);

  if (retVal == -1)
    printf("\nSubString not found\n");
  else
    printf("\nfound: '%d %s'\n", retVal, &t[retVal]);

  return 0;
}