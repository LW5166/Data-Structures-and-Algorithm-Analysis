/*
这是一个计算最大子列和的函数
采用二重循环
用空间换时间
时间复杂度为O(n^2)
*/

int MaxSubsequence_sum2(const int a[], int n)
{
    long long ThisSum,MaxSum;//修改int 为long long
    int i,j;
    MaxSum=0;
    for(i=0;i<n;i++)
    {
        ThisSum=0;
        for(j=i;j<n;j++)
        {
            ThisSum+=a[j];
            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}