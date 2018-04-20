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
	printf(" |               C Queue               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Queue *que;

	que_init_queue(&que);

	int i;
	for (i = 0; i < 4; i++) {
		que_enqueue(que, i);
		que_display(que);
	}

	for (i = 0; i < 4; i++) {
		que_dequeue(que);
		que_display(que);
	}



	printf("\n");
	return 0;
}