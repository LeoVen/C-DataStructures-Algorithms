/**
 * @file Core.c
 *
 * @author Leonardo Vencovsky
 * @date 04/04/2018
 *
 * @brief Source file for Core module
 *
 * The Core includes an @c enum type for status codes and other utility
 * functions.
 *
 * @note A note about Core.c
 *
 */

#include "Core.h"

/**
 * @brief Visualize status codes
 *
 * This function returns a string that represents the status error for
 * better visualization.
 *
 * @param[in] status The status returned by a function
 *
 * @return A string equivalent for the status name
 */
char * status_repr(Status status)
{
	switch (status)
	{
		case DS_OK: return "DS_OK";
		case DS_ERR_INVALID_POSITION: return "DS_ERR_INVALID_POSITION";
		case DS_ERR_INVALID_OPERATION: return "DS_ERR_INVALID_OPERATION";
		case DS_ERR_INVALID_SIZE: return "DS_ERR_INVALID_SIZE";
		case DS_ERR_NOT_FOUND: return "DS_ERR_NOT_FOUND";
		case DS_ERR_ALLOC: return "DS_ERR_ALLOC";
		case DS_ERR_OPERATION_FAILED: return "DS_ERR_OPERATION_FAILED";
		case DS_ERR_UNEXPECTED_RESULT: return "DS_ERR_UNEXPECTED_RESULT";
		case DS_ERR_ITER: return "DS_ERR_ITER";
		case DS_ERR_NULL_POINTER: return "DS_ERR_NULL_POINTER";
	}
}

void print_status_repr(Status status)
{
	printf("\n%s", status_repr(status));
}