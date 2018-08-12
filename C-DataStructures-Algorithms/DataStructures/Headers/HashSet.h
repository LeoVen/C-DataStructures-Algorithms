/**
 * @file HashSet.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 10/06/2018
 *
 * @brief Header file for @c HashSet implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

#ifndef HASH_FUNCTION_TYPE
#define HASH_FUNCTION_TYPE

	typedef Status (*hash_function_t)(char *, size_t *);

#endif

#ifndef REHASH_FUNCTION_TYPE
#define REHASH_FUNCTION_TYPE

	typedef Status (*rehash_function_t)(size_t *);

#endif

	typedef struct HashSetEntry
	{
		char *value;
		size_t hash;
	} HashSetEntry;

	typedef struct HashSet
	{
		struct HashSetEntry **hash_table;
		size_t size;
		size_t max_size;
		hash_function_t hash_function;
		rehash_function_t rehash_function;
	} HashSet;

	Status set_init_set(HashSet **set, size_t max_size, hash_function_t hash_function, rehash_function_t rehash_function);

	Status set_init_entry(HashSetEntry **entry, char *value);

	Status set_make_entry(HashSetEntry **entry, char *key, size_t hash);

	Status set_insert(HashSet *set, char *value);

	Status set_remove(HashSet *set, char *value);

	Status set_display_entry(HashSetEntry *entry);
	Status set_display_entry_raw(HashSetEntry *entry);
	Status set_display_set(HashSet *set);
	Status set_display_set_raw(HashSet *set);
	Status set_display_elements(HashSet *set);

	Status set_delete_set(HashSet **set);
	Status set_erase_set(HashSet **set);

	bool set_is_full(HashSet *set);
	bool set_is_empty(HashSet *set);

	Status set_contains(HashSet *set, char *value, bool *result);
	bool set_exists(HashSet *set, char *value);

	Status set_count_elements(HashSet *set, size_t *result);
	Status set_count_empty(HashSet *set, size_t *result);

	Status set_union(HashSet *set1, HashSet *set2, HashSet *result);
	Status set_intersection(HashSet *set1, HashSet *set2, HashSet *result);
	Status set_difference(HashSet *set1, HashSet *set2, HashSet *result);
	Status set_complement(HashSet *set1, HashSet *set2, HashSet *result);
	Status set_sym_diff(HashSet *set1, HashSet *set2, HashSet *result);

	Status set_hash_djb2(char *key, size_t *hash);
	Status set_hash_sdbm(char *key, size_t *hash);
	Status set_hash_prime(char *key, size_t *hash);

	Status set_rehash_rj(size_t *hash);
	Status set_rehash_prime(size_t *hash);

#ifdef __cplusplus
}
#endif