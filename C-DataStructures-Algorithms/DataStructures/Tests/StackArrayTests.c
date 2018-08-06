/**
* @file StackArrayTests.c
*
* @author Leonardo Vencovsky (https://github.com/LeoVen)
* @date 04/08/2018
*
* @brief Test Cases for @c StackArray implementations in C
*
*/

#include "StackArray.h"

int StackArrayTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Stack Array            |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	StackArray *stack;
	int i;

	sta_init(&stack);

	for (i = 0; i < 100; i++)
	{
		sta_push(stack, i);
	}

	sta_display(stack);

	while (!sta_is_empty(stack))
	{
		sta_slice(stack);
	}

	sta_display(stack);

	sta_delete(&stack);

	printf("\n");
	return 0;
}