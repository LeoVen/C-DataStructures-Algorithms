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

	Status arr_copy(Array *arr, Array **result);
	
	Status arr_blend(Array *arr);

	Status arr_switch(Array *arr, size_t pos1, size_t pos2);
	Status arr_reverse(Array *arr);

	/*

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+
	int bubbleSortCArray(Array *array);
	int selectionSortCArray(Array *array);
	int insertionSortCArray(Array *array);
	int blenderCArray(Array *array);

	// +-------------------------------------+
	// |             Searching               |
	// +-------------------------------------+
	int valueOcurranceCArray(Array *array, int value);
	Array * valuePositionsCArray(Array *array, int value);
	int findMaxCArray(Array *array);
	int findMinCArray(Array *array);

	// +-------------------------------------+
	// |              Display                |
	// +-------------------------------------+
	int displayCArray(Array *array);
	int displayRawCArray(Array *array);
	*/
#ifdef __cplusplus
}
#endif