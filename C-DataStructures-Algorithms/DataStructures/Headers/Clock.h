/**
* @file Clock.h
*
* @author Leonardo Vencovsky (https://github.com/LeoVen)
* @date 15/08/2018
*
* @brief Header file for @c Clock implementations in C
*
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

#ifndef CLOCK_SPEC
#define CLOCK_SPEC

#define CLOCK_BUFFER_SIZE 50
#define CLOCK_RUNNING 1
#define CLOCK_STOPPED 0

#endif

	/**
	 * @brief @c Clock is a structure that encapsulates a timer
	 *
	 */
	typedef struct Clock
	{
		int state;                          /*!< Clock state */
		double time;                        /*!< Last calculated time */
		double *buffer;                     /*!< Buffer that stores the lap times */
		size_t buff_size;                   /*!< Buffer size */
		clock_t timer;                      /*!< Current running time */
		clock_t lap_timer;                  /*!< Current lap running time */
		Status(*start)(struct Clock*);      /*!< Function that starts the clock */
		Status(*stop)(struct Clock*);       /*!< Function that stops the clock */
		Status(*lap)(struct Clock*);        /*!< Function that stops and starts the clock again storing the value */
		Status(*reset)(struct Clock*);      /*!< Function that resets the timer and laps */
	} Clock;

	Status clk_init(Clock **clk);

	Status clk_start(Clock *clk);
	Status clk_stop(Clock *clk);
	Status clk_lap(Clock *clk);
	Status clk_reset(Clock *clk);

	Status clk_display(Clock *clk);

	Status clk_delete(Clock **clk);
	Status clk_erase(Clock **clk);

	bool clk_is_running(Clock *clk);
	bool clk_is_stopped(Clock *clk);

#ifdef __cplusplus
}
#endif