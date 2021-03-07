//
// Created by 15403 on 2021/3/7.
//
/*
 * 课堂中我们通过调用自己定义的 print_C 函数来打印一个大大的字母 C，
 * 现在要求大家自己写几个类似的函数并调用它们。*/

#include <stdio.h>

void print_FISHC(void);

int main() {
    print_FISHC();
    return 0;
}

void print_FISHC(void) {
    printf("########\n"
           "##\n"
           "########\n"
           "##\n"
           "##\n"
           "##\n"
    );
    printf("######\n"
           "  ##\n"
           "  ##\n"
           "  ##\n"
           "######\n");
    printf(" #####\n"
           "##   ##\n"
           "##\n"
           " #####\n"
           "     ##\n"
           "##   ##\n"
           " #####\n");
    printf("##     ##\n"
           "##     ##\n"
           "#########\n"
           "##     ##\n"
           "##     ##\n");
    printf(" #######\n"
           "##     ##\n"
           "##\n"
           "##\n"
           "##     ##\n"
           " #######\n");

}

