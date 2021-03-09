#include <stdio.h>
#include <string.h>
#include "md5.h"

void md5(unsigned char *dest, unsigned char *src);

void md5(unsigned char *dest, unsigned char *src)
{
    int i;

    MD5_CTX md5;

    // 初始化
    MD5Init(&md5);
    // 传入明文字符串及其长度
    MD5Update(&md5, src, strlen((char *)src));
    // 得到加密后的字符串
    MD5Final(&md5, dest);
}

int main(void)
{
    int i;
    unsigned char src[128];
    unsigned char dest[16];

    printf("请输入密码：");
    scanf("%s", src);

    printf("你输入的密码是：%s\n", src);

    md5(dest, src);

    printf("加密后的密码是：");
    for (i = 0; i < 16; i++)
    {
        printf("%02x", dest[i]);
    }
    putchar('\n');

    return 0;
}