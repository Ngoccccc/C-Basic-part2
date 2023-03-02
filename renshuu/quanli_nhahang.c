#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student_s{
    char mssv[10];
    char name[30];
    float grade;
}Student;

void writeFile(Student data){
    FILE *f = fopen("SV.dat","ab");
    fwrite(&data,sizeof(Student),1,f);
    fclose(f);
}

void input(){
   Student data;
   do{
        
        printf("Nhap thong tin SV:\n");
        printf("Nhap MSSV: "); scanf("%s",data.mssv);
        printf("Nhap name: "); scanf("%s",data.name);
        printf("Nhap grade: "); scanf("%f",&data.grade);
        while(data.grade<0 || data.grade>10){
            printf("Nhap lai so diem tu 0 -> 10: ");
            scanf("%f",&data.grade);
        };

        if(strcmp(data.name,"###")!=0){
            writeFile(data);
            printf("---------------------------\nNhap sinh vien moi:\n");
        }
    }
    while(strcmp(data.name,"###")!=0);
}

void readFile(Student *A){
    FILE *f = fopen("SV.dat","rb");
    int i=0;
    Student sv;
    while(!feof(f)){
        fread(&A[i++],sizeof(Student),1,f);
    }
}
void sortStudent(Student A[],int n){
    
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(strcmp(A[i].mssv,A[j].mssv)>0){
                Student tmp = A[i];
                A[i]=A[j];
                A[j]=tmp;
            }
        }

    }
}
int main(){
    Student dssv[100];
    readFile(dssv);
    int n = sizeof(dssv)/sizeof(dssv[0]);
    sortStudent(dssv,3);
    for(int i = 0; i<3;i++){
        printf("%s  ",dssv[i].mssv);
    }

    return 0;
}