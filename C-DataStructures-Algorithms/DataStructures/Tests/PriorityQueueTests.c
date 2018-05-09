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

	Status st = DS_OK;

	size_t i, len = 0;

	pqe_init_queue(&pqe);

	if (pqe_is_empty(pqe))
		printf("Priority Queue is Empty");

	pqe_enqueue(pqe, 0, 20);
	pqe_enqueue(pqe, 1, 10);
	pqe_enqueue(pqe, 2, 12);
	pqe_enqueue(pqe, 3, 11);
	pqe_enqueue(pqe, 4, 11);
	pqe_enqueue(pqe, 5, 11);
	pqe_enqueue(pqe, 6, 13);
	pqe_enqueue(pqe, 7, 21);
	pqe_enqueue(pqe, 8, 20);

	pqe_display(pqe);
	// front <- 7 <- 0 <- 8 <- 6 <- 2 <- 3 <- 4 <- 5 <- 1 <- rear

	pqe_erase_queue(&pqe);

	pqe_enqueue_node(pqe, pqe_get_node(0, 20));
	pqe_enqueue_node(pqe, pqe_get_node(1, 10));
	pqe_enqueue_node(pqe, pqe_get_node(2, 12));
	pqe_enqueue_node(pqe, pqe_get_node(3, 11));
	pqe_enqueue_node(pqe, pqe_get_node(4, 11));
	pqe_enqueue_node(pqe, pqe_get_node(5, 11));
	pqe_enqueue_node(pqe, pqe_get_node(6, 13));
	pqe_enqueue_node(pqe, pqe_get_node(7, 21));
	pqe_enqueue_node(pqe, pqe_get_node(8, 20));

	pqe_display(pqe);
	// front <- 7 <- 0 <- 8 <- 6 <- 2 <- 3 <- 4 <- 5 <- 1 <- rear

	int highest, lowest;

	pqe_priority_highest(pqe, &highest);
	pqe_priority_lowest(pqe, &lowest);

	printf("\nHighest priority : %d\nLowest Priority : %d\n", highest, lowest);

	pqe_get_length(pqe, &len);

	for (i = 0; i < len; i++) {
		pqe_dequeue(pqe);
	}

	pqe_display(pqe);

	que_erase_queue(&pqe);

	for (i = 0; i < 100; i++)
		pqe_enqueue(pqe, i, i % 5);

	pqe_display(pqe);

	PriorityQueue *pqe_even = NULL, *pqe_odd = NULL;
	PriorityQueueNode *node;
	int data;
	size_t j;
	if (pqe_init_queue(&pqe_odd) == DS_OK && pqe_init_queue(&pqe_even) == DS_OK) {
		pqe_get_length(pqe, &len);
		for (j = 0; j < len; j++) {
			pqe_peek_front(pqe, &data);
			if (data % 2 == 0) {
				que_dequeue_node(pqe, &node);
				que_enqueue_node(pqe_even, node);
			}
			else {
				que_dequeue_node(pqe, &node);
				que_enqueue_node(pqe_odd, node);
			}
		}
	}

	pqe_display(pqe);
	pqe_display(pqe_odd);
	pqe_display(pqe_even);

	pqe_delete_queue(&pqe);
	pqe_delete_queue(&pqe_odd);
	pqe_delete_queue(&pqe_even);

	printf("\n");
	return 0;
}