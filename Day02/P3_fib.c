#include<stdio.h>
#include<time.h>

long long fib(int n){   /*计算斐波那契数列*/
    long long result=0;
    if(n==1 || n==2) return 1;
    return fib(n-1) + fib(n-2);
}

int main(){
    for(int i=40;i<100;i++){
        clock_t start=clock();
        printf("fib(%d)=%lld\n",i,fib(i));
        clock_t end=clock();
        int time=(end - start)/CLOCKS_PER_SEC;
        printf("time=%d\n",time);
    }
    return 0;
}

