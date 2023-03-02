#include <stdio.h>

void BlockReadWrite (FILE *fin,FILE *fout){
    int num;
    char buff[100];
    while(!feof(fin)){
        num = fread(buff,sizeof(char),100,fin);
        buff[num*sizeof(char)] = "\0";
        printf("%s",buff);
        fwrite(buff,sizeof(char),num,fout);
    }
}

int main(){
    FILE *fptr1, *fptr2;
    char filenameOut[]= "fileOut.txt";
    char filenameIn[]= "fileIn1.txt";
    

    if ((fptr1 = fopen(filenameOut, "a")) == NULL){
        printf("Cannot open %s.\n", filenameOut);
    }
    else if ((fptr2 = fopen(filenameIn, "r")) == NULL){
        fclose(fptr1);
        printf("Cannot open %s.\n", filenameIn);
    }
     
    else {
        BlockReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }
    
    return 0;

}