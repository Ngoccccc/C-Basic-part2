#include <stdio.h>
#include <ctype.h>
int main()
{
    char filename[100] = "lab1w.txt";
    FILE *f = fopen(filename, "r");
    FILE *fout = fopen("writeFile.txt", "w");
    if (f == NULL)
    {
        printf("Error: Cannot open lab1w.txt\n");
    }
    int c;
    while (( c = fgetc(f)) != EOF)
    {   
        if('a' <= c && c <= 'z'){
            c = toupper(c);
        }
        else if('A' <= c && c <= 'Z'){
            c = tolower(c);
        }
        fputc(c, fout);
        putchar(c);
    }
    fclose(f);
}