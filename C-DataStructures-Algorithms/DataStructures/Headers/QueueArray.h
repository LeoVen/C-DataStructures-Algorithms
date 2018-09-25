/**
* @file QueueArray.h
*
* @author Leonardo Vencovsky (https://github.com/LeoVen)
* @date 04/08/2018
*
* @brief Header file for @c QueueArray implementations in C
*
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

#ifndef QUEUE_ARRAY_SPEC
#define QUEUE_ARRAY_SPEC

#define QUEUE_ARRAY_INIT_SIZE 8
#define QUEUE_ARRAY_GROW_RATE 2

#endif

	/**
	 * A @c QueueArray is a buffered @c Queue with FIFO operations, (First-int
	 * First-out), so the first item added is the first one to be removed. It
	 * also has the ability to increase in size.
	 *
	 * @b Advantages over @c Queue
	 * - Fast insertion
	 * - No need of pointers, only the data is allocated in memory
	 *
	 * @b Drawbacks
	 * - Slow removal as all items must be shifted
	 * - When the @c QueueArray is full the buffer needs to be reallocated
	 *
	 * @b Functions
	 *
	 * @c QueueArray.c
	 *
	 */
	typedef struct QueueArray
	{
		int *buffer;		/*!< @c QueueArray data buffer */
		size_t length;		/*!< @c QueueArray length */
		size_t capacity;	/*!< @c QueueArray total capacity */
		size_t growth_rate; /*!< @c QueueArray buffer growth rate */
	} QueueArray;

	Status qua_init(QueueArray **qua);

	Status qua_get_length(QueueArray *qua, size_t *result);

	Status qua_enqueue(QueueArray *qua, int value);

	Status qua_dequeue(QueueArray *qua, int *value);
	Status qua_pop(QueueArray *qua);

	Status qua_display(QueueArray *qua);
	Status qua_display_raw(QueueArray *qua);

	Status qua_delete(QueueArray **qua); // Erases and sets to NULL
	Status qua_erase(QueueArray **qua);  // Erases and inits

	Status qua_peek_front(QueueArray *qua, int *result);
	Status qua_peek_rear(QueueArray *qua, int *result);

	size_t qua_length(QueueArray *qua);
	size_t qua_capacity(QueueArray *qua);

	bool qua_is_empty(QueueArray *qua);
	bool qua_is_full(QueueArray *qua);

	//Status qua_copy(QueueArray *qua, QueueArray **result);

	Status qua_realloc(QueueArray *qua);

#ifdef __cplusplus
}
#endif;
