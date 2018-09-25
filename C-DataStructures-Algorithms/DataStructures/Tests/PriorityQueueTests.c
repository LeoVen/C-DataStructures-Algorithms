/**
 * @file PriorityQueueTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 08/05/2018
 *
 * @brief Test Cases for @c PriorityQueue implementations in C
 *
 */

#include "PriorityQueue.h"

int PriorityQueueTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |           C Priority Queue          |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	PriorityQueue *prq;

	size_t i, len = 0;

	prq_init_queue(&prq);

	if (prq_is_empty(prq))
		printf("Priority Queue is Empty");

	prq_enqueue(prq, 0, 20);
	prq_enqueue(prq, 1, 10);
	prq_enqueue(prq, 2, 12);
	prq_enqueue(prq, 3, 11);
	prq_enqueue(prq, 4, 11);
	prq_enqueue(prq, 5, 11);
	prq_enqueue(prq, 6, 13);
	prq_enqueue(prq, 7, 21);
	prq_enqueue(prq, 8, 20);

	prq_display(prq);
	// front <- 7 <- 0 <- 8 <- 6 <- 2 <- 3 <- 4 <- 5 <- 1 <- rear

	prq_erase_queue(&prq);

	int highest, lowest;

	prq_priority_highest(prq, &highest);
	prq_priority_lowest(prq, &lowest);

	printf("\nHighest priority : %d\nLowest Priority : %d\n", highest, lowest);

	prq_get_length(prq, &len);

	for (i = 0; i < len; i++)
	{
		prq_dequeue(prq);
	}

	prq_display(prq);

	prq_erase_queue(&prq);

	int f;
	for (f = 0; f < 100; f++)
		prq_enqueue(prq, f, f % 5);

	prq_display(prq);

	PriorityQueue *prq_even = NULL, *prq_odd = NULL;
	PriorityQueueNode *node;
	int data;
	size_t j;
	if (prq_init_queue(&prq_odd) == DS_OK && prq_init_queue(&prq_even) == DS_OK)
	{
		prq_get_length(prq, &len);
		for (j = 0; j < len; j++)
		{
			prq_peek_front(prq, &data);
			if (data % 2 == 0)
			{
				prq_dequeue_node(prq, &node);
				prq_enqueue_node(prq_even, node);
			}
			else
			{
				prq_dequeue_node(prq, &node);
				prq_enqueue_node(prq_odd, node);
			}
		}
	}

	prq_display(prq);
	prq_display(prq_odd);
	prq_display(prq_even);

	prq_delete_queue(&prq);
	prq_delete_queue(&prq_odd);
	prq_delete_queue(&prq_even);

	printf("\n");
	return 0;
}