//
// Created by Hexapetalous on 1/1/16.
//
#include <stdio.h>

int main(void) {
    printf("Input[1]:");
    int a;
    scanf("%d", &a);
    printf("Input[2]:");
    int z;
    scanf("%d", &z);
    if (z % a != 0) {
        printf("No way. Exit.\n");
        return 0;
    }
    int s = z;
    printf("%d = ", z);
    int flag = 0, b;
    for (b = 1; b < s; b = b * 10 + 1)
        ;
    for (b /= 10; b >= 1; b /= 10) {
        int t = a * b;
        for (; s >= t;) {
            if (flag == 0)
                flag = 1;
            else
                printf(" + ");
            printf("%d", t);
            s -= t;
        }
    }
    printf("\n");
    return 0;
}
