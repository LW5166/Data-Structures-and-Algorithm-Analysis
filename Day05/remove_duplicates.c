#include <stdio.h>

// 你的核心任务函数
int removeDuplicates(int* nums, int numsSize) {
    // 1. 防御性编程：空数组处理
    if (numsSize == 0) {
        return 0;
    }

    // 2. 定义双指针
    // slow: 慢指针，维护有效数据的边界
    int slow = 0;
    
    // fast: 快指针，负责扫描
    int fast = 1;
    // TODO: 编写循环逻辑
    // 让 fast 从 1 跑到 numsSize - 1
    for(fast;fast<numsSize;fast++)
    {
        if(nums[fast] != nums[slow])
        {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    // 在循环内部：
    //    判断 nums[fast] 和 nums[slow] 是否相等
    //    如果不相等 -> slow 前进一步 -> 将 nums[fast] 的值 覆盖写入 nums[slow]
    
    
    
    // 3. 返回有效长度
    // 索引从0开始，如果 slow 停在索引 4，说明有 5 个元素
    return slow + 1;
}

// 验证程序 (Driver Code)
int main() {
    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    for(int i=0; i<size; i++) printf("%d ", arr[i]);
    printf("\n");

    // 执行去重
    int newLen = removeDuplicates(arr, size);

    printf("去重后长度: %d\n", newLen);
    printf("去重后数组(前%d位): ", newLen);
    for(int i=0; i<newLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 简单的自测逻辑
    if (newLen == 5 && arr[4] == 4) {
        printf(">> 测试通过: 逻辑正确！\n");
    } else {
        printf(">> 测试失败: 结果不符合预期。\n");
    }

    return 0;
}