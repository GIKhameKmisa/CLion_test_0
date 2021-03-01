#include <stdio.h>

int main() {
    char pint[100];
    char *p1 = pint;
    printf("请输入一个英文句子");
    scanf("%[^\n]", pint);
    char temp;
    while (1) {
        temp = *p1++;
        if (temp == 'i') {
        } else if (temp == '\0') {
            printf("%c", temp);
            break;
        } else {
            printf("%c", temp);
        }
    }
}
