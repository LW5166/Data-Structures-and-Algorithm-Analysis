#include<stdio.h>

long long factorial(int n){   /*递归计算阶乘*/
    long long result=1;
    if(n==0)
        result = 1;
    else if(n<0)
        return -1;
    else{
        result=n*factorial(n-1);
    }
    return result;
}

int main(){
    for(int i=0;i<20;i++)
        printf("%lld\n",factorial(i));
    return 0;
}