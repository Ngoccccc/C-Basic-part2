/*
    Author:Trần Tiến Ngọc 20205009
    Date: 8/12/2022
    Target: Verifying 2 list
 */


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

int check(phoneAddr_t a, phoneAddr_t b){
    if(strcmp(a.name,b.name) != 0) return 1;
    if(strcmp(a.email,b.email) != 0) return 1;
    if(strcmp(a.tel,b.tel) != 0) return 1;
    return 0;
}

int check2(phoneAddr_t a, phoneAddr_t b){
    if(strcmp(a.name,b.name) == 0 && strcmp(a.email,b.email) == 0 && strcmp(a.tel,b.tel) == 0) return 1;
    if(strcmp(a.name,b.name) == 0 || strcmp(a.email,b.email) == 0 || strcmp(a.tel,b.tel) == 0) return 0;
    return 1;
} 



phoneAddr_t searchDataByName(phoneAddr_t list[],char name[],int n){
    for(int i=0;i<n;i++){
        if(strcmp(list[i].name,name)==0){
            printf("tim thay");
            return list[i];

        }
    }

}
void verify1(phoneAddr_t lst1[], phoneAddr_t lst2[], int n, int m) {
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(check(lst1[i],lst2[j])==0){
                count++;
            }
        }
        if(count==0){
            printf("not found %s in list 2\n",lst1[i].name);
        }
        count =0;
    }

    printf("--------------------------\n");

    for(int i=0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(check(lst1[j],lst2[i])==0){
                count++;
            }
        }
        if(count==0){
            printf("not found %s in list 1\n",lst2[i].name);
        }
        count =0;
    }

    printf("--------------------------\n");


    for(int i=0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(check2(lst1[j],lst2[i])==0){
                printf("phan tu co ten: %s cua list 1 gan giong phan tu co ten: %s cua list 2",lst1[j].name,lst2[i].name);
            }
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
    phoneAddr_t b[] = {
        {"A","1","1@"},
        {"j","5","5@"}
    };
    verify1(a,b,5,2);

    return 0;
}

