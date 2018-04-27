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

#include "..\..\Core\Core.h"

	typedef struct CircularBuffer {
		size_t length;                      /*!< Maximum Buffer length */
		size_t *start;                      /*!< Where elements are added */
		size_t *end;                        /*!< Where elements are removed */
		int * buffer;                       /*!< Buffer */
	} CircularBuffer;

	Status cbf_init(CircularBuffer **squ, size_t length);

	//CircularBuffer * cbf_get();

	//Status cbf_get_length(CircularBuffer *cbf, size_t *result);

	//Status cbf_add(CircularBuffer *cbf, int value);

	//Status cbf_remove(CircularBuffer *cbf, int *value);

	//Status cbf_delete(CircularBuffer **cbf);
	//Status cbf_erase(CircularBuffer **cbf);

	//Status cbf_wrap(CircularBuffer **cbf);

	//bool cbf_is_empty(CircularBuffer *cbf);
	//bool cbf_is_full(CircularBuffer *cbf);

#ifdef __cplusplus
}
#endif;


#pragma once
