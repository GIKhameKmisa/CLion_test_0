//
// Created by 15403 on 2021/2/2.
//
/* 这次不限制正方形矩阵的尺寸，要求程序自动计算用户输入的字符，并以最大的正方形矩阵输出
 * （比如用户输入 17 个字符，输出 4 * 4 矩阵）。*/

#include <stdio.h>
#include <math.h>

int main() {
    char str[1024];
    char ch;
    int i = 0;
    scanf("%s", str);
    while ((ch = *(str + i)) != '\0') {
        i++;
    }
    int len = sqrt(i);

    for (i = 0; i < len; i++) {
        for (int j = 0; j < len; ++j) {
            printf("%c ", *(str + j + len * i));
        }
        printf("\n");
    }

}