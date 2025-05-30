#include<stdio.h>

int main(){
    int number, i = 0;
    scanf("%d", &number);
    
    while (number != 1) { // 循环直到number变为1
        if (number % 2 == 0) {
            number = number / 2;
        } else {
            number = 3 * number + 1;
            number = number / 2;
            
        }
        i++; // 每次操作后步数加1
    }
    printf("%d", i); // 打印总步数
    return 0;
}