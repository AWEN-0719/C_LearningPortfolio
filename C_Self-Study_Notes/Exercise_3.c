#include <stdio.h>

int main(void)
{
    int choice;         // 運算選擇
    double num1, num2;  // 支援小數的輸入
    int quotient, remainder; // 用於顯示商數與餘數
    char cont = 'y';    // 控制是否繼續運算

    printf("==== 簡易計算機 ====\n");

    // 外層迴圈：當使用者選擇繼續時，反覆執行
    while (cont == 'y' || cont == 'Y') {
        // 顯示運算選單
        printf("\n請選擇運算:\n");
        printf("1. 加法 (+)\n");
        printf("2. 減法 (-)\n");
        printf("3. 乘法 (*)\n");
        printf("4. 除法 (/)\n");
        printf("5. 商數與餘數 (整數運算)\n");
        printf("0. 退出\n");
        printf("選擇: ");
        scanf("%d", &choice);

        // 選擇退出
        if (choice == 0) {
            printf("已退出計算機。\n");
            break;
        }

        // 加、減、乘、除，使用 double 支援小數
        if (choice >= 1 && choice <= 4) {
            printf("輸入兩個數字，用空格分開: ");
            scanf("%lf %lf", &num1, &num2); // 讀入小數

            switch (choice) {
                case 1: // 加法
                    printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                    break;
                case 2: // 減法
                    printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                    break;
                case 3: // 乘法
                    printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                    break;
                case 4: // 除法
                    if (num2 != 0)
                        printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                    else
                        printf("錯誤: 除數不能為 0\n");
                    break;
            }
        }
        // 商數與餘數
        else if (choice == 5) {
            printf("輸入兩個數字，用空格分開: ");
            scanf("%lf %lf", &num1, &num2);

            // 先轉成整數
            int int1 = (int)num1;
            int int2 = (int)num2;

            if (int2 == 0) {
                printf("錯誤: 除數不能為 0\n");
            } else {
                quotient = int1 / int2;
                remainder = int1 % int2;
                printf("%d / %d = %d ... %d (商數與餘數)\n", int1, int2, quotient, remainder);
            }
        }
        // 無效選擇
        else {
            printf("無效選擇，請重新輸入。\n");
        }

        // 詢問是否繼續
        printf("是否繼續計算? (y/n): ");
        scanf(" %c", &cont); // 前面空格吃掉換行符
    }

    return 0; // 程式正常結束
}
