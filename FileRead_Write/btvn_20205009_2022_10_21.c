#include <stdio.h>

/* 
Program:LineReadWrite
Actor: Tran Tien Ngoc
MSSV: 20205009
Finish Date: 27/10
Note: ket qua thu nghiem thanh cong
Han che neu co: 
*/


void LineReadWrite(FILE *fin1,FILE *fin2, FILE *fout){
    char Str1[100];
    char Str2[100];
    char memo[2];
    int count =0;
    while ((fgets(Str1, 100, fin1) != NULL) && (fgets(Str2, 100, fin2) != NULL))  {
        
        fputc(Str1[0],fout);
        
        count++;
    }
    
    while ((fgets(Str1, 100, fin1) != NULL)){
        fputs(Str1, fout); printf("%s", Str1);
    } 
    while ((fgets(Str2, 100, fin2) != NULL)){
        fputs(Str2, fout); printf("%s", Str2);
    }
}

int main() {
    FILE *fptr1, *fptr2,*fptr3;
    char filenameOut[]= "fileOut.txt";
    char filenameIn1[]= "fileIn1.txt";
    char filenameIn2[]= "fileIn2.txt";

    if ((fptr1 = fopen(filenameOut, "a")) == NULL){
        printf("Cannot open %s.\n", filenameOut);
    }
    else if ((fptr2 = fopen(filenameIn1, "r")) == NULL){
        fclose(fptr1);
        printf("Cannot open %s.\n", filenameIn1);
    }
    else if ((fptr3 = fopen(filenameIn2, "r")) == NULL){
        fclose(fptr1);
        printf("Cannot open %s.\n", filenameIn2);
    }  
    else {
        LineReadWrite(fptr2,fptr3, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }
    return 0;
}