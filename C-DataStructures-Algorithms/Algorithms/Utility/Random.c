/**
 * @file Random.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 11/04/2018
 *
 * @brief Functions that can easily generate random data
 *
 */

#include "Algorithms.h"

Status random_array_int(int **array, size_t size)
{
	(*array) = malloc(size * sizeof(int));

	if (!array)
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < size; i++)
	{

		(*array)[i] = rand();
	}

	return DS_OK;
}

Status random_int_between(int *result, int min, int max)
{
	if (max <= min)
		return DS_ERR_INVALID_ARGUMENT;

	*result = rand() % (max + 1 - min) + min;

	return DS_OK;
}

//Status random_char(char **ch);
//Status random_array_char(int **string, size_t size);
