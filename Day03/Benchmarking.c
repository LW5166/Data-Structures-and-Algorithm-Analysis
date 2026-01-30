#include <stdio.h>
#include <time.h>   // 必须包含，用于 clock()
#include <stdlib.h> // 用于 malloc, rand

// 根据需要修改 N 的大小来观测差距
#define N 2000 

// 临时允许 include .c 文件方便调试
#include "MaxSubsequence_sum_1.c"
#include "MaxSubsequence_sum2.c"

int main()
{
    // 1. 变量声明
    int *p = NULL;
    clock_t start, end; // ✅ 使用 clock_t 类型
    double time1, time2; // ✅ 使用 double 类型
    long long res1, res2; // 接收结果
    
    // 2. 内存申请与检查
    p = (int*)malloc(N * sizeof(int));
    if (p == NULL) { // ✅ 防御性编程：必须检查 malloc 是否成功
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 3. 数据填充
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++) {
        p[i] = (rand() % 101) - 50; // -50 到 50
    }
    printf("Data generated. N = %d\n", N);

    // 4. 测试 Algorithm 1 (O(N^3))
    printf("Testing Algo 1 (O(N^3))... Please wait...\n");
    start = clock(); // ✅ 开始打点
    res1 = MaxSubsequence_sum1(p, N);
    end = clock();   // ✅ 结束打点
    
    // ✅ 计算秒数：强制转 double
    time1 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Algo 1 Result: %lld | Time: %f seconds\n", res1, time1);

    // 5. 测试 Algorithm 2 (O(N^2))
    printf("Testing Algo 2 (O(N^2))...\n");
    start = clock();
    res2 = MaxSubsequence_sum2(p, N);
    end = clock();
    
    time2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Algo 2 Result: %lld | Time: %f seconds\n", res2, time2);

    // 6. 验证一致性
    if (res1 != res2) {
        printf("!! ERROR: Results do not match!\n");
    } else {
        printf(">> Success: Results match.\n");
    }
    
    // 7. 内存释放
    free(p); // ✅ 释放 p
    p = NULL; // ✅ 置空

    return 0;
}