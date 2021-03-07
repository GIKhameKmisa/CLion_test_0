//
// Created by 15403 on 2021/3/7.
//
/*
 * 你应该听说过 itoa 函数（函数文档 -> 传送门），它的作用是将一个整数转换成字符串形式存储。
 * 现在要求我们自己来实现一个类似功能的函数 myitoa(int num, char *str)，
 * 该函数的第一个参数是待转换的整型变量，第二参数传入一个字符指针，用于存放转换后的字符串。*/
#include <stdio.h>

char *myitoa(int num, char *str);

int main() {
    printf("请输入要转换的整数");
    int num;
    scanf("%d,", &num);
    char str[10];
    printf("转换后的字符串为: %s", myitoa(num, str));

}

char *myitoa(int num, char *str) {
    /* for (int i = 0; i < sizeof(num_char) / sizeof(char); i++) {
         *(str+i) =
     }*/
    // 首先判断正负,其次判断位数,之后从最大位开始求商
    // 判断正负 < 0 则第一位 '-'
    // 判断位数 当商等于0时 除数为 最大位 加一 1234/10000
    //开始求商,1234/1000 得1 234/100 得2 34/10 得3 4/1 得 4
    int temp;//临时数字会改变
    if (num < 0) {
        str[0] = '-';
        temp = -num;
    } else {
        str[0] = ' ';
        temp = num;
    }
    //判断位数
    int num_dividend = temp; //被除数
    int num_divisor = 10; //除数
    int answer = num_dividend / num_divisor; //得数

    while (answer != 0) {
        num_divisor *= 10;
        answer = num_dividend / num_divisor;
    }

    //开始转换
    int i = 1;
    while (num_divisor != 1) { //1234 234 34 4
        num_divisor /= 10;
        answer = num_dividend / num_divisor;
        num_dividend = num_dividend - answer * num_divisor;
        str[i] = answer + '0';
        i++;
    }
    str[i] = '\0';
    return str;
}
