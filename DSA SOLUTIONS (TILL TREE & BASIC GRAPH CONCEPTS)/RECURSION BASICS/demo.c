#include<stdio.h>
void t(int n){
    if(n>0){
        t(n-1);
        printf("%d",n);
        return;
    }
}

int main(){
    t(4);
    return 0;
}