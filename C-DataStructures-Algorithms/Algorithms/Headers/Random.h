/**
 * @file Random.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/04/2018
 *
 * @brief Header File for Random Generators functions
 *
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Algorithms.h"

	Status random_array_int(int **array, size_t size);

	Status random_int_between(int *result, int min, int max);

	//Status random_char(char **ch);
	Status random_array_char(char **string, size_t size);

#ifdef __cplusplus
}
#endif