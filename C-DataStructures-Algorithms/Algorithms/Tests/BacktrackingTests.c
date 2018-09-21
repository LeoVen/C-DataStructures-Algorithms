/**
 * @file BacktrackingTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/09/2018
 *
 * @brief Test Cases for Backtracking Algorithms
 *
 */

#include "Backtracking.h"

int BacktrackingTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Backtracking           |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Status st = queens(6);

	if (st != DS_OK)
		return st;

	printf("\n");

	int i, solutions;
	for (i = 1; i <= 12; i++)
	{
		if (queens_solutions(i, &solutions) == DS_OK)
			printf(" %d", solutions);
	}

	printf("\n");
	return 0;
}