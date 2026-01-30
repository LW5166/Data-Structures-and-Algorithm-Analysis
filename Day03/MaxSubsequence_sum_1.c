/*
这是一个计算最大子列和的函数
采用三重循环
时间复杂度O(n^3)
*/

int MaxSubsequence_sum1(const int a[], int n)
{
    long long ThisSum,MaxSum;//修改int 为 long long
    int i,j,k;
    MaxSum=0;
    for(i=0;i<n;i++)
    {
        for( j=i;j<n;j++)
        {
            ThisSum=0;
            for(k=i;k<=j;k++)   //注意<=
            {
                ThisSum+=a[k];
            }
            if(ThisSum > MaxSum)
                MaxSum=ThisSum;
        }
    }
    return MaxSum;
}