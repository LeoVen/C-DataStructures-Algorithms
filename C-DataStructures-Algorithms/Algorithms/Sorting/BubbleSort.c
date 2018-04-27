/**
 * @file BubbleSort.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 11/04/2018
 *
 * @brief Bubble sorting function
 *
 */

#include "Sorting.h"

Status bubble_sort_array_int(int *array, size_t arr_size)
{
	if (array == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr_size <= 0)
		return DS_ERR_INVALID_SIZE;

	size_t i, j;
	for (i = 0; i < arr_size - 1; i++) {

		for (j = 0; j < arr_size - i - 1; j++) {

			if (array[j] >array[j + 1]) {

				swap(array, j, j + 1);
			}
		}
	}

	return DS_OK;
}

Status swap(int *array, size_t p1, size_t p2)
{
	int temp = array[p1];
	
	array[p1] = array[p2];
	
	array[p2] = temp;

	return DS_OK;
}