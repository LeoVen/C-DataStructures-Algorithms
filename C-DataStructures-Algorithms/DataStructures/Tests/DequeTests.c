/**
 * @file DequeTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 09/05/2018
 *
 * @brief Test Cases for @c Deque implementations in C
 *
 */

#include "..\Headers\Deque.h"

int DequeTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C Deque               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Deque *deq;

	deq_init_queue(&deq);

	int i;
	for (i = 0; i < 6; i++) {
		deq_enqueue_front(deq, i);
		deq_display(deq);
	}

	deq_erase_queue(&deq);

	for (i = 0; i < 6; i++) {
		deq_enqueue_rear(deq, i);
		deq_display(deq);
	}

	for (i = 0; i < 6; i++) {
		deq_enqueue_front(deq, i);
		deq_display(deq);
	}

	deq_display_raw(deq);

	int result;
	deq_peek_front(deq, &result);
	printf("\nfront: %d", result);

	deq_peek_rear(deq, &result);
	printf("\nrear: %d\n", result);

	for (i = 0; i < 6; i++) {
		deq_dequeue_rear(deq);
		deq_display(deq);
	}

	for (i = 0; i < 10; i++)
		deq_enqueue_rear(deq, i);
	
	size_t size;

	deq_get_length(deq, &size);

	deq_display(deq);

	printf("\nQueue length: %zu", size);

	deq_get_length(deq, &size);

	size_t j;
	for (j = 0; j < size; j++) {
		deq_dequeue_front(deq);
		deq_display_raw(deq);
	}

	for (i = 0; i < 100; i++)
		deq_enqueue_rear(deq, i);

	Deque *deq_even = NULL, *deq_odd = NULL;
	DequeNode *node;
	int data;
	size_t len;
	if (deq_init_queue(&deq_odd) == DS_OK && deq_init_queue(&deq_even) == DS_OK) {
		deq_get_length(deq, &len);
		for (j = 0; j < len; j++) {
			deq_peek_front(deq, &data);
			if (data % 2 == 0) {
				deq_dequeue_front_node(deq, &node);
				deq_enqueue_rear_node(deq_even, node);
			}
			else {
				deq_dequeue_front_node(deq, &node);
				deq_enqueue_rear_node(deq_odd, node);
			}
		}
	}

	deq_display(deq);
	deq_display(deq_odd);
	deq_display(deq_even);

	deq_delete_queue(&deq);
	deq_delete_queue(&deq_odd);
	deq_delete_queue(&deq_even);

	printf("\n");
	return 0;
}