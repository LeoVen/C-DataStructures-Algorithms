/**
 * @file Sorting.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/04/2018
 *
 * @brief Header file for Sorting Algorithms
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\..\Core\Algorithms.h"

	Status bubble_sort_array_int(int *array, size_t arr_size);
	Status swap(int *array, size_t p1, size_t p2);

#ifdef __cplusplus
}
#endif