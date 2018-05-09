/**
 * @file PriorityQueueTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 08/05/2018
 *
 * @brief Test Cases for @c PriorityQueue implementations in C
 *
 */

#include "..\Headers\PriorityQueue.h"

int PriorityQueueTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |           C Priority Queue          |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	PriorityQueue *pqe;

	pqe_init_queue(&pqe);

	if (pqe_is_empty(pqe))
		printf("Priority Queue is Empty");

	printf("\n");
	return 0;
}