/**
 * @file PrimeTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 13/08/2018
 *
 * @brief Test Cases for Prime Algorithms
 *
 */

#include "Prime.h"

int PrimeTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Prime Tests            |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Prime *p;

	prm_init(&p);

	size_t i;

	while (p->nth < 1000)
	{
		printf("%zu ", p->prime);
		p->next(p);
	}

	printf("%zu ", p->prime);

	printf("\nNth: %zu", p->nth);

	printf("\n\n");

	while (p->has_prev(p))
	{
		printf("%zu ", p->prime);
		p->prev(p);
	}

	printf("%zu ", p->prime);

	printf("\nNth: %zu", p->nth);

	printf("\n\n1000th prime: %zu", p->nth_prime(1000));

	printf("\n");

	for (i = 3; i < 25; i++)
		printf("\nThe closest prime lower than %zu is %zu", i, p->lt(i));

	printf("\n");

	for (i = 2; i < 25; i++)
		printf("\nThe closest prime greater than %zu is %zu", i, p->gt(i));

	prm_delete(&p);

	printf("\n");
	return 0;
}