/**
 * @file Backtracking.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/09/2018
 *
 * @brief Header File for Backtracking Algorithms
 *
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

	Status queens(int board_size);
	Status queens_solutions(int board_size, int *result);
	void queens_print(int *row, int board_size);
	bool queens_valid(int t, int *row);

#ifdef __cplusplus
}
#endif