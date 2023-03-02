#include<stdio.h>
#include<stdlib.h>

void main()
{
    int chon;
    int a,b;
    do
    {
        
        printf("----------MENU----------\n");
        printf("1. Nhap\n");
        printf("2. Tinh Tong\n");
        printf("3. Tinh Tich\n");
        printf("4. Thoat\n");
        scanf("%d", &chon);

        switch (chon)
        {
        case 1:
            printf("Nhap 2 so a va b\n");
            printf("a = ");
            scanf("%d", &a);
            printf("b = ");
            scanf("%d", &b);
            break;
        case 2:
            printf("Tong a va b la: %d\n", a+b);
            break;
        case 3:
            printf("Tong a va b la: %d\n", a*b);
            break;
            break;
        }
    } while (chon != 4);
}

