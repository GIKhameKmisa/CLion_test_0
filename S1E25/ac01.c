//
// Created by 15403 on 2021/2/13.
//
/*
 * 要求一：允许用户自定义输入两个矩阵的尺寸和数据
 * 要求二：输出格式如下 用户先输入 两个矩阵的尺寸 M*P 和 P*N 再输入 两个矩阵的值 最后输出计算结果
 * 要求三：由于我们还没有教动态内存分配，所以不允许使用 malloc 函数。但你可以使用 VLA 变长数组
 * */

#include <stdio.h>

int main() {
    int M, P, N, R;
    char temp;
    printf("请输入第一个矩阵尺寸 :");
    scanf("%d %c %d", &M, &temp, &P);
    printf("请输入第二个矩阵尺寸 :");
    scanf("%d %c %d", &P, &temp, &N);

    int square_1[M][P];
    int square_2[P][N];
    int square_3[M][N];
    printf("请输入第一个矩阵的值\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            *(*(square_1 + i) + j) = getchar();
            getchar();
        }
    }
    printf("请输入第二个矩阵的值\n");
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < N; ++j) {
            *(*(square_2 + i) + j) = getchar();
            getchar();
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < P; ++k) {
                *(*(square_3 + i) + j) += (*(*(square_1 + i) + k)) * (*(*(square_2 + k) + j));
            }
        }
    }
    R = M > P ? M : P; //最大行数
    /* 从第一行打印到最后一行 打印到中间行时有 * 和 =
     * 如果没有则用空格替代,*/

}
