#include<stdio.h>


int main() {
    FILE *fptr1, *fptr2;
    char filenameOut[]= "fileOut.txt";
    char filenameIn1[]= "fileIn1.txt";
    char Str[100];
    int count=1;
    if ((fptr1 = fopen(filenameOut, "w")) == NULL){
        printf("Cannot open %s.\n", filenameOut);
    }
    else if ((fptr2 = fopen(filenameIn1, "r")) == NULL){
        fclose(fptr1);
        printf("Cannot open %s.\n", filenameIn1);
    }
    else {
        while ((fgets(Str, 100, fptr2) != NULL))  {
        fprintf(fptr1,"%d %s",count,Str);
        count++;
    }
        fclose(fptr1);
        fclose(fptr2);
    }
    return 0;
}