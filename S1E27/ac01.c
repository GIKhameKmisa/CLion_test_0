//
// Created by 15403 on 2021/3/7.
//
/*
 * 请编写一个程序，测试一下你当前的计算机是大端还是小端？*/
#include <stdio.h>

int main() {
    int a = 0x1234;
    char *p = (char *) &a;
    if (*p == 0x12) {
        printf("大端");
    } else if (*p == 0x34) {
        printf("小端");
    }
}