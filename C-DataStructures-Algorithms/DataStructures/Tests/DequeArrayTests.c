/**
 * @file DequeTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 09/05/2018
 *
 * @brief Test Cases for @c Deque implementations in C
 *
 */

#include "DequeArray.h"

int DequeArrayTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Deque Array            |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	DequeArray *deque, *new_deque;

	int k, front, rear;;
	dqa_create(&deque, 20, 350);

	int i, j;
	for (i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			dqa_enqueue_front(deque, i);
		else
			dqa_enqueue_rear(deque, i);

		printf("\n");

		for (k = 0; k < deque->capacity; k++)
		{
			printf("%d ", deque->buffer[k]);
		}

		dqa_peek_front(deque, &front);
		dqa_peek_rear(deque, &rear);

		printf("\nFront     : %zu", deque->front);
		printf("\nRear      : %zu", deque->rear);
		printf("\nSize      : %zu", deque->size);
		printf("\nCapacity  : %zu", deque->capacity);
		printf("\nFront V   : %zu", front);
		printf("\nRear V    : %zu", rear);
	}

	dqa_copy(deque, &new_deque);

	for (i = 0; i < 40; i++)
	{
		if (i % 2 == 0)
			dqa_dequeue_front(deque, &j);
		else
			dqa_dequeue_rear(deque, &j);

		printf("\n");

		for (k = 0; k < deque->capacity; k++)
		{
			printf("%d ", deque->buffer[k]);
		}

		dqa_peek_front(deque, &front);
		dqa_peek_rear(deque, &rear);

		printf("\nFDequeued : %zu", j);
		printf("\nFront     : %zu", deque->front);
		printf("\nRear      : %zu", deque->rear);
		printf("\nSize      : %zu", deque->size);
		printf("\nCapacity  : %zu", deque->capacity);
		printf("\nFront V   : %zu", front);
		printf("\nRear V    : %zu", rear);
	}

	dqa_display(deque);
	dqa_display(new_deque);
	
	dqa_delete(&deque);
	dqa_delete(&new_deque);

	printf("\n");
	return 0;
}