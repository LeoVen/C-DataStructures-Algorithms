/**
 * @file QueueTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Test Cases for @c Queue implementations in C
 *
 */

#include "..\Headers\Queue.h"

int QueueTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Static Queue           |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Queue *que;

	que_init_queue(&que);

	printf("\nLength: %zu", que->length);

	printf("\n");
	return 0;
}