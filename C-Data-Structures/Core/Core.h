/**
 * @file Core.h
 *
 * @author Leonardo Vencovsky
 * @date 04/04/2018
 *
 * @brief Header file for Core module
 *
 * The Core includes an @c enum type for status codes and other utility
 * functions.
 *
 * @note A note about Core.h
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

	/**
	 * @brief Status code returned by functions
	 *
	 * These status codes are returned by almost all functions in the project.
	 * They are used to prevent unwanted results when a function fails and can
	 * also be used by the user to control his/her own program flow.
	 *
	 */
	typedef enum Status {
		DS_OK                       = 0, /**< Returned by a function when all operations were successful */
		DS_ERR_INVALID_POSITION     = 1, /**< When an invalid position is passed as argument */
		DS_ERR_INVALID_OPERATION    = 2, /**< When an invalid operation is made (e.g. remove element of an empty list ) */
		DS_ERR_INVALID_SIZE         = 3, /**< When an invalid size is given */
		DS_ERR_NOT_FOUND            = 4, /**< When a search fails to find a value ) */
		DS_ERR_ALLOC                = 5, /**< When a function fails to allocate memory  */
		DS_ERR_OPERATION_FAILED     = 6, /**< When a function does not receive <code>DS_OK</code> from an internal function */
		DS_ERR_UNEXPECTED_RESULT    = 7, /**< When an unexpected result happens. Contact developers. */
		DS_ERR_ITER                 = 8, /**< When an iteration reaches an unexpected value */
		DS_ERR_NULL_POINTER         = 9 /**< When a @c NULL parameter is passed to a function */
	} Status;
	
	char * status_repr(Status status);

	void print_status_repr(Status status);

#ifdef __cplusplus
}
#endif