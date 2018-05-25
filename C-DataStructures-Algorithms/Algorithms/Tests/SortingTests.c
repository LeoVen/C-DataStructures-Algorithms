/**
 * @file SortingTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/04/2018
 *
 * @brief Test Cases for Sorting Algorithms
 *
 */

#include "..\..\Core\Algorithms.h"


int SortingTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |              C Sorting              |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	int *array;
	size_t size = 100;

	generate_array_random(&array, size);

	display_array_int(array, size);

	bubble_sort_array_int(array, size);

	display_array_int(array, size);

	printf("\n");
	return 0;
}