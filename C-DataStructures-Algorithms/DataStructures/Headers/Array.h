/**
 * @file Array.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/03/2018
 *
 * @brief Header file for @c Array implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "Core.h"

	/**
	 * The @c Array structure is a wrapper for an array of integers that has a
	 * fixed size. It has a few rules for inserting, pushing, updating and
	 * removing values. They are:
	 * - @b The @b zero-value: any zeroes in the array are considered empty
	 * spaces.
	 * - @b Insert: Inserts an integer in a given zero-value position. Returns
	 * @c DS_ERR_INVALID_POSITION if that position is not a zero-value.
	 * - @b Push: Same as Insert but this time an integer is added to the first
	 * available zero-value position. Returns @ DS_ERR_FULL if there are no
	 * zero-value positions.
	 * - @b Update: Updates a non-zero-value position with a new integer. If
	 * the position is a zero-value @c DS_ERR_INVALID_POSITION is returned.
	 * - @b Remove: Sets to zero-value a given position. If the position is
	 * already a zero-value @c DS_ERR_INVALID_POSITION is returned.
	 */
	typedef struct Array {
		int *buffer;
		size_t size;
	} Array;

	Status arr_init(Array **arr, size_t size);

	Array * arr_get(size_t size);

	Status arr_insert(Array *arr, size_t position, int value);
	Status arr_push(Array *arr, int value);

	Status arr_update(Array *arr, size_t position, int value);

	Status arr_remove(Array *arr, size_t position);

	Status arr_display(Array *arr);
	Status arr_display_raw(Array *arr);

	Status arr_delete(Array **arr);
	Status arr_erase(Array *array);

	Status arr_max(Array *arr, int *result);
	Status arr_min(Array *arr, int *result);
	Status arr_frequency(Array *arr, int key, int *result);
	Status arr_key_positions(Array *arr, Array **result, int key);

	bool arr_is_empty(Array *arr);

	Status arr_copy(Array *arr, Array **result);
	
	Status arr_switch(Array *arr, size_t pos1, size_t pos2);
	Status arr_reverse(Array *arr);
	Status arr_blend(Array *arr);

	Status arr_sort_bubble(Array *arr);
	Status arr_sort_selection(Array *arr);
	Status arr_sort_insertion(Array *arr);
	
	
#ifdef __cplusplus
}
#endif