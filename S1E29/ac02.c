//
// Created by 15403 on 2021/3/7.
//
/*
 * 这节课终于学到了可变参数，现在尝试自己模拟实现 printf 格式化输出的基本功能
 * 要求：
1. 自己写一个函数 myprintf，模拟实现 printf 函数的可变参数特性
2. 输出第一个参数中除了格式化占位符外的所有字符
3. 实现 %d 的格式化输出
4. 实现 %c 的格式化输出
5. 实现 %s 的格式化输出
6. 实现 myprintf 函数返回打印了多少字符
7. 全程仅能使用 putchar 唯一一个标准库函数*/

#include <stdio.h>
#include <stdarg.h>

int myprintf(const char *format, ...);

char *myitoa(int num, char *str);

int main() {
    int num;
    num = myprintf(" num = %d", -13);
    myprintf(" count = %d", num);

    return 0;
}

int myprintf(const char *format, ...) {
    va_list vap;
    va_start(vap, format);
    int i = 0; // format
    int count = 0; // str
    // 如果不是格式换位符则直接输出 注意format也是一个字符串
    while (format[i] != '\0') {
        if (format[i] != '%') {
            putchar(format[i]);
            i++;
        } else {
            switch (format[i + 1]) {
                case 'c': {
                    count = 1;
                    putchar(va_arg(vap, int));
                    break;
                }
                case 'd': {
                    count = 0;
                    char str[10];
                    myitoa(va_arg(vap, int), str);
                    while (str[count] != '\0') {
                        putchar(str[count]);
                        count++;
                    }
                    break;
                }
                case 's': {
                    count = 0;
                    char *str = va_arg(vap, char *);
                    while (*(str + count) != '\0') {
                        putchar(*(str + count));
                        count++;
                    }
                    break;
                }
            }
            i += 2;
        }
    }

    /*if (format[1] == 'd') {
        i = 0;
        char str[10];
        myitoa(va_arg(vap, int), str);
        while (str[i] != '\0') {
            putchar(str[i]);
            i++;
        }
    }
    if (format[1] == 'c') {
        i = 1;
        putchar(va_arg(vap, int));
    }
    if (format[1] == 's') {
        i = 0;
        char *str = va_arg(vap, char *);
        while (*(str + i) != '\0') {
            putchar(*(str + i));
        }
    }*/
    va_end(vap);
    return count;
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