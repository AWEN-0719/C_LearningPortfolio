#include <stdio.h> // 輸入輸出函數
#include <stdlib.h> // 系統函數
#include <ctype.h> // 字符處理函數

const char *expr_ptr; // 全局指針，用於解析輸入的算式

// 函數宣告
double parse_expression();  // 處理加減
double parse_term();        // 處理乘除
double parse_factor();      // 處理括號和數字

int main(void) {
    char input[200]; // 儲存輸入的運算式
    char cont = 'y'; // 控制是否繼續計算

    while(cont == 'y' || cont == 'Y') {
        // 清空畫面
        #ifdef _WIN32
            system("cls"); // Windows
        #else
            system("clear"); // Linux/Mac
        #endif

        printf("==== 支援括號的控制台計算機 ====\n");
        printf("請輸入運算式 (例: (3+4)*5/2): ");
        scanf(" %[^\n]s", input); // 讀取整行

        expr_ptr = input; // 初始化指針
        double result = parse_expression(); // 開始解析
        printf("結果: %.6lf\n", result);

        printf("是否繼續計算? (y/n): ");
        scanf(" %c", &cont);
    }

    printf("已退出計算機。\n");
    return 0;
}

// 解析加減運算
double parse_expression() { // 解析加減運算
    double value = parse_term(); // 先解析乘除運算
    while(*expr_ptr) { // 當還有字元要解析時
        if(*expr_ptr == '+') { // 如果是加號
            expr_ptr++; // 移動指針
            value += parse_term(); // 解析下一個項並相加
        } else if(*expr_ptr == '-') { // 如果是減號
            expr_ptr++; // 移動指針
            value -= parse_term(); // 解析下一個項並相減
        } else { // 如果不是加減號，結束解析
            break; // 退出迴圈
        }
    }
    return value; // 返回計算結果
}

// 解析乘除運算
double parse_term() { // 解析乘除運算
    double value = parse_factor(); // 先解析括號或數字
    while(*expr_ptr) { // 當還有字元要解析時
        if(*expr_ptr == '*') { // 如果是乘號
            expr_ptr++; // 移動指針
            value *= parse_factor(); // 解析下一個因子並相乘
        } else if(*expr_ptr == '/') { // 如果是除號
            expr_ptr++; // 移動指針
            double divisor = parse_factor(); // 解析下一個因子
            if(divisor != 0) value /= divisor; // 除數不為0時相除
            else { // 除數為0時顯示錯誤訊息並退出
                printf("錯誤: 除數不能為0\n"); // 顯示錯誤訊息
                exit(1); // 退出程式
            } // 結束if-else
        } else { // 如果不是乘除號，結束解析
            break; // 退出迴圈
        } // 結束if-else
    } // 結束while
    return value; // 返回計算結果
} // 結束parse_term函數

// 解析括號或數字
double parse_factor() { //  解析括號或數字
    while(*expr_ptr == ' ') expr_ptr++; // 跳過空格

    double value = 0; // 儲存解析的值
    if(*expr_ptr == '(') { // 括號
        expr_ptr++; // 跳過開括號
        value = parse_expression(); // 解析括號內的運算式
        if(*expr_ptr == ')') expr_ptr++; // 跳過閉括號
        else { // 如果沒有閉括號，顯示錯誤訊息並退出
            printf("錯誤: 缺少閉括號\n"); // 顯示錯誤訊息
            exit(1); // 退出程式
        } // 結束if-else
    } else if(isdigit(*expr_ptr) || *expr_ptr == '.') { // 數字
        sscanf(expr_ptr, "%lf", &value); // 讀取數字
        while(isdigit(*expr_ptr) || *expr_ptr == '.') expr_ptr++; // 移動指針
    } else { // 無效字元
        printf("錯誤: 無效字元 '%c'\n", *expr_ptr); // 顯示錯誤訊息
        exit(1); // 退出程式
    } // 結束if-else

    return value; // 返回解析的值
} // 結束parse_factor函數
