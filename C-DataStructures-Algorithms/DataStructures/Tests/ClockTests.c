/**
 * @file ClockTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 15/08/2018
 *
 * @brief Test Cases for @c Clock implementations in C
 *
 */

#include <Windows.h>
#include "Clock.h"

int ClockTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C Clock               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Clock *c;

	clk_init(&c);

	c->start(c);

	Sleep(50);

	c->stop(c);

	printf("\n%lf", c->time);

	c->start(c);

	Sleep(100);

	c->stop(c);

	printf("\n%lf", c->time);

	c->reset(c);

	c->start(c);

	size_t i;
	for (i = 1; i <= 10; i++)
	{
		Sleep(100 * i);
		c->lap(c);
	}

	c->stop(c);

	clk_display(c);

	printf("\nTotal time: %lf\n\n", c->time);

	c->reset(c);

	for (i = 0; i < 10; i++)
	{
		Sleep(rand() % 500);
		c->lap(c);
	}

	// Should be empty because lap() will fail every time because start()
	// was not called after reset()
	clk_display(c);

	printf("\nTotal time: %lf\n\n", c->time);

	// Now it should work
	c->start(c);

	for (i = 0; i < 10; i++)
	{
		Sleep(rand() % 500);
		c->lap(c);
	}

	clk_display(c); // Won't work because clock is still running

	c->stop(c);

	clk_display(c);

	printf("\nTotal time: %lf", c->time);

	clk_delete(&c);

	printf("\n");
	return 0;
}