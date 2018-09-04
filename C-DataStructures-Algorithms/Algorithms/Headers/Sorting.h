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
extern "C"
{
#endif

#include "Algorithms.h"

	Status sort_bubble_array_int(int *array, size_t arr_size);
	Status sort_selection_array_int(int *array, size_t arr_size);
	Status sort_insertion_array_int(int *array, size_t arr_size);
	Status sort_quicksort_array_int(int *array, size_t arr_size);

	Status sort_swap_integer(int *array, size_t p1, size_t p2);

#ifdef __cplusplus
}
#endif