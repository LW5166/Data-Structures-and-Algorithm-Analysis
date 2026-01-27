#include<stdio.h>
#define N 10

long power(long x,int n){   /*计算x的n次方*/
    long result=1;
    for(int i=0;i<n;i++)
    {
        result*=x;
    }
    return result;
    /*
     * Copilot 建议:
     * 这个函数实现得很好，逻辑清晰。
     * 但需要注意，当 n 较大时（例如 n > 63），power(2, n) 的结果会超出 long 类型的最大值，
     * 导致数据溢出。在 main 函数的循环中你会观察到这个现象（结果会变成负数或0）。
     * 在现阶段，你只需要意识到这个限制即可，这是理解数据类型范围的好机会。
     */
}

double geometric_sum(int n){    /*计算几何级数*/
    int denominator=1;
    double sum=0;
    for(int i=0;i<=n;i++)
    {
        /*
         * Copilot 建议:
         * 这是一个非常常见的C语言陷阱！
         * 因为 denominator 是 int 类型，所以 (1/denominator) 会执行“整数除法”。
         * 当 denominator 的值是 2, 4, 8... 时，1/denominator 的结果永远是 0。
         * 这导致你的 sum 实际上等于 1 + 0 + 0 + ...
         *
         * 【修复建议】
         * 为了得到正确的浮点数结果，你需要将除法操作变为“浮点数除法”。
         * 方法1 (推荐): 将被除数1写成浮点数形式 1.0。
         *    sum += (1.0 / denominator);
         *
         * 方法2: 将 denominator 强制类型转换为 double。
         *    sum += (1 / (double)denominator);
         */
        sum+=(1.0/denominator);
        denominator*=2;
    }
    return sum;
}

int main(){
    long a;
    double b;
    for(int i=10;i<=50;i++)
    {
        a=power(2,i);
        b=geometric_sum(i);
        /*
         * Copilot 建议:
         * 为了让输出结果更清晰，方便你观察不同N值对应的结果，
         * 可以在打印时把当前的循环变量 i 也包含进来。
         *
         * 【优化建议】
         * printf("N=%d, result A=%ld, result B=%lf\n", i, a, b);
         */
        printf("N=%d\n",i);
        printf("result A=%ld\n",a);
        printf("result B=%lf\n",b);
    }
    return 0;
}