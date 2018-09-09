/**
* @file StackArray.h
*
* @author Leonardo Vencovsky (https://github.com/LeoVen)
* @date 04/08/2018
*
* @brief Header file for @c StackArray implementatiosn in C
*
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

#ifndef STACK_ARRAY_SPEC
#define STACK_ARRAY_SPEC

#define STACK_ARRAY_INIT_SIZE 8
#define STACK_ARRAY_GROW_RATE 2

#endif

	/**
	* A @c StackArray is a buffered @c Stack with LIFO operations (Last-in
	* First-out), so the last item added is the first one to be removed. It
	* also has the ability to increase in size.
	*
	* @b Advantages over @c Stack
	* - Fast insertion and removal
	* - No need of pointers, only the data is allocated in memory
	*
	* @b Drawbacks
	* - When the @c StackArray is full the buffer needs to be reallocated
	*
	* @b Functions
	*
	* @c StackArray.c
	*
	*/
	typedef struct StackArray
	{
		int *buffer;		/*!< @c StackArray data buffer */
		size_t height;		/*!< @c StackArray height */
		size_t capacity;	/*!< @c StackArray total capacity */
		size_t growth_rate; /*!< @c StackArray buffer growth rate */
	} StackArray;

	Status sta_init(StackArray **sta);

	Status sta_get_height(StackArray *sta, size_t *result);
	size_t sta_height(StackArray *sta);

	Status sta_push(StackArray *sta, int value);

	Status sta_slice(StackArray *sta);
	Status sta_pop(StackArray *sta, int *result);

	Status sta_display(StackArray *sta);
	Status sta_display_raw(StackArray *sta);

	Status sta_delete(StackArray **sta); // Erases and sets to NULL
	Status sta_erase(StackArray **sta);  // Erases and inits

	Status sta_look(StackArray *sta, int *result);
	int sta_peek(StackArray *sta);

	bool sta_is_empty(StackArray *sta);
	bool sta_is_full(StackArray *sta);

	//Status sta_copy(StackArray *sta, StackArray **result);

	Status sta_realloc(StackArray *sta);

#ifdef __cplusplus
}
#endif