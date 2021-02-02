//
// Created by 15403 on 2021/1/30.
//
/* 编写一个程序，接收用户的输入，并将前 9 个字符以正方形矩阵（3 * 3）的方式输出。
 * 3*3可以使用二维数组存储字符, char square[3][3] = {0};
 * */
#include <stdio.h>

int main() {
    char square[3][3] = {'0'};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j) {
            *(*(square + i) + j) = getchar();
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j) {
            printf("%c ", *(*(square + i) + j));
        }
        printf("\n");
    }


}