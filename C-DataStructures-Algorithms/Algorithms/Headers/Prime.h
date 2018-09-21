/**
 * @file Prime.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 13/08/2018
 *
 * @brief Header file for Prime numbers related functions
 *
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

	// A prime struct that helps finding prime sequences
	typedef struct Prime
	{
		size_t prime;
		size_t nth;
		size_t(*next)(struct Prime*);
		size_t(*prev)(struct Prime*);
		size_t(*nth_prime)(size_t);
		size_t(*lt)(size_t);
		size_t(*gt)(size_t);
		bool(*is_prime)(size_t);
		bool(*has_prev)(struct Prime*);
	} Prime;

	Status prm_init(Prime **prime);

	size_t prm_next(Prime *prime);
	size_t prm_prev(Prime *prime);

	size_t prm_nth_prime(size_t nth);

	size_t prm_lt(size_t n);
	size_t prm_gt(size_t n);

	//Status prm_factors(size_t n, size_t **result);

	bool prm_is_prime(size_t number);

	bool prm_has_prev(Prime *prime);

	Status prm_delete(Prime **prime);
	Status prm_erase(Prime **prime);

#ifdef __cplusplus
}
#endif