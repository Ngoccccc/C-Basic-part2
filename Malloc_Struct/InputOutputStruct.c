#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char name[64];
    char phone[12];
    char email[64];
} info_t;

int main(){
    FILE *f;
    info_t info[3];
    info_t doc[3];
    for(int i=0; i<3; i++){
        scanf("%s %s %s",info[i].name,info[i].phone,info[i].email);
    }
    f = fopen("info.dat", "w+b");
    if(f == NULL){
        printf("error");
        return 1;
    }
    int irc = fwrite(info,sizeof(info),3,f);
    printf("fwrite return code: %d\n",irc);
    int num = fread(doc,sizeof(info),3,f);
    info[num*sizeof(info)] = "\0";
    printf("%s",info);
    return 0;
}