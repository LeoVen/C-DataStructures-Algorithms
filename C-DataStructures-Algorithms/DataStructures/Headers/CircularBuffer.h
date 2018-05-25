/**
 * @file CircularBuffer.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Header file for @c CircularBuffer implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "Core.h"

	/**
	 * A @c CircularBuffer, Circular Queue, Cyclic Buffer or a Ring Buffer is a
	 * Data Structure that has a fixed-size buffer that is connected by its
	 * ends making a circular buffer zone. The @c CircularBuffer has FIFO
	 * operations so it can also be used as a static @c Queue where the amount
	 * of items that can be queued up is fixed to the maximum size of the
	 * buffer.
	 */
	typedef struct CircularBuffer {
		bool is_empty;                      /*!< If buffer is empty or not */
		size_t length;                      /*!< Current Buffer length */
		size_t max_length;                  /*!< Maximum Buffer length */
		size_t start;                       /*!< Where elements are added */
		size_t end;                         /*!< Where elements are removed */
		int * buffer;                       /*!< Buffer */
	} CircularBuffer;

	Status cbf_init(CircularBuffer **squ, size_t length);

	CircularBuffer * cbf_get(size_t size);

	Status cbf_get_length(CircularBuffer *cbf, size_t *result);

	Status cbf_add(CircularBuffer *cbf, int value);

	Status cbf_remove(CircularBuffer *cbf, int *value);

	Status cbf_display(CircularBuffer *cbf);

	Status cbf_delete(CircularBuffer **cbf); // Deletes structure
	Status cbf_erase(CircularBuffer **cbf); // Erases and init

	Status cbf_wrap(CircularBuffer *cbf);

	bool cbf_is_empty(CircularBuffer *cbf);
	bool cbf_is_full(CircularBuffer *cbf);

#ifdef __cplusplus
}
#endif;
