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

int QueueArrayTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Queue Array            |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	QueueArray *q;

	qua_init(&q);
	
	int i, val;
	size_t s;

	for (i = 0; i < 100; i++)
		qua_enqueue(q, i);

	qua_display(q);

	while (!qua_is_empty(q))
	{
		qua_pop(q);

		if (q->length % 10 == 0)
			qua_display(q);
	}

	qua_display(q);

	qua_erase(&q);


	// TIMING INSERTION AND REMOVAL
	clock_t begin;
	clock_t end;

	size_t Q_SIZE = 100000;

	size_t partition = Q_SIZE / 1000; // FOR EACH ONE THOUSAND REMOVALS

	double *times = malloc(sizeof(double) * partition);

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

	printf("\n");
	return 0;
}