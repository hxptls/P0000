/*
 * parameters.h
 * Created by Hexapetalous on Jan 3, 2016.
 *
 * This is a part of P0000, a number division.
 * This is the bridge with the command line preceding part.
 *
 * Copyright (c) 2016 Hexapetalous. All rights reserved.
 * The code is licensed to MIT License.
 */
#ifndef P0000_PARAMETERS_H
/*
 * This function saves argus from command line. Input:
 *  argc: int       the command line arguments' count
 *  argv: char **   the command line arguments
 *  type: Type*     what kind(s) of work will be done
 *  number: int*    the bigger number in the program
 *  divisor: int*   the number that will cut `number` in some way
 * Returning code:
 *  0   good
 *  1   die
 */
typedef unsigned int Type;
#define DIVIDE_WITH_SAME_DIGIT 0x0001
int get_command_line_parameters(int argc, char * argv[], Type * type,
                                int * number, int * divisor);
#define P0000_PARAMETERS_H

#endif //P0000_PARAMETERS_H
