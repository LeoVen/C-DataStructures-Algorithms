/**
 * @file GeneratorsTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/04/2018
 *
 * @brief Test Cases for Generators
 *
 */

#include "Random.h"

int GeneratorsTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |          C Random Generators        |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	printf("\nGenerating random numbers between 0 and 9 (inclusive)\n");

	int i, res;
	for (i = 0; i < 100; i++) {

		random_int_between(&res, 0, 9);
		printf("%d ", res);
	}

	printf("\n");
	return 0;
}