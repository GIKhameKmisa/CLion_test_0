//
// Created by 15403 on 2021/3/7.
//
/*
 * 横向打印FISHC,自定义间隔*/
#include <stdio.h>
#include <string.h>

void print_FISHC(void);

int main() {
    print_FISHC();
}

void print_FISHC(void) {
    char *letter[] = {
            "\
\########@\
\##      @\
\##      @\
\######  @\
\##      @\
\##      @\
\##      @\
",
            "\
\####@\
\ ## @\
\ ## @\
\ ## @\
\ ## @\
\ ## @\
\####@\
",
            "\
 \###### @\
\##    ##@\
\##      @\
\ ###### @\
\      ##@\
\##    ##@\
\ ###### @\
",
            "\
\##     ##@\
\##     ##@\
\##     ##@\
\#########@\
\##     ##@\
\##     ##@\
\##     ##@\
",
            "\
\ ###### @\
\##    ##@\
\##      @\
\##      @\
\##      @\
\##    ##@\
\ ###### @\
"
    };

    printf("请输入字母的间隔(空格数):");
    int num;
    scanf("%d", &num);
    for (int i = 0; i < 7; ++i) {
        //七行
        for (int j = 0; j < 5; ++j) {
            //五个字母判断长度len,然后判断行数,letter[j][]
            int len = strlen(letter[j]) / 7; //每个字母每一行有多少字符包括@
            int hash = i * len; //字母的第几行
            int k = 0;
            while (letter[j][hash + k] != '@') {
                putchar(letter[j][hash + k]);
                k++;
            }
            for (int l = 0; l < num; ++l) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}