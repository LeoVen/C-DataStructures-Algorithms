/**
 * @file Array.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/03/2018
 *
 * @brief Header file for Array implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

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

	Status arr_erase(Array *array);
	Status arr_delete(Array **arr);

	Status arr_max(Array *arr, int *result);
	Status arr_min(Array *arr, int *result);
	Status arr_frequency(Array *arr, int key, int *result);
	Status arr_key_positions(Array *arr, Array **result, int key);

	// Status arr_grow(Array **arr);
	// Status arr_shrink(Array **arr);

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