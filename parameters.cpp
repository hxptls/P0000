/*
 * parameters.cpp
 * Created by Hexapetalous on Jan 3, 2016.
 *
 * For more info, check `parameters.h`.
 * Copyright (c) 2016 Hexapetalous. All rights reserved.
 */
#include "parameters.h"

int get_command_line_parameters(int argc, char * argv[], Type * type,
                                int * number, int * divisor)
{
    *type = DIVIDE_WITH_SAME_DIGIT;
    *number = 2016;
    *divisor = 7;
    return 1;
}
