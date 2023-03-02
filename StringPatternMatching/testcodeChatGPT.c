#include <stdio.h>
#include <string.h>

int brute_force_match(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int count = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return count;
        }
        else{
            count++;
        }
    }

    return -1;
}

int boyer_moore_match(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int count = 0;
    int last[256];
    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        last[(unsigned char) pattern[i]] = i;
    }

    int i = m - 1;
    int k = m - 1;
    while (i < n) {
        if (text[i] == pattern[k]) {
            if (k == 0) {
                return count;
            } else {
                count++;
                i--;
                k--;
            }
        } else {
            int j = last[(unsigned char) text[i]];
            i += m - (k > j + 1 ? k : j + 1);
            k = m - 1;
        }
    }

    return -1;
}

int KMPMatch(const char *text, const char *pattern) {
int n = strlen(text);
int m = strlen(pattern);
int prefix[m];
compute_prefix(pattern, prefix);
int count = 0;
int q = 0;
for (int i = 0; i < n; i++) {
    while (q > 0 && pattern[q] != text[i]) {
        q = prefix[q - 1];
        count++;
    }
    if (pattern[q] == text[i]) {
        q++;
    }
    count ++;
    if (q == m) {
        return count;
    }
    
}

return -1;
}
void compute_prefix(const char *pattern, int *prefix) {
int m = strlen(pattern);
prefix[0] = 0;
int k = 0;
for (int q = 1; q < m; q++) {
    while (k > 0 && pattern[k] != pattern[q]) {
        k = prefix[k - 1];
    }
    if (pattern[k] == pattern[q]) {
        k++;
    }
    prefix[q] = k;
}
}

int main() {
    char text[] = "the quick brown fox jumps over the lazy dog";
    char pattern[] = "mps";
    int result1 = brute_force_match(text, pattern);
    if (result1 == -1) {
        printf("Not found\n");
    } else {
        printf("Found at index %d\n", result1);
    }
    int result2 = boyer_moore_match(text, pattern);
    if (result2 == -1) {
        printf("Not found\n");
    } else {
        printf("Found at index %d\n", result2);
    }
    int result3 = KMPMatch(text, pattern);
    if (result3 != -1) {
        printf("Match found at index %d\n", result3);
    } else {
        printf("Match not found\n");
    }
    return 0;
}