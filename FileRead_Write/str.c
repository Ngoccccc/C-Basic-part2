#include <stdio.h>
#include <string.h>

void replaces(char str[],char before,char after){
    int n = strlen(str);
    for(int i = 0; i < n; i++){
        if(str[i] == before){
            str[i] = after;
        }
    }
}

int main(){
    char str[10];
    char tmp;
    char before,after;
    scanf("%s",str);
    scanf(" %c",&before);
    do {
        tmp = getchar();
    }
    while(tmp!='\n');
    scanf(" %c",&after);
    replaces(str,before,after);
    printf("%s\n",str);
}