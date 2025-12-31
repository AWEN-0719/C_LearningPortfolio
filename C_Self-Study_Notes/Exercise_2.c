#include <stdio.h>

int main(void)
{
    int a = 1;  // 外層迴圈的被乘數
    int b;      // 內層迴圈的乘數

    while (a <= 9) {
        b = 1;  // 每次外層開始，內層從 1 開始
        while (b <= 9) {
            printf("%2d x %2d = %3d\n", a, b, a * b);
            b++;  // 內層迴圈加 1
        }
        printf("\n"); // 每一個乘法表空一行
        a++;  // 外層迴圈加 1
    }

    return 0;
}
