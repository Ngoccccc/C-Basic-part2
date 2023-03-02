#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _Price {
    float giamo;
    float giadong;
} Price;

typedef struct _cophieu{
    Price price[11];
    char key[10];
    int day;
    int songaytang;
    float trungbinh;
    struct _cophieu *left;
    struct _cophieu *right;
} cophieu;

cophieu *root = NULL;

cophieu *maxCP;
cophieu *makeNode (char *name, float op, float cp){
    cophieu *p = (cophieu *) malloc(sizeof(cophieu));
    strcpy(p->key,name);
    p->day  = 0;
    p->price[0].giamo = op;
    p->price[0].giadong = cp;
    p->left = NULL;
    p->right = NULL;
    return p;
}


cophieu * insert(cophieu *node, char *key, float op, float cp){
    if(node == NULL) return makeNode(key,op,cp);
    int c = strcmp(node->key, key);
    if (c == 0) // không insert được nếu tên trùng nhau
    {
        printf("Email %s exists, do not insert\n", node->key);
        return node;
    }
    else if (c < 0) //  thì add node vừa insert vào rightChild
    {
        node->right = insert(node->right, key, op, cp);
        return node;
    }
    else // thì add node vừa insert vào leftChild
    {
        node->left = insert(node->left,key, op, cp);
        return node;
    }
}

cophieu * find(cophieu *r, char *key){
    if(r == NULL) return NULL;
    int c = strcmp(r->key, key);
    if(c == 0){
        return r;
    }
    if(c<0) return find(r->right,key);
    return find(r->left,key);
}


void readData(){
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL){
        printf("Error opening data.txt file");
    }
    
    char key[10];
    float op;
    float cp;
    int day;
    int N;
    fscanf(fp, "%d", &N);
    for(int i=0; i<N; i++){
        fscanf(fp, "%s\t%f\t%f", key, &op, &cp);
        root = insert(root,key,op,cp);
    }
    while(!feof(fp)){
        fscanf(fp, "%s\t%f\t%f", key, &op, &cp);
        cophieu * buff = find(root,key);
        buff->day++;
        buff->price[buff->day].giamo = op;
        buff->price[buff->day].giadong = cp;
    }
    fclose(fp);
}

void inOrder(cophieu *r)
{

    if (r == NULL)
        return;
    inOrder(r->left);
    float TB = 0;
    for (int i = 0; i < 10; i++)
    {
        TB += r->price[i].giadong - r->price[i].giamo;
    }
    r->trungbinh = TB / 10;
    printf("%-5s   %8.3f\n", r->key, TB / 10);
    inOrder(r->right);
}

void findTang(cophieu *r)
{
    if (r == NULL)
        return;
    findTang(r->left);
    if(r->price[0].giadong-r->price[0].giamo >0 &&r->price[1].giadong-r->price[1].giamo >0)
        printf("%-5s\n", r->key);
    findTang(r->right);
}

void tinhSoNgayTang(cophieu *r){
    if (r == NULL)
        return;
    
    tinhSoNgayTang(r->left);
    int max = 0;
    int count = 0;
    for(int i=0;i<9;i++){
        for(int j = i+1;j<10;j++){
            if((r->price[i].giadong-r->price[i].giamo>0) && (r->price[j].giadong-r->price[j].giamo>0)){
                count++;
            }
            else{
                if(count>max)
                    max = count;
                count = 0;
            }
        }
    }
    r->songaytang = max;
    tinhSoNgayTang(r->right);
}

void findVip(cophieu *r){
    maxCP->songaytang = 0;
    if (r == NULL)
        return ;
    
    findVip(r->left);
    if(r->songaytang>maxCP->songaytang){
        maxCP->songaytang = r->songaytang;
    }
    findVip(r->right);
}

void findMax(cophieu *r,int max){
    findMax(r->left,max);
    if(r->songaytang==max){
        printf("Co phieu %s co so ngay tang lon nhat la: %d\n",r->key,max);
    }
    findMax(r->right,max);
}



int main(){
    char name1[30];
    int chon;
    char name[30];
    do
    {
        printf("----------MENU----------\n");
        printf("1. Doc file\n");
        printf("2. Tim kiem theo ma chung khoan\n");
        printf("3. Tim kiem chung khoan co xu huong tang\n");
        printf("4. Tim ma so ngay tang lon nhat\n");
        printf("5. Thoat\n");
        printf("Moi ban chon menu: ");
        scanf("%d", &chon);

        switch (chon)
        {
        case 1:
            readData();
            printf("%-5s  %-5s  \n", "Name", "Trung Binh");
            inOrder(root);
            break;
        case 2:

            printf("Nhap ma chung khoan: ");
            fflush(stdin);
            scanf("%s", name);
            cophieu *r = find(root, name);
            if (r == NULL)
            {
                printf("Khong tim thay ma !!");
            }
            else
            {
                float min = 1000, max = 0;
                for (int i = 0; i < 10; i++)
                {
                    if (r->price[i].giadong < min)
                        min = r->price[i].giadong;
                    if (r->price[i].giadong > max)
                        max = r->price[i].giadong;
                }
                printf("Gia dong cua cao nhat: %.3f\nGia dong cua thap nhat: %.3f\n", max, min);
            }

            break;
        case 3:
            findTang(root);
            break;
        case 4:
            tinhSoNgayTang(r);
            findVip(root);
            printf("%d test",maxCP->songaytang);
            break;
        case 5:
            printf("Tran Tien Ngoc 20205009\n");
            printf("Ket thuc chuong trinh ");
            break;
        default:
            
            break;
        }

    } while (chon != 5);
}