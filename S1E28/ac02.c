//
// Created by 15403 on 2021/3/7.
//
/*
 * 让FISHC纵向打印,可以自定义间隔*/

#include <stdio.h>

void print_FISHC(void);

void print_F(void);

void print_I(void);

void print_S(void);

void print_H(void);

void print_C(void);

void print_space(int num);

int main() {
    print_FISHC();
}

void print_FISHC(void) {
    printf("请输入字母的间隔(空格数):");
    int num;
    scanf("%d", &num);
    print_F();
    print_space(num);
    print_I();
    print_space(num);
    print_S();
    print_space(num);
    print_H();
    print_space(num);
    print_C();
}

void print_F(void) {
    printf("########\n"
           "##\n"
           "######\n"
           "##\n"
           "##\n"
           "##\n");
}

void print_I(void) {
    printf("####\n"
           " ## \n"
           " ## \n"
           " ## \n"
           " ## \n"
           " ## \n"
           "####\n");
}

void print_S(void) {
    printf(" ######\n"
           "##    ##\n"
           "##\n"
           " ######\n"
           "      ##\n"
           "##    ##\n"
           " ######\n");
}

void print_H(void) {
    printf("##     ##\n"
           "##     ##\n"
           "##     ##\n"
           "#########\n"
           "##     ##\n"
           "##     ##\n"
           "##     ##\n");
}

void print_C(void) {
    printf(" ######\n"
           "##    ##\n"
           "##\n"
           "##\n"
           "##\n"
           "##    ##\n"
           " ######\n");
}

void print_space(int num) {
    for (int i = 0; i < num; ++i) {
        printf("\n");
    }

}
