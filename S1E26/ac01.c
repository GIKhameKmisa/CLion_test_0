//
// Created by 15403 on 2021/2/27.
//
/*
 * 分割字符串。用户输入一个英文句子，你的程序将这个字符串按空格进行分割，返回由单词组成的二维数组。
 * 要求:
 *      返回的二维数组必须尽可能地节省空间（利用C语言的变长数组来实现）
 *      不能使用现成的函数帮忙（你只能 #include <stdio.h>）*/
#include <stdio.h>

#define MAX 1024

int main() {
    char pint[MAX];
    char *p1 = pint;
    printf("请输入一个英文句子");
    scanf("%[^\n]", pint); //读取输入的句子存储到pint字符串数组中
    int i, j, num_word, num_char;
    char temp;
    i = 0;
    j = 0;
    num_word = 0;
    num_char = 0;
    while (1) {
        temp = *p1++;
        if (temp == ' ') {

        } else if (temp == '\0') {
            break;
        } else {
            i++;
            if ((*p1 == ' ') || (*p1 == '\0')) {
                num_word++;
                j++;
            }
            if (j) {
                num_char = i > num_char ? i : num_char;
                i = 0;
                j = 0;
            }
        }
    }
    num_char++;
    char result[num_word][num_char];
    char (*p2)[num_char] = result;
    p1 = pint;
    while (1) {
        temp = *p1++;

        if (temp == ' ') {

        } else if (temp == '\0') {
            break;
        } else {
            *(*(p2 + i) + j) = temp;
            j++;
            if ((*p1 == ' ') || (*p1 == '\0')) {
                while (j < (num_char - 1)) {
                    *(*(p2 + i) + j) = ' ';
                    j++;
                }
                i++;
                j = 0;
            }
        }
    }
    printf("分割结果已存放到result[%d][%d]的二维数组中...\n", num_word, num_char);
    printf("现在依次打印每个单词:\n");
    for (int i = 0; i < num_word; i++) {
        for (int j = 0; j < num_char - 1; j++) {
            printf("%c", *(*(p2 + i) + j));
        }
        printf("\n");
    }
}