#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 2000
#include"MaxSubsequence_sum_1.c"

int main()
{
    int *p = NULL;
    int i=0;
    int start,end;
    int time1;
    p=malloc(N*sizeof(int));
    srand((unsigned int) time(NULL));
    while(i<N)
    {
        *(p+i) = rand()%100-50;
        i++;
    }

    start=clock(NULL);
    MaxSubsequence_sum1(p,N);
    end=clock(NULL) ;
    time1=(end-start);
    i=0;
    while (i<N)
    {
        printf("%d ",*(p+i));
        i++;
    }

    printf("Algorthm 1用时",time1);
    return 0;
}