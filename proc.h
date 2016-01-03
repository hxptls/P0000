/*
 * proc.h
 * Created by Hexapetalous on Jan 2, 2016.
 *
 * This is a part of P0000, a number division.
 * This is the procedure of the program.
 *
 * Copyright (c) 2016 Hexapetalous. All rights reserved.
 * The code is licensed to MIT License.
 */
#ifndef P0000_PROC_H
/*
 * This function assumes the arguments are legal:
 *  number:int  the big number that will be divided
 *  divider:int       the divider
 * It will divide `watermelon` like, if `watermelon` is 2016 and `knife` is 7:
 *  2016 = 777 + 777 + 77 + 77 + 77 + 77 + 77 + 77
 * will be printed on the screen. It has side effect.
 * The output is the status of it's work:
 *  0   good
 *  1   die
 */
int divide_into_numbers_with_same_digit_and_print(int number, int divider);
/*
 * The arguments' are the same.
 * If `number` or `divider` is too big or small, or `number` is not divisible by
 * `divider`, it will not pass the check.
 * Output:
 *  0   good
 *  1   die
 * The biggest value of `number` is defined with implementation and it should
 * greater than 0. `divider` is between 0 and 9.
 */
int check_arguments(int number, int divider);
#define P0000_PROC_H

#endif //P0000_PROC_H
