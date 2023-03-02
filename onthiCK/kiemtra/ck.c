#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct _time{
    int hh;
    int mm;
    int ss;
    int DD;
    int MM;
    int YYYY;
}time;

typedef struct _guixe{
    char bienso[20];
    time time;
    int guihaylay;
    struct _guixe *next;
}guixe;

typedef struct _quanligui{
    char bienso[20];
    time time;
    int guihaylay;
    struct _quanligui *left;
    struct _quanligui *right;
}quanligui;


quanligui *rootBT;
guixe *root;



guixe * llPrint(guixe * root)
{
    for (guixe *p = root; p != NULL; p = p->next)
        printf("%4.d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d %s %d\n", p->time.YYYY,p->time.MM,p->time.DD,p->time.hh,p->time.mm,p->time.ss,p->bienso,p->guihaylay);
    printf("\n");
    return root;
}

guixe *createNewNode(int YYYY, int MM,int DD,int hh,int mm, int ss, char bienso[20],int guihaylay)
{
    guixe *newNode = (guixe *)malloc(sizeof(guixe));
    if (newNode == NULL)
        return NULL;
    strcpy(newNode->bienso, bienso);
    newNode->time.hh = hh;
    newNode->time.mm = mm;
    newNode->time.ss = ss;
    newNode->time.YYYY = YYYY;
    newNode->time.MM = MM;
    newNode->time.DD = DD;
    newNode->guihaylay = guihaylay;
    newNode->next = NULL;
    return newNode;
}

quanligui *createNewNodeBT(int YYYY, int MM,int DD,int hh,int mm, int ss, char bienso[20],int guihaylay)
{
    quanligui *newNode = (quanligui *)malloc(sizeof(quanligui));
    if (newNode == NULL)
        return NULL;
    strcpy(newNode->bienso, bienso);
    newNode->time.hh = hh;
    newNode->time.mm = mm;
    newNode->time.ss = ss;
    newNode->time.YYYY = YYYY;
    newNode->time.MM = MM;
    newNode->time.DD = DD;
    newNode->guihaylay = guihaylay;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

guixe* llInsertTail(guixe* root,int YYYY, int MM,int DD,int hh,int mm, int ss, char bienso[20],int guihaylay)
{
    guixe *pNewNode = createNewNode(YYYY,MM,DD,hh,mm,ss,bienso,guihaylay);

    if (root == NULL)
        return (guixe*)pNewNode;

    guixe *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
        ;
    p->next = pNewNode;
    return root;
}

quanligui * insert(quanligui *node,int YYYY, int MM,int DD,int hh,int mm, int ss, char bienso[20],int guihaylay){
    if(node == NULL) return createNewNodeBT(YYYY,MM,DD,hh,mm,ss,bienso,guihaylay);
    int c = strcmp(node->bienso, bienso);
    if (c == 0) // không insert được nếu tên trùng nhau
    {
        printf("Bien so %s exists, do not insert\n", node->bienso);
        return node;
    }
    else if (c < 0) //  thì add node vừa insert vào rightChild
    {
        node->right = insert(node->right,YYYY,MM,DD,hh,mm,ss,bienso,guihaylay);
        return node;
    }
    else // thì add node vừa insert vào leftChild
    {
        node->left = insert(node->left,YYYY,MM,DD,hh,mm,ss,bienso,guihaylay);
        return node;
    }
}

quanligui *findMin(quanligui *r)
{
    if (r == NULL)
    {
        return NULL;
    }
    quanligui *lmin = findMin(r->left);
    if (lmin != NULL)
    {
        return lmin;
    }
    return r;
}

quanligui * find(quanligui *r, char bienso[20]){
    if(r == NULL) return NULL;
    int c = strcmp(r->bienso, bienso);
    if(c == 0){
        return r;
    }
    if(c<0) return find(r->right,bienso);
    return find(r->left,bienso);
}

quanligui *delete_quanligui(quanligui *r, char bienso[20])
{
    if (r == NULL)
    {
        return NULL;
    }
    if (strcmp(r->bienso, bienso) > 0)
    {
        r->left = delete_quanligui(r->left, bienso);
    }
    else if (strcmp(r->bienso, bienso) < 0)
    {
        r->right = delete_quanligui(r->right, bienso);
    }
    else
    {
        if (r->left != NULL && r->right != NULL)
        {
            quanligui *tmp = findMin(r->right);
            strcpy(r->bienso, tmp->bienso);
            r->right = delete_quanligui(r->right, tmp->bienso);
        }
        else
        {
            quanligui *tmp = r;
            if (r->left == NULL)
                r = r->right;
            else
                r = r->left;
            free(tmp);
        }
    }
    return r;
}



void readData(){
    FILE * f = fopen("data.txt","r");
    if(f == NULL){
        printf("Error opening data.txt file");
    }
    char bienso[40];
    int hh;
    int mm;
    int ss;
    int DD;
    int MM;
    int YYYY;
    int guihaylay;
    while(!feof(f)){
        fscanf(f,"%d-%d-%d %d:%d:%d %s %d",&YYYY,&MM,&DD,&hh,&mm,&ss,bienso,&guihaylay);
        root = llInsertTail(root, YYYY,MM,DD,hh,mm,ss,bienso,guihaylay);
    }

}

void readDataBT(){
    FILE * f = fopen("data.txt","r");
    if(f == NULL){
        printf("Error opening data.txt file");
    }
    char bienso[40];
    int hh;
    int mm;
    int ss;
    int DD;
    int MM;
    int YYYY;
    int guihaylay;
    while(!feof(f)){
        fscanf(f,"%d-%d-%d %d:%d:%d %s %d",&YYYY,&MM,&DD,&hh,&mm,&ss,bienso,&guihaylay);
        if(guihaylay == 1){
            rootBT = insert(rootBT, YYYY,MM,DD,hh,mm,ss,bienso,guihaylay);
        }
        if(guihaylay == 0){
            rootBT = delete_quanligui(rootBT,bienso);
        }
        
    }

}
int count = 0;
void inOrder(quanligui *r)
{
    
    if (r == NULL)
        return;
    inOrder(r->left);
    count++;
    printf("Bien so: %s\n",r->bienso);
    inOrder(r->right);
}

void inOrderF(quanligui *r)
{
    FILE *f = fopen("change_log.txt","w");
    if (r == NULL)
        return;
    inOrderF(r->left);
    fprintf(f,"%d-%d-%d %d:%d:%d %s %d",r->time.YYYY,r->time.MM,r->time.DD,r->time.hh,r->time.mm,r->time.ss,r->bienso,r->guihaylay);
    inOrderF(r->right);
}

void freeTree(quanligui *tree) {
  if (tree != NULL) {
    freeTree(tree->left);
    freeTree(tree->right);
    free((void *)tree);
  }
}

void main(){
    char name1[30];
    int chon;
    char name[30];
    do
    {
        printf("----------MENU----------\n");
        printf("1. Doc file\n");
        printf("2. In ra thong tin trong 1 ngay\n");
        printf("3. Truy van  xe hien tai\n");
        printf("4. Ghi file\n");
        printf("5. Thoat\n");
        printf("Moi ban chon menu: ");
        scanf("%d", &chon);

        switch (chon)
        {
        case 1:
            readData();
            root = llPrint(root);
            break;
        case 2:
            printf("Nhap ngay thang nam can truy van: ");
            int nam,thang,ngay;
            scanf("%d-%d-%d",&nam,&thang,&ngay);
            int countGui=0;
            int countLay=0;
            guixe *p =root;
            for (p ; p->next != NULL; p = p->next){
                if(p->time.YYYY==nam && p->time.MM==thang && p->time.DD==ngay ){
                    if( p->guihaylay == 0){
                    countLay++;
                    }
                    if(p->guihaylay == 1){
                    countGui++;
                    }
                }
            }
            printf("So luot gui la: %d\n",countGui);
            printf("So luot lay la: %d\n",countLay);
            break;
        case 3:
            int luachon;
            
            readDataBT();
            printf("so luong xe gui la: %d\n",count);
            inOrder(rootBT);
            printf("1. In thong tin cac xe trong bai\n");
            printf("2. Gui xe\n");
            printf("3. Tra xe\n");
            scanf("%d",&luachon);
            do{
            switch (luachon)
            {
            case 1:
                
                break;
            case 2:
                char biensomoi[20];
                printf("Nhap bien so xe");
                scanf("%s",biensomoi);
                if(find(rootBT,biensomoi)){
                    printf("Xe da gui");
                }
                else{
                    rootBT = insert(rootBT,2023, 02,28,06,30, 30, biensomoi[20],1);
                }
                break;
            case 3:
                char biensotra[20];
                printf("Nhap bien so xe");
                scanf("%s",biensotra);
                if(find(rootBT,biensotra)){
                    printf("Xe da tra");
                }
                else{
                    rootBT = delete_quanligui(rootBT, biensotra);
                }
                break;
            default:
                break;
            }
            
            }
            while (luachon!=0);
            break;
        case 4:
            inOrderF(rootBT);
            break;
        case 5:
            printf("Ket thuc chuong trinh ");
            break;
        default:
            
            break;
        }

    } while (chon != 5);
    free(root);
    freeTree(rootBT);
}