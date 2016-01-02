/*
 * main.c
 * Created by Hexapetalous on Jan 1 2016.
 *
 * This is a part of P0000, a number division.
 * This is the entry of the program.
 *
 * Copyright (c) 2016 Hexapetalous. All rights reserved.
 * The code is licensed to MIT License.
 */
#include <stdio.h>
#include "proc.h"

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
    divide_into_numbers_with_same_digit_and_print(z, a);
    printf("\n");
    return 0;
}
