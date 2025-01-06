// Online C compiler to run C program online
#include <stdio.h>

void func(int *u){
  printf("%d ",*u);
  *u=9;
   printf(" now val of u  is%d ",*u);
}

int main() {
    // Write C code here
    printf("Try programiz.pro  ");
    int a=4;
    //printf("%d  ",a);
    int *p=&a;
    //int *q=p;
    //printf("%d %d",*p,*q);
    //int b=9;
    //p=&b;
    //printf("%d %d  ",*p,*q);
    func(p);

    printf(" now val of p  is%d ",*p);
    return 0;
}