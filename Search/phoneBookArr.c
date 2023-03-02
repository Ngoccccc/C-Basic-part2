#include <stdio.h>
#include <string.h>
typedef struct {
    char name[20];
    char tel[20];
    char email[20];
} phoneAddr_t;

void showData(phoneAddr_t data){
    printf("name: %s\n", data.name);
    printf("tel: %s\n", data.tel);
    printf("email: %s\n", data.email);
}

void inputData(phoneAddr_t list[],phoneAddr_t data,int n){
    for(int i=0;i<n;i++){
        strcpy(list[i].name,data.name);
        strcpy(list[i].tel,data.tel);
        strcpy(list[i].email,data.email);
    }
}

phoneAddr_t searchDataByName(phoneAddr_t list[],char name[],int n){
    for(int i=0;i<n;i++){
        if(strcmp(list[i].name,name)==0){
            printf("tim thay");
            return list[i];

        }
    }

}

int readFromFile(char fn[],phoneAddr_t buf[],int elemNum){
    FILE *file = fopen(fn,"rb");
    
    int n = fread(buf,sizeof(phoneAddr_t),elemNum,file);
    fclose(file);
    return n;
}

int main(){
    
    phoneAddr_t a[] = {
        {"A","1","1@"},
        {"B","2","2@"},
        {"C","3","3@"},
        {"D","4","4@"},
        {"E","5","5@"}
    };
    phoneAddr_t list[10];
    int n = readFromFile("test.dat",list,5);
    printf("%d\n",n);
    for(int i = 0; i < n; i++){
        showData(list[i]);
    }

    return 0;
}

