long long MaxSubsequence_sum4(const int a[],int n)
{
    long long MaxSum,ThisSum;
    int i;
    ThisSum = MaxSum = 0;
    for(i=0;i<n;i++)
    {
        ThisSum += a[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}