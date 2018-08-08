/**
 * @file SelectionSort.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 29/05/2018
 *
 * @brief Selection sorting functions
 *
 */

#include "Sorting.h"

Status sort_selection_array_int(int *array, size_t arr_size)
{
	if (array == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr_size < 2)
		return DS_ERR_INVALID_SIZE;

	size_t i, j, min;
	int tmp;

	for (i = 0; i < arr_size - 1; i++) {

		min = i;

		for (j = i + 1; j < arr_size; j++)
			if (array[j] < array[min])
				min = j;

		tmp = array[min];
		array[min] = array[i];
		array[i] = tmp;

	}
	
	return DS_OK;
}
