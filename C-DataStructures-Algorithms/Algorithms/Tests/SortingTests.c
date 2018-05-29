/**
 * @file SortingTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/04/2018
 *
 * @brief Test Cases for Sorting Algorithms
 *
 */

#include "Algorithms.h"


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

	random_array_int(&array, size);

	display_array_int(array, size);

	sort_bubble_array_int(array, size);

	display_array_int(array, size);

	free(array);

	size = 500;

	random_array_int(&array, size);

	display_array_int(array, size);

	sort_selection_array_int(array, size);

	display_array_int(array, size);

	free(array);

	printf("\n");
	return 0;
}