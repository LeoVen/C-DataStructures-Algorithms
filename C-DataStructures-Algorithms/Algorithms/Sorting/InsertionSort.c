/**
 * @file InsertionSort.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 07/08/2018
 *
 * @brief Insertion sorting function
 *
 */

#include "Core.h"

Status sort_insertion_array_int(int *array, size_t arr_size)
{
	if (array == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr_size < 2)
		return DS_ERR_INVALID_SIZE;

	size_t i, j;
	int num;
	for (i = 1; i < arr_size; i++)
	{

		num = array[i];

		j = i - 1;

		while (array[j] > num)
		{
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = num;
	}

	return DS_OK;
}
