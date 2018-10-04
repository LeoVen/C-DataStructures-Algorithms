/**
* @file QueueArrayTests.c
*
* @author Leonardo Vencovsky (https://github.com/LeoVen)
* @date 04/08/2018
*
* @brief Test Cases for @c QueueArray implementations in C
*
*/

#include "QueueArray.h"

int QUA_TIME_TESTS(void);
int QUA_REALLOC_TEST(void);

int QueueArrayTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Queue Array            |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	QUA_TIME_TESTS();
	QUA_REALLOC_TEST();

	QueueArray *q;

	qua_init(&q);

	int i, j;

	for (i = 0; i < 100; i++)
		qua_enqueue(q, i);

	qua_display(q);

	while (!qua_is_empty(q))
	{
		qua_pop(q);

		if (q->length % 20 == 0)
			qua_display(q);
	}

	qua_display(q);

	qua_delete(&q);

	qua_init(&q);

	for (i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			qua_enqueue(q, i);
		else if (i % 3 == 0)
			qua_dequeue(q, &j);

		if (i % 20 == 0)
		{
			qua_display(q);

			printf("\nLength   : %zu", q->length);
			printf("\nCapacity : %zu", q->capacity);
			printf("\nFront    : %zu", q->front);
			printf("\nRear     : %zu", q->rear);

		}
	}

	QueueArray *queue;

	qua_copy(q, &queue);
	
	printf("\n\n\nOriginal\n--------\n");
	qua_display(q);
	printf("\nLength   : %zu", q->length);
	printf("\nCapacity : %zu", q->capacity);
	printf("\nFront    : %zu", q->front);
	printf("\nRear     : %zu", q->rear);
	printf("\nCopy\n----\n");
	qua_display(queue);
	printf("\nLength   : %zu", queue->length);
	printf("\nCapacity : %zu", queue->capacity);
	printf("\nFront    : %zu", queue->front);
	printf("\nRear     : %zu", queue->rear);

	qua_delete(&q);
	qua_delete(&queue);

	printf("\n");
	return 0;
}

int QUA_TIME_TESTS(void)
{
	int i;
	QueueArray *q;

	qua_init(&q);

	// TIMING INSERTION AND REMOVAL
	clock_t begin;
	clock_t end;

	size_t s, Q_SIZE = 100000;

	size_t partition = Q_SIZE / 1000; // FOR EACH ONE THOUSAND REMOVALS

	double *times = malloc(sizeof(double) * partition);

	if (!times)
		return -1;

	// INSERTION IS CALCULATED ONCE
	begin = clock();

	for (i = 0; i < Q_SIZE; i++)
		qua_enqueue(q, i);

	end = clock();

	double insert = (double)(end - begin) / CLOCKS_PER_SEC;

	s = 0;

	while (!qua_is_empty(q))
	{
		i = -1;

		begin = clock();
		while (++i < 1000)
		{
			qua_pop(q);
		}
		end = clock();

		times[s] = (double)(end - begin) / CLOCKS_PER_SEC;

		s++;
	}

	qua_delete(&q);

	printf("\n\n\nInsertion Time: %lf\n\n\n", insert);

	for (s = 0; s < partition; s++)
		printf(" %lf", times[s]);

	free(times);

	return 0;
}

int QUA_REALLOC_TEST(void)
{
	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ------ QUA_REALLOC_TEST ------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	QueueArray *queue;

	qua_init(&queue);

	queue->growth_rate = 10000000000; // oops! wrong!

	// Testing realloc
	int i;
	for (i = 0; i < 10; i++)
		qua_enqueue(queue, i);

	qua_display(queue);

	qua_delete(&queue);

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- End tests ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	return 0;
}