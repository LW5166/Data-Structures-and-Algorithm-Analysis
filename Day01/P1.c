#include <stdio.h>

// 修改1：使用 long long (确保是64位)，而不是 long
long long power(long x, int n) {
    long long result = 1; 
    for(int i=0; i<n; i++) {
        result *= x;
    }
    return result;
}

double geometric_sum(int n) {
    double sum = 0;
    // 修改2：完全抛弃 int denominator，改用 double
    // 这样就不会有整数溢出变成0的问题了，只会变得无限小
    double current_term = 1.0; 
    
    for(int i=0; i<=n; i++) {
        sum += current_term;
        current_term = current_term / 2.0; 
    }
    return sum;
}

int main() {
    long long a; // 修改3：这里也要用 long long
    double b;
    
    // 我们只测到63，因为2^64连 long long 也会溢出
    for(int i=23; i<=40; i++) { 
        a = power(2, i);
        b = geometric_sum(i);
        
        // 修改4：输出格式用 %lld (long long decimal)
        printf("N=%d\n", i);
        printf("result A=%lld\n", a); 
        printf("result B=%.10f\n", b); // %.10f 可以看清小数
        printf("----------------\n");
    }
    return 0;
}