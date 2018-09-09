/**
 * @file DynamicArray.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/03/2018
 *
 * @brief Header file for @c DynamicArray implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

#ifndef DYNAMIC_ARRAY_SPEC
#define DYNAMIC_ARRAY_SPEC

#define DYNAMIC_ARRAY_INIT_SIZE 8
#define DYNAMIC_ARRAY_GROW_RATE 2

#endif

	/**
	 * @brief A DynamicArray that increases in size as needed
	 *
	 * A @c DynamicArray is a wrapper for a dynamic array that grows its buffer
	 * when needed along with many utility functions that are useful for
	 * abstracting its dynamism and avoid direct buffer calls.
	 *
	 * @b Advantages over @c Array
	 * - Dynamic size
	 * - Easy insertion/removal
	 *
	 * @b Drawbacks
	 * - As the array increases in size, shifting elements becomes more
	 * time-consuming
	 *
	 * @b Functions
	 *
	 * @c DynamicArray.c
	 */
	typedef struct DynamicArray
	{
		int *buffer;		/*!< @c DynamicArray data buffer */
		size_t size;		/*!< @c DynamicArray size */
		size_t capacity;	/*!< @c DynamicArray total capacity */
		size_t growth_rate; /*!< @c DynamicArray buffer growth rate */
	} DynamicArray;

	Status dar_init(DynamicArray **dar);
	Status dar_make(DynamicArray **dar, int *array, size_t arr_size);

	Status dar_get(DynamicArray *dar, size_t index, int *result);

	//Status dar_insert(DynamicArray *dar, int *array, size_t arr_size, size_t index);
	Status dar_insert_front(DynamicArray *dar, int value);
	Status dar_insert_at(DynamicArray *dar, int value, size_t index);
	Status dar_insert_back(DynamicArray *dar, int value);

	Status dar_update(DynamicArray *dar, int value, size_t index);

	//Status dar_remove(DynamicArray *dar, size_t from, size_t to);
	Status dar_remove_front(DynamicArray *dar);
	Status dar_remove_at(DynamicArray *dar, size_t index);
	Status dar_remove_back(DynamicArray *dar);

	Status dar_remove_keys(DynamicArray *dar, int value);

	Status dar_display(DynamicArray *darr);
	Status dar_display_raw(DynamicArray *darr);

	Status dar_delete(DynamicArray **darr);
	Status dar_erase(DynamicArray **dar);

	size_t dar_cap(DynamicArray *dar);
	size_t dar_size(DynamicArray *dar);

	bool dar_is_empty(DynamicArray *dar);
	bool dar_is_full(DynamicArray *dar);

	Status dar_find_max(DynamicArray *dar, int *result);
	Status dar_find_min(DynamicArray *dar, int *result);
	Status dar_find_max_pos(DynamicArray *dar, size_t *result);
	Status dar_find_min_pos(DynamicArray *dar, size_t *result);

	Status dar_frequency(DynamicArray *dar, int value, size_t *frequency);

	Status dar_contains(DynamicArray *dar, int value, bool *result);
	bool dar_exists(DynamicArray *dar, int value);

	Status dar_find_occurrance_first(DynamicArray *dar, int value, size_t *position);
	Status dar_find_occurrance_last(DynamicArray *dar, int value, size_t *position);

	//Status dar_copy(DynamicArray *dar, DynamicArray **result);
	//Status dar_merge_sorted(DynamicArray *dar1, DynamicArray *dar2, DynamicArray **result);

	//Status dar_append(DynamicArray *dar1, DynamicArray *dar2);
	//Status dar_prepend(DynamicArray *dar1, DynamicArray *dar2);

	//Status dar_is_sorted(DynamicArray *dar, bool *result);
	//Status dar_reverse(DynamicArray *dar);
	//Status dar_sort_bubble(DynamicArray *dar);
	//Status dar_sort_selection(DynamicArray *dar);
	//Status dar_sort_insertion(DynamicArray *dar);

	Status dar_grow(DynamicArray *dar, size_t size);
	Status dar_realloc(DynamicArray *dar);

#ifdef __cplusplus
}
#endif