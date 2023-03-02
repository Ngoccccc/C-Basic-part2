#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]){
    FILE   *fr,*fw;
    int a;
    int count=1;
    char Str[100];
    char *fn_read = argv[1];
    char fn_write[] = "fileOut.txt";
    fw = fopen(fn_write, "w");
    fr = fopen(fn_read, "r");
    while ((fgets(Str, 100, fr) != NULL))  {
        fprintf(fw,"%d %s",count,Str);
        count++;
    }
    return 0;
}