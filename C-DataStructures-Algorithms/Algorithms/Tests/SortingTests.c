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

	// SORTING TESTS

	clock_t begin, end;
	double result;
	size_t i, j;

	int *arr;
	char *names[3] = { "Selection Sort", "Insertion Sort", "Bubble Sort" };

	Status(*sorting_functions[3])(int *, size_t);

	sorting_functions[0] = sort_selection_array_int;
	sorting_functions[1] = sort_insertion_array_int;
	sorting_functions[2] = sort_bubble_array_int;

	for (j = 0; j < 2; j++)
	{
		size = 10000;

		for (i = 0; i < 8; i++)
		{
			random_array_int(&arr, size);

			begin = clock();
			sorting_functions[j](arr, size);
			end = clock();

			result = (double)(end - begin) / CLOCKS_PER_SEC;

			printf("\nResult of %s for %zu integers: %lf", names[j], size, result);

			free(arr);
			
			size += 10000;
		}

	}

	printf("\n");
	return 0;
}