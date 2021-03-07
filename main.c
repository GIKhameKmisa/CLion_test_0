#include <stdio.h>

int main() {
    int num = 520;
    const int cnum = 880;
    const int *pc = &cnum;

    printf("cnum: %d, &cnum: %p\n", cnum, &cnum);
    printf("*pc: %d, pc: %p\n", *pc, pc);

//    *pc = 1024;  // 尝试修改 *pc 的值，报错
    printf("*pc: %d\n", *pc);

    return 0;
}
