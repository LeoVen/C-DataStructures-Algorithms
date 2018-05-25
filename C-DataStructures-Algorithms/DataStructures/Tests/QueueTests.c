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
	for (i = 0; i < 6; i++) {
		que_enqueue(que, i);
		que_display(que);
	}

	int result;
	que_peek_front(que, &result);
	printf("\nfront: %d", result);

	que_peek_rear(que, &result);
	printf("\nrear: %d\n", result);

	for (i = 0; i < 6; i++) {
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
	if (que_init_queue(&que_odd) == DS_OK && que_init_queue(&que_even) == DS_OK) {
		que_get_length(que, &len);
		for (j = 0; j < len; j++) {
			que_peek_front(que, &data);
			if (data % 2 == 0) {
				que_dequeue_node(que, &node);
				que_enqueue_node(que_even, node);
			}
			else {
				que_dequeue_node(que, &node);
				que_enqueue_node(que_odd, node);
			}
		}
	}

	que_display(que);
	que_display(que_odd);
	que_display(que_even);

	que_delete_queue(&que);
	que_delete_queue(&que_odd);
	que_delete_queue(&que_even);

	printf("\n");
	return 0;
}