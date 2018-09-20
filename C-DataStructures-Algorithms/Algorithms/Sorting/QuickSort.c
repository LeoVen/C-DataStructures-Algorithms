/**
 * @file QuickSort.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 03/09/2018
 *
 * @brief Quicksort function
 *
 */

#include "Core.h"

Status sort_quicksort_array_int(int *array, size_t arr_size)
{
	if (arr_size < 2)
		return DS_OK;

	size_t pivot = array[arr_size / 2];

	size_t i, j;
	for (i = 0, j = arr_size - 1; ; i++, j--)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i >= j)
			break;

		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

	sort_quicksort_array_int(array, i);
	sort_quicksort_array_int(array + i, arr_size - i);

	return DS_OK;
}
