#include <stdio.h>
#include<string.h>
#include <stdlib.h>

char *my_strcat(char *str1,char *str2){
    int len1,len2;
    char *result;
    len1 = strlen(str1);
    len2 = strlen(str2);
    result = (char *)malloc((len1+len2+1)*sizeof(char));
    strcpy(result,str1);
    strcpy(result+len1,str2);
    return result;
}

int main(){
    char str1[]= "hello_";
    char str2[] = "world";
    char *result;
    result = my_strcat(str1,str2);
    printf("%s",result);
    return 0;
}