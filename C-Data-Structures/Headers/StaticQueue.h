/**
* @file StaticQueue.h
*
* @author Leonardo Vencovsky (https://github.com/LeoVen)
* @date 18/04/2018
*
* @brief Header file for @c StaticQueue implementations in C
*
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	typedef struct StaticQueue {
		size_t length;                      /*!< Maximum Queue length */
		size_t *front;                      /*!< Where elements are removed */
		size_t *rear;                       /*!< Where elements are inserted */
		int * buffer;                       /*!< Queue Buffer */
	} StaticQueue;

	Status que_stc_init(StaticQueue **squ, size_t length);

	//Queue * que_stc_get()

	//Status que_stc_get_length(StaticQueue *squ, size_t *result)

	//Status que_stc_enqueue(Queue *squ, int value)

	//Status que_stc_dequeue(Queue *squ, int *value)

	//Status que_stc_delete(Queue **squ)
	//Status que_stc_erase(Queue **squ)

	/*
	 * This allows the queue to be circular. The insertion point wraps around
	 * its end and check if the first position is available. It can also be
	 * used during iteration to change the insertion point.
	 *
	 */
	//Status que_stc_check_circularity(StaticQueue **squ)

#ifdef __cplusplus
}
#endif;


#pragma once
