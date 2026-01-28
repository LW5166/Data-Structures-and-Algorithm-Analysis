#include<stdio.h>

long long factorial(int n){   /*递归计算阶乘*/
    long long result=1;
    if(n==0)
        return 1;
    else if(n<0)
        return -1;
    else
        return n*factorial(n-1);
}

int main(){
    for(int i=0;i<20;i++)
        printf("%d!=%lld\n",i,factorial(i));
    return 0;
}