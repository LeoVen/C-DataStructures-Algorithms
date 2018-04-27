/**
 * @file Display.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 11/04/2018
 *
 * @brief Display functions for many types of data
 *
 */

#include "Core.h"
#include "Display.h"

Status display_array_int(int *array, size_t size)
{
	printf("\n");

	size_t i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n");

	return DS_OK;
}