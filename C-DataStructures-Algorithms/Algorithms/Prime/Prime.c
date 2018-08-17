/**
 * @file Prime.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 13/08/2018
 *
 * @brief Source file for Prime numbers related functions
 *
 */

#include "Prime.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status prm_init(Prime **prime)
{
	(*prime) = malloc(sizeof(Prime));

	if (!(*prime))
		return DS_ERR_ALLOC;

	(*prime)->prime = 2;
	(*prime)->nth = 1;

	(*prime)->next = prm_next;
	(*prime)->prev = prm_prev;

	(*prime)->nth_prime = prm_nth_prime;
	(*prime)->lt = prm_lt;
	(*prime)->gt = prm_gt;

	(*prime)->is_prime = prm_is_prime;
	(*prime)->has_prev = prm_has_prev;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                         Prime Functions                                         |
// +-------------------------------------------------------------------------------------------------+

// Goes to the next prime and returns it
size_t prm_next(Prime *prime)
{
	if (prime == NULL)
		return 0;

	size_t i, p = 0, fix = (prime->nth == 1) ? 1 : 2;

	for (i = prime->prime + fix; ; i += 2)
		if (prime->is_prime(i))
		{
			prime->prime = i;

			(prime->nth)++;

			p = i;

			break;
		}

	return p;
}

// Goes to a previous prime and returns it
size_t prm_prev(Prime *prime)
{
	if (prime == NULL)
		return 0;

	if (!prm_has_prev(prime))
		return 0;

	size_t i, p = 0, fix = (prime->nth == 2) ? 1 : 2;

	for (i = prime->prime - fix; i > 1; i -= 2)
		if (prm_is_prime(i))
		{
			prime->prime = i;

			(prime->nth)--;

			p = i;

			break;
		}

	return p;
}

// Returns nth prime
size_t prm_nth_prime(size_t nth)
{
	if (nth == 0)
		return 0;

	if (nth == 1)
		return 2;

	size_t i, p = 0, total = 1;

	for (i = 3; ; i += 2)
		if (prm_is_prime(i))
		{
			total++;

			if (total == nth)
			{
				p = i;

				break;
			}
		}

	return p;
}

// The highest prime number less than N
size_t prm_lt(size_t n)
{
	if (n < 3)
		return 0;

	if (n == 3)
		return 2;

	size_t i, fix = (n % 2 == 0) ? 1 : 2;
	for (i = n - fix; i > 1; i -= 2)
		if (prm_is_prime(i))
			return i;

	return 0;
}

// The lowest prime number greater than N
size_t prm_gt(size_t n)
{
	if (n < 3)
		return 3;

	size_t i, fix = (n % 2 == 0) ? 1 : 2;
	for (i = n + fix; ; i += 2)
		if (prm_is_prime(i))
			return i;
}

//Status prm_factors(size_t n, size_t **result)

// Checks if a given number is prime
bool prm_is_prime(size_t n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	size_t i;
	for (i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

// Returns true or false if there is a previous prime number
bool prm_has_prev(Prime *prime)
{
	return prime->nth > 1;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status prm_delete(Prime **prime)
{
	if ((*prime) == NULL)
		return DS_ERR_NULL_POINTER;

	free(*prime);

	*prime = NULL;

	return DS_OK;
}

Status prm_erase(Prime **prime)
{
	if ((*prime) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = prm_delete(prime);

	if (st != DS_OK)
		return st;

	st = prm_init(prime);

	if (st != DS_OK)
		return st;

	return DS_OK;
}
