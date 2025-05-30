#include <stdio.h>

int main() {
    int num, step = 0;
    scanf("%d", &num);
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
            step++;
        } else {
            num = (num * 3 + 1) / 2;
            step++;
        }
    }
    printf("%d", step);
}