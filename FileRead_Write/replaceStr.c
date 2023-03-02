#include<stdio.h>
#include <string.h>

void replace_char(char *str,char c1,char c2){
    int i=0;
    while (*str != '\0'){
        if(*str == c1)
            *str = c2;

        ++str;
    }
}
int main(){

    // str trả về giá trị của biến 
    // *str trả về giá trị str trỏ đến
    // &str trả về địa chỉ của str
    char *str = "papa";
    char tmp;
    char before,after;
    scanf(" %c",&before);
    do {
        tmp = getchar();
    }
    while(tmp!='\n');
    scanf(" %c",&after);
    replace_char(str,before,after);
    while(*str != '\0'){     
        printf("%c ", *str); 
        ++str;
    }
    return 0;
}