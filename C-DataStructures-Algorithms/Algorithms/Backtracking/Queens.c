/**
 * @file Queens.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/09/2018
 *
 * @brief Source file for the Queens Puzzle implementations using backtracking
 * in C
 *
 * @see https://oeis.org/A000170
 */

#include "Backtracking.h"

void queens_p(int current, int total, int *queens);
void queens_r(int current, int total, int *queens, int *result);

Status queens(int board_size)
{
	if (board_size <= 0)
		return DS_ERR_INVALID_ARGUMENT;

	int *queens = malloc(sizeof(int) * board_size);

	if (!queens)
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < board_size; i++)
		queens[i] = 0;

	queens_p(0, board_size, queens);

	free(queens);

	return DS_OK;
}

Status queens_solutions(int board_size, int *result)
{
	*result = 0;

	if (board_size <= 0)
		return DS_ERR_INVALID_ARGUMENT;

	int *queens = malloc(sizeof(int) * board_size);

	if (!queens)
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < board_size; i++)
		queens[i] = 0;

	queens_r(0, board_size, queens, result);

	free(queens);

	return DS_OK;
}

void queens_p(int current, int total, int *queens)
{
	if (current == total)
	{
		printf("\n");
		queens_print(queens, total);
		printf("\n");
	}
	else
	{
		int i;
		for (i = 0; i < total; i++)
		{
			queens[current] = i;

			if (queens_valid(current, queens))
				queens_p(current + 1, total, queens);
		}
	}
}

void queens_r(int current, int total, int *queens, int *result)
{
	if (current == total)
		(*result)++;
	else
	{
		int i;
		for (i = 0; i < total; i++)
		{
			queens[current] = i;

			if (queens_valid(current, queens))
				queens_r(current + 1, total, queens, result);
		}
	}
}

bool queens_valid(int t, int *row)
{
	int i;
	for (i = 0; i < t; i++)
	{
		if ((row[i] == row[t]) || (t - i == abs(row[i] - row[t])))
			return false;
	}

	return true;
}

void queens_print(int *row, int board_size)
{
	int i, j;
	for (i = 0; i < board_size; i++)
	{
		for (j = 0; j < board_size; j++)
		{
			if (row[j] == i)
				printf("  Q  ");
			else
				printf("  .  ");
		}

		printf("\n");
	}
}
