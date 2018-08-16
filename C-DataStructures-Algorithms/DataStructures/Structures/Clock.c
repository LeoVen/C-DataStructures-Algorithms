/**
 * @file Clock.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 15/08/2018
 *
 * @brief Source file for @c Clock implementations in C
 *
 */

#include "Clock.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status clk_init(Clock **clk)
{
	(*clk) = malloc(sizeof(Clock));

	if (!(*clk))
		return DS_ERR_ALLOC;

	(*clk)->buffer = malloc(sizeof(double) * _CLOCK_BUFFER_SIZE);

	if (!((*clk)->buffer))
		return DS_ERR_ALLOC;

	(*clk)->buff_size = 0;

	(*clk)->time = 0.0;
	(*clk)->state = _CLOCK_STOPPED;

	(*clk)->start = clk_start;
	(*clk)->stop = clk_stop;
	(*clk)->reset = clk_reset;
	(*clk)->lap = clk_lap;

	(*clk)->timer = 0;
	(*clk)->lap_timer = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Clock                                               |
// +-------------------------------------------------------------------------------------------------+

Status clk_start(Clock *clk)
{
	if (clk == NULL)
		return DS_ERR_NULL_POINTER;

	if (clk_is_running(clk))
		return DS_ERR_INVALID_OPERATION;

	clk->timer = clock();
	clk->lap_timer = clock();

	clk->state = _CLOCK_RUNNING;

	return DS_OK;
}

Status clk_stop(Clock *clk)
{
	if (clk == NULL)
		return DS_ERR_NULL_POINTER;

	if (clk_is_stopped(clk))
		return DS_ERR_INVALID_OPERATION;

	clock_t t = clock();

	clk->time += (double)(t - clk->timer) / CLOCKS_PER_SEC;

	clk->state = _CLOCK_STOPPED;

	return DS_OK;
}

Status clk_lap(Clock *clk)
{
	if (clk == NULL)
		return DS_ERR_NULL_POINTER;

	if (clk_is_stopped(clk))
		return DS_ERR_INVALID_OPERATION;

	if (clk->buff_size == _CLOCK_BUFFER_SIZE - 1)
		return DS_ERR_FULL;

	clock_t t = clock();

	clk->buffer[clk->buff_size] = (double)(t - clk->lap_timer) / CLOCKS_PER_SEC;

	(clk->buff_size)++;

	clk->lap_timer = t;

	return DS_OK;
}

Status clk_reset(Clock *clk)
{
	if (clk == NULL)
		return DS_ERR_NULL_POINTER;

	if (clk_is_running(clk))
		return DS_ERR_INVALID_OPERATION;

	clk->time = 0.0;
	
	clk->buff_size = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

// Displays stored times
Status clk_display(Clock *clk)
{
	if (clk == NULL)
		return DS_ERR_NULL_POINTER;

	if (clk_is_running(clk))
		return DS_ERR_INVALID_OPERATION;

	printf("\nClock\n");

	if (clk->buff_size == 0)
	{
		printf("[ empty ]\n");

		return DS_OK;
	}

	size_t i;
	for (i = 0; i < clk->buff_size; i++)
		printf(" %lf", clk->buffer[i]);

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status clk_delete(Clock **clk)
{
	if ((*clk) == NULL)
		return DS_ERR_NULL_POINTER;

	free((*clk)->buffer);

	free(*clk);

	*clk = NULL;

	return DS_OK;
}

Status clk_erase(Clock **clk)
{
	if ((*clk) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = clk_delete(clk);

	if (st != DS_OK)
		return st;

	st = clk_init(clk);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

bool clk_is_running(Clock *clk)
{
	return clk->state == _CLOCK_RUNNING;
}

bool clk_is_stopped(Clock *clk)
{
	return clk->state == _CLOCK_STOPPED;
}
