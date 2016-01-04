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
#include "parameters.h"

int main(int argc, char * argv[]) {
    int n, d;
    Type t;
    int status = get_command_line_parameters(argc, argv, &t, &n, &d);
    if (status == -1)
        return 1;
    else if (status == 1)
        return 0;

    if (check_arguments(n, d) != 0)
        return 0;
    divide_into_numbers_with_same_digit_and_print(n, d);
    printf("\n");
    return 0;
}
