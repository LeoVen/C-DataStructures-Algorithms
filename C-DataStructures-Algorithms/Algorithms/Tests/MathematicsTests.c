/**
 * @file MathematicsTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/04/2018
 *
 * @brief Test Cases for Mathematical Algorithms
 *
 */

#include "Core.h"
#include "Algorithms.h"


int MathematicsTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |             C Mathematics           |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	size_t n = 32, k = 54;
	printf("\nJosephus of %zu by %zu : %zu", n, k, Josephus(n, k));

	n = 331;
	k = 98;
	printf("\nJosephus of %zu by %zu : %zu", n, k, Josephus(n, k));

	printf("\n");
	return 0;
}