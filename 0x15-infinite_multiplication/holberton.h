#ifndef _MULTI_H_
#define _MULTI_H_

#define _TRUE_ 1
#define _FALSE_ 0
#define MAX1 2500
#define MAX2 2500

#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
void multiply(char *num_1, char *num_2);
int is_a_number(char *a_str);
void sum_and_print(char answer[MAX1][MAX2], int len_1, int len_2);
int str_len(char *a);

#endif /*_MULTI_H_*/
