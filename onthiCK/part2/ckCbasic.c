#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _khachsan
{
    char maYeuCau[20];
    int soNguoi;
    char soPhong[20];
    char maKhachSan[20];
    char thoiGian[20];
    int soTreEm;
    struct _khachsan *next;
} khachsan;

typedef struct _quanliks
{
    char maYeuCau[20];
    int soNguoi;
    char soPhong[20];
    char maKhachSan[20];
    char thoiGian[20];
    int soTreEm;
    struct _quanliks *left;
    struct _quanliks *right;
} quanliks;

quanliks *rootBT;
khachsan *root;

khachsan *llPrint(khachsan *root)
{
    int count = 0;
    for (khachsan *p = root; p != NULL; p = p->next)
    {
        printf("%s %d %s %s %s %d\n", p->maYeuCau, p->soNguoi, p->soPhong, p->maKhachSan, p->thoiGian, p->soTreEm);
        count++;
    }
    printf("\n");
    printf("so luong doc duoc: %d\n", count);
    return root;
}

khachsan *createNewNode(char maYeuCau[20], int soNguoi, char soPhong[20], char maKhachSan[20], char thoiGian[20], int soTreEm)
{
    khachsan *newNode = (khachsan *)malloc(sizeof(khachsan));
    if (newNode == NULL)
        return NULL;
    strcpy(newNode->maYeuCau, maYeuCau);
    strcpy(newNode->soPhong, soPhong);
    strcpy(newNode->maKhachSan, maKhachSan);
    strcpy(newNode->thoiGian, thoiGian);
    newNode->soNguoi = soNguoi;
    newNode->soTreEm = soTreEm;
    newNode->next = NULL;
    return newNode;
}

quanliks *createNewNodeBT(char maYeuCau[20], int soNguoi, char soPhong[20], char maKhachSan[20], char thoiGian[20], int soTreEm)
{
    quanliks *newNode = (quanliks *)malloc(sizeof(quanliks));
    if (newNode == NULL)
        return NULL;
    strcpy(newNode->maYeuCau, maYeuCau);
    strcpy(newNode->soPhong, soPhong);
    strcpy(newNode->maKhachSan, maKhachSan);
    strcpy(newNode->thoiGian, thoiGian);
    newNode->soNguoi = soNguoi;
    newNode->soTreEm = soTreEm;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

khachsan *llInsertTail(khachsan *root, char maYeuCau[20], int soNguoi, char soPhong[20], char maKhachSan[20], char thoiGian[20], int soTreEm)
{
    khachsan *pNewNode = createNewNode(maYeuCau, soNguoi, soPhong, maKhachSan, thoiGian, soTreEm);

    if (root == NULL)
        return (khachsan *)pNewNode;

    khachsan *p = NULL;
    for (p = root; p->next != NULL; p = p->next)
        ;
    p->next = pNewNode;
    return root;
}

quanliks *insert(quanliks *node, char maYeuCau[20], int soNguoi, char soPhong[20], char maKhachSan[20], char thoiGian[20], int soTreEm)
{
    if (node == NULL)
        return createNewNodeBT(maYeuCau, soNguoi, soPhong, maKhachSan, thoiGian, soTreEm);
    int c = strcmp(node->maYeuCau, maYeuCau);
    if (c == 0) // không insert được nếu tên trùng nhau
    {
        printf("MaYC %s exists, do not insert\n", node->maYeuCau);
        return node;
    }
    else if (c < 0) //  thì add node vừa insert vào rightChild
    {
        node->right = insert(node->right, maYeuCau, soNguoi, soPhong, maKhachSan, thoiGian, soTreEm);
        return node;
    }
    else // thì add node vừa insert vào leftChild
    {
        node->left = insert(node->left, maYeuCau, soNguoi, soPhong, maKhachSan, thoiGian, soTreEm);
        return node;
    }
}

quanliks *findMin(quanliks *r)
{
    if (r == NULL)
    {
        return NULL;
    }
    quanliks *lmin = findMin(r->left);
    if (lmin != NULL)
    {
        return lmin;
    }
    return r;
}

quanliks *find(quanliks *r, char maYeuCau[20])
{
    if (r == NULL)
        return NULL;
    int c = strcmp(r->maYeuCau, maYeuCau);
    if (c == 0)
    {
        return r;
    }
    if (c < 0)
        return find(r->right, maYeuCau);
    return find(r->left, maYeuCau);
}

quanliks *delete_quanliks(quanliks *r, char maYeuCau[20])
{
    if (r == NULL)
    {
        return NULL;
    }
    if (strcmp(r->maYeuCau, maYeuCau) > 0)
    {
        r->left = delete_quanliks(r->left, maYeuCau);
    }
    else if (strcmp(r->maYeuCau, maYeuCau) < 0)
    {
        r->right = delete_quanliks(r->right, maYeuCau);
    }
    else
    {
        if (r->left != NULL && r->right != NULL)
        {
            quanliks *tmp = findMin(r->right);
            strcpy(r->maYeuCau, tmp->maYeuCau);
            r->right = delete_quanliks(r->right, tmp->maYeuCau);
        }
        else
        {
            quanliks *tmp = r;
            if (r->left == NULL)
                r = r->right;
            else
                r = r->left;
            free(tmp);
        }
    }
    return r;
}

void readData()
{
    FILE *f = fopen("booking_orders.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file");
    }
    char maYeuCau[20];
    int soNguoi;
    char soPhong[20];
    char maKhachSan[20];
    char thoiGian[20];
    int soTreEm;
    int N;
    fscanf(f, "%d", &N);

    for (int i = 0; i < N; i++)
    {
        fscanf(f, "%s %d %s %s %s %d", maYeuCau, &soNguoi, soPhong, maKhachSan, thoiGian, &soTreEm);
        root = llInsertTail(root, maYeuCau, soNguoi, soPhong, maKhachSan, thoiGian, soTreEm);
    }
}

void transferData()
{
    khachsan *p = root;
    for (p; p != NULL; p = p->next)
    {
        rootBT = insert(rootBT, p->maYeuCau, p->soNguoi, p->soPhong, p->maKhachSan, p->thoiGian, p->soTreEm);
    }
}

void inOrder(quanliks *r)
{

    if (r == NULL)
        return;
    inOrder(r->left);
    printf("%s %d %s %s %s %d\n", r->maYeuCau, r->soNguoi, r->soPhong, r->maKhachSan, r->thoiGian, r->soTreEm);
    inOrder(r->right);
}

khachsan *llDeleteAll(khachsan *root)
{
    khachsan *p = NULL;
    for (; root != NULL; root = p)
    {
        p = root->next;
        free(root);
    }
    return NULL;
}

void inOrderF(quanliks *r)
{
    FILE *f = fopen("booking_output.txt", "w");
    if (r == NULL)
        return;
    inOrderF(r->left);
    fprintf(f, "%s %d %s %s %s %d\n", r->maYeuCau, r->soNguoi, r->soPhong, r->maKhachSan, r->thoiGian, r->soTreEm);
    inOrderF(r->right);
}

void freeTree(quanliks *tree)
{
    if (tree != NULL)
    {
        freeTree(tree->left);
        freeTree(tree->right);
        free((void *)tree);
    }
}

void main()
{
    char name1[30];
    int chon;
    char name[30];
    do
    {
        printf("----------MENU----------\n");
        printf("1. Doc file\n");
        printf("2. Kiem tra so luong yeu cau khong hop le\n");
        printf("3. Tra cuu ma theo yeu cau\n");
        printf("4. Thay doi yeu cau\n");
        printf("5. Huy yeu cau\n");
        printf("6. Luu danh sach yeu cau ra file\n");
        printf("7. Thoat\n");
        printf("Moi ban chon menu: ");
        scanf("%d", &chon);

        switch (chon)
        {
        case 1:
            readData();
            llPrint(root);
            break;
        case 2:
        {
            khachsan *p = root;
            int khonghople = 0;
            for (p; p != NULL; p = p->next)
            {
                if (p->soNguoi == p->soTreEm)
                {
                    khonghople++;
                }
            }
            printf("so yeu cau khong hop le la: %d\n", khonghople);
        }
        break;
        case 3:
        {
            char maYCTimKiem[20];
            transferData();
            printf("Nhap ma yeu cau can tim kiem:");
            scanf("%s", maYCTimKiem);
            rootBT = find(rootBT, maYCTimKiem);
            if (rootBT == NULL)
            {
                printf("Not found\n");
            }
            else
            {
                printf("Tim thay:");
                printf("%s %d %s %s %s %d\n", rootBT->maYeuCau, rootBT->soNguoi, rootBT->soPhong, rootBT->maKhachSan, rootBT->thoiGian, rootBT->soTreEm);
            }
        }
        break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            inOrderF(rootBT);
            break;
        case 7:
            printf("Ket thuc chuong trinh ");
            freeTree(rootBT);
            root = llDeleteAll(root);
            break;
        default:

            break;
        }

    } while (chon != 7);
}