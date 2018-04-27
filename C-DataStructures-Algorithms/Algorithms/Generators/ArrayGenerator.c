/**
 * @file ArrayGenerator.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 11/04/2018
 *
 * @brief Functions that can easily generate Arrays of any type
 *
 */

#include "..\..\Core\Algorithms.h"

Status generate_array_random(int **array, size_t size)
{
	(*array) = malloc(size * sizeof(int));

	if (!array)
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < size; i++) {

		(*array)[i] = rand();
	}

	return DS_OK;
}