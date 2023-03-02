#include <stdio.h>
#include <stdlib.h>
#define Max 20 //so phan tu toi da cua Queue
typedef int item; //kieu du lieu
 
typedef struct Queue
{
    int Front, Rear; //front: phan tu dau hang, rear: phan tu cuoi hang
    item Data[Max]; //Mang cac phan tu
    int count; //dem so phan tu cua Queue
} Queue_t; //;

void Init (Queue_t *Q) //khoi tao Queue rong
{
    Q->Front = 0; //phan tu dau
    Q->Rear = -1; // phan tu cuoi o -1 (khong co phan tu trong Q)
    Q->count = 0; //so phan tu bang 0
}

int Isempty (Queue_t *Q) //kiem tra Queue rong
{
    if (Q->count == 0) //so phan tu = 0 => rong
        return 1;
    return 0;
}
 
int Isfull (Queue_t *Q) //kiem tra Queue day
{
    if (Q->count == Max) //so phan tu = Max => day
        return 1;
    return 0;
}

void Push(Queue_t *Q, item x) //them phan tu vao cuoi Queue
{
    if (Isfull(Q)) printf("Hang doi day !");
    else
    { 
        Q->Data[++Q->Rear] = x; //tang Rear len va gan phan tu vao
        Q->count++; //tang so phan tu len
    }
}


int Pop(Queue_t *Q) //Loai bo phan tu khoi dau hang doi
{
    if (Isempty(Q)) printf("Hang doi rong !");
    else
    {
        item x = Q->Data[Q->Front];
        for (int i=Q->Front; i<Q->Rear; i++) //di chuyen cac phan tu ve dau hang
            Q->Data[i] = Q->Data[i+1];
        Q->Rear--; // giam vi tri phan tu cuoi xuong
        Q->count--;//giam so phan tu xuong
        return x; //tra ve phan tu lay ra
    }
}

item Qfront (Queue_t *Q) //xem thong tin phan tu dau hang
{
    if (Isempty(Q)) printf("Hang doi rong !");
    else return Q->Data[Q->Front];
}

void PrintQueue (Queue_t *Q){
    if (Isempty(Q)) printf("Hang doi rong !");
    else
    {
        for (int i=Q->Front; i<=Q->Rear; i++)
            printf("%d   ",Q->Data[i]);
        printf("\n");
    }
}

int main(){
    Queue_t *Q;
    Init(Q);
    for(int i=0;i<10;i++){
        Push(Q,i);
    }
    PrintQueue(Q);
    Pop(Q);
    PrintQueue(Q);
    
    return 0;
}