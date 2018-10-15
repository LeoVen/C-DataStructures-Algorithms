/**
* @file DequeArray.h
*
* @author Leonardo Vencovsky (https://github.com/LeoVen)
* @date 08/10/2018
*
* @brief Header file for @c DequeArray implementations in C
*
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

#ifndef DEQUE_ARRAY_SPEC
#define DEQUE_ARRAY_SPEC

#define DEQUE_ARRAY_INIT_SIZE 8
#define DEQUE_ARRAY_GROW_RATE 200

#endif

	/**
	 * A @c DequeArray is a buffered @c Deque with @c enqueue and @c dequeue
	 * operations on both ends. It also has the ability to increase in size.
	 *
	 * @b Advantages over @c Deque
	 * - Fast insertion
	 * - No need of pointers, only the data is allocated in memory
	 *
	 * @b Drawbacks
	 * - When the @c DequeArray is full the buffer needs to be reallocated and
	 * elements need to be shifted
	 *
	 * @b Functions
	 *
	 * @c DequeArray.c
	 *
	 */
	typedef struct DequeArray
	{
		int *buffer;		/*!< @c DequeArray data buffer */
		size_t front;       /*!< Index of the first node at the front of the @c Deque */
		size_t rear;        /*!< Index of the first element at the rear of the @c Deque */
		size_t size;		/*!< Total elements in the @c DequeArray */
		size_t capacity;	/*!< @c DequeArray total capacity */
		size_t growth_rate; /*!< @c DequeArray buffer growth rate */
	} DequeArray;

	Status dqa_init(DequeArray **dqa);
	Status dqa_create(DequeArray **dqa, size_t initial_capacity, size_t growth_rate);

	Status dqa_get_length(DequeArray *dqa, size_t *result);

	Status dqa_enqueue_front(DequeArray *dqa, int value);
	Status dqa_enqueue_rear(DequeArray *dqa, int value);

	Status dqa_dequeue_front(DequeArray *dqa, int *value);
	Status dqa_dequeue_rear(DequeArray *dqa, int *value);

	Status dqa_display(DequeArray *dqa);
	Status dqa_display_raw(DequeArray *dqa);

	Status dqa_delete(DequeArray **dqa); // Erases and sets to NULL
	Status dqa_erase(DequeArray **dqa);  // Erases and inits

	Status dqa_peek_front(DequeArray *dqa, int *result);
	Status dqa_peek_rear(DequeArray *dqa, int *result);

	size_t dqa_size(DequeArray *dqa);
	size_t dqa_capacity(DequeArray *dqa);

	bool dqa_is_empty(DequeArray *dqa);
	bool dqa_is_full(DequeArray *dqa);
	bool dqa_fits(DequeArray *dqa, size_t size);

	Status dqa_copy(DequeArray *dqa, DequeArray **result);

	Status dqa_realloc(DequeArray *dqa);

#ifdef __cplusplus
}
#endif;
