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

	Status arr_init_array(Array **arr, size_t size);

	Array * arr_get_array(size_t size);

	Status arr_insert(Array *arr, size_t position, int value);
	Status arr_push(Array *arr, int value);

	Status arr_update(Array *arr, size_t position, int value);

	Status arr_remove(Array *arr, size_t position);

	Status arr_erase_array(Array *array);

	Status arr_switch_values(Array *arr, size_t pos1, size_t pos2);

	Status arr_copy(Array *arr, Array **result);

	/*
	int reverseCArray(Array *array);

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