//
// Created by wan on 1/2/16.
//
#include <stdio.h>

int main(void) {
    printf("Input:");
    int a;
    scanf("%d", &a);
    if (2016 % a != 0) {
        printf("No way. Exit.\n");
        return 0;
    }
    int s = 2016;
    printf("2016 = ");
    int flag = 0, b;
    for (b = 1111; b >= 1; b /= 10) {
        int t = a * b;
        for (;;) {
            if (s >= t) {
                if (flag == 0)
                    flag = 1;
                else
                    printf(" + ");
                printf("%d", t);
                s -= t;
            }
            else
                break;
        }
    }
    printf("\n");
    return 0;
}
