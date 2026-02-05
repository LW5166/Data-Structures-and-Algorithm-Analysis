static long long Max3(long long i, long long j,long long k)
{
    long long max;
    if(i>j)
        max = i;
    else max = j;
    if(k>max)  
        max = k;
    return max;
}

static long long MaxSubsequence_Sum(const int a[], int left,int right)
{
    long long MaxLeftSum,MaxRightSum;
    long long LeftBorderSum,RightBorderSum;
    long long MaxLeftBorderSum,MaxRightBorderSum;
    int middle;
    middle = (left + right)/2;

    if(left == right)//Base Case 修改这里直接返回a[left]
    {    
        if(a[left] > 0)
            return a[left];
        else return 0;
    }
    else
    {
        MaxLeftSum = MaxSubsequence_Sum(a,left,middle);
        MaxRightSum = MaxSubsequence_Sum (a,middle + 1,right);//注意是middle+1，否则middle会被重复计算

        MaxLeftBorderSum = 0;
        LeftBorderSum = 0;
        for(int i=middle;i>=left;i--)
        {
            LeftBorderSum += a[i];
            if(LeftBorderSum > MaxLeftBorderSum)
                MaxLeftBorderSum = LeftBorderSum;
        }

        MaxRightBorderSum = 0;
        RightBorderSum = 0;
        for(int j=middle+1;j<=right;j++)
        {
            RightBorderSum += a[j];
            if(RightBorderSum > MaxRightBorderSum)
                MaxRightBorderSum = RightBorderSum;
        }
        return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);
    }
}

long long MaxSubsequence_sum3(const int a[],int n)
{
    return MaxSubsequence_Sum(a,0,(n-1));
}