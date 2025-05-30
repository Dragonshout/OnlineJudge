#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int times = 0; // 初始化times变量
    
    while (n != 1) { // 确保n不为负数或零
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        times++;
    }
    
    printf("%d", times); // 输出步数
    
    return 0;
}