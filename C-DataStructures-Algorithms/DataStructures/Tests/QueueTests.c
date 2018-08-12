/**
 * @file QueueTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Test Cases for @c Queue implementations in C
 *
 */

#include "Queue.h"

int QueueTests(void)
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
	for (i = 0; i < 6; i++)
	{
		que_enqueue(que, i);
		que_display(que);
	}

	int result;
	que_peek_front(que, &result);
	printf("\nfront: %d", result);

	que_peek_rear(que, &result);
	printf("\nrear: %d\n", result);

	for (i = 0; i < 6; i++)
	{
		que_dequeue(que);
		que_display(que);
	}

	for (i = 0; i < 10; i++)
		que_enqueue(que, i);

	size_t size;

	que_get_length(que, &size);

	que_display(que);

	printf("\nQueue length: %zu", size);

	que_erase_queue(&que);

	for (i = 0; i < 100; i++)
		que_enqueue(que, i);

	Queue *que_even = NULL, *que_odd = NULL;
	QueueNode *node;
	int data;
	size_t len, j;
	if (que_init_queue(&que_odd) == DS_OK && que_init_queue(&que_even) == DS_OK)
	{
		que_get_length(que, &len);
		for (j = 0; j < len; j++)
		{
			que_peek_front(que, &data);
			if (data % 2 == 0)
			{
				que_dequeue_node(que, &node);
				que_enqueue_node(que_even, node);
			}
			else
			{
				que_dequeue_node(que, &node);
				que_enqueue_node(que_odd, node);
			}
		}
	}

	que_display(que);
	que_display(que_odd);
	que_display(que_even);

	Queue *copy_queue;

	que_copy_queue(que_even, &copy_queue);

	que_delete_queue(&que);
	que_delete_queue(&que_odd);
	que_delete_queue(&que_even);

	que_init_queue(&que);

	int l, k, l_max = 4, front, rear;
	len = 0;
	for (i = 0; i < 1000; i++)
	{

		node = NULL;

		printf("\n---------- ---------- ---------- ---------- ----------");

		k = rand();
		l = rand();

		que_get_length(que, &len);

		if (k % 2 == 0 && len < l_max)
		{
			// Enqueue
			if (l % 2 == 0)
			{
				printf("\nque_enqueue()");
				que_enqueue(que, rand() % 100);
			}
			else
			{
				printf("\nque_enqueue_node()");
				que_make_node(&node, rand() % 100);
				que_enqueue_node(que, node);
			}
		}
		else
		{
			// Dequeue
			if (l % 2 == 0)
			{
				printf("\nque_dequeue()");
				que_dequeue(que);
			}
			else
			{
				printf("\nque_dequeue_node()");
				que_dequeue_node(que, &node);
				free(node);
			}
		}

		front = 0;
		rear = 0;

		que_peek_front(que, &front);
		que_peek_rear(que, &rear);
		que_get_length(que, &len);

		que_display(que);

		printf("\nQueue length: %zu", len);
		printf("\nFront node: %d", front);
		printf("\nRear node: %d", rear);

		printf("\n---------- ---------- ---------- ---------- ----------");
	}

	que_delete_queue(&que);

	printf("\n\nCopied Queue:\n\n");

	que_display(copy_queue);

	que_delete_queue(&copy_queue);

	printf("\n");
	return 0;
}