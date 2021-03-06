/*
 * proc.c
 * Created by Hexapetalous on Jan 2, 2016.
 *
 * For more info, check `proc.h`.
 * Copyright (c) 2016 Hexapetalous. All rights reserved.
 */
#include "proc.h"
#include <stdio.h>

/*Gears start.*****************************************************************/
int get_biggest_knife(int mountain, int climber);
int cut_into_small_pieces(int watermelon, int * knife);
void print_optional_plus_symbol(void);
int check_for_size(int w, int k);
int check_for_suitable_knife(int w, int k);
/*Gears end.*******************************************************************/

/*Always cut into the biggest pieces of possible.*/
int divide_into_numbers_with_same_digit_and_print(int watermelon, int knife)
{
    printf("%d = ", watermelon);
    int biggest_knife = get_biggest_knife(watermelon, knife);
    int rest_wm = watermelon;
    while (rest_wm > 0)
    {
        print_optional_plus_symbol();
        rest_wm = cut_into_small_pieces(rest_wm, &biggest_knife);
    }
    return 0;
}

#define MAX_WATERMELON 200000000
int check_arguments(int watermelon, int knife)
{
    if (check_for_size(watermelon, knife) != 0)
        return -1;
    if (check_for_suitable_knife(watermelon, knife) != 0)
        return -1;
    return 0;
}

int check_for_size(int watermelon, int knife)
{
    if (watermelon > MAX_WATERMELON || watermelon < 1)
    {
        printf("Illegal value: %d is too large or small(max %d, min 10).\n",
               watermelon, MAX_WATERMELON);
        return 1;
    }
    else if (knife > 9 || knife < 1)
    {
        printf("Illegal value: %d(should between 1 and 9).\n", knife);
        return 2;
    }
    else if (watermelon < knife)
    {
        printf("Illegal value: %d should be greater than %d.\n",
               watermelon, knife);
        return 3;
    }
    return 0;
}

int check_for_suitable_knife(int watermelon, int knife)
{
    if (watermelon % knife != 0)
    {
        printf("Error: %d can\'t be resolved by %d.\n", watermelon, knife);
        return -1;
    }
    return 0;
}

int get_biggest_knife(int mountain, int climber)
{
    int c;
    for (c = climber; c <= mountain; c = c * 10 + climber)
        ;
    return c / 10;
}

int cut_into_small_pieces(int watermelon, int * knife)
{
    if (watermelon < *knife)
        *knife /= 10;
    printf("%d", *knife);
    return watermelon - *knife; /*Cut!*/
}

/* The first number doesn't need a '+' before it.*/
void print_optional_plus_symbol(void)
{
    static int flag = 0;
    if (flag == 0)
        flag = 1;
    else
        printf(" + ");
    return;
}
