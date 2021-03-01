//
// Created by 15403 on 2021/3/1.
//
/*
 * 修改代码，使得程序允许用户指定分隔符。*/

#include <stdio.h>

int main() {
    char pint[100];
    char *p1 = pint;
    char ch;
    printf("请输入一个英文句子: ");
    scanf("%[^\n]", pint); //读取输入的句子存储到pint字符串数组中
    getchar();//读取回车
    printf("请输入分隔符: ");
    scanf("%c", &ch);
    int i, j, num_word, num_char;
    char temp;
    i = 0;
    j = 0;
    num_word = 0;
    num_char = 0;
    while (1) {
        temp = *p1++;
        if (temp == ch) {

        } else if (temp == '\0') {
            break;
        } else {
            i++;
            if ((*p1 == ch) || (*p1 == '\0')) {
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

        if (temp == ch) {

        } else if (temp == '\0') {
            break;
        } else {
            *(*(p2 + i) + j) = temp;
            j++;
            if ((*p1 == ch) || (*p1 == '\0')) {
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