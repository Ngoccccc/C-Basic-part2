#include<stdio.h>
#include<math.h>
typedef struct {
    double x;
    double y;
} point;

typedef struct 
{
    point center;
    double radius;
} circle;


int main(){
    point a,b;
    a.x =12;
    a.y =24;
    b=a;
    printf("%f",b.y);
    return 0;
}

