#include<stdio.h>

long long fib(int n){   /*计算斐波那契数列*/
    long long result=0;
    if(n==1) result=1;
    else{
        result=fib(n-1) + fib(n-2);
    }
    return result;
}

int main(){
    for(int i=1;i<40;i++)
        printf("%lld",fib(i));
    return 0;
}

