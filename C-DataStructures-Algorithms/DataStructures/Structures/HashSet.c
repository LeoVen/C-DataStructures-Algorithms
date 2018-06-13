/**
 * @file HashSet.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 10/06/2018
 *
 * @brief Source file for @c HashSet implementations in C
 *
 */

#include "HashSet.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status set_init_table(HashSet **set, size_t max_size, hash_function_t hash_function, rehash_function_t rehash_function)
{
	if (max_size == 0)
		return DS_ERR_INVALID_SIZE;

	if (hash_function == NULL)
		return DS_ERR_INVALID_ARGUMENT;

	*set = malloc(sizeof(HashSet));

	if (!(*set))
		return DS_ERR_ALLOC;

	(*set)->buckets = malloc(sizeof(HashSetEntry *) * max_size);

	if (!((*set)->buckets))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < max_size; i++) {

		((*set)->buckets)[i] = NULL;
	}

	(*set)->size = 0;
	(*set)->max_size = max_size;

	(*set)->hash_function = hash_function;
	(*set)->rehash_function = rehash_function;

	return DS_OK;
}

Status set_init_entry(HashSetEntry **entry, char *value)
{
	*entry = malloc(sizeof(HashSetEntry));

	if (!(*entry))
		return DS_ERR_ALLOC;

	(*entry)->value = _strdup(value);
	(*entry)->hash = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Status set_make_entry(HashSetEntry **entry, char *value, size_t hash)
{
	*entry = malloc(sizeof(HashSetEntry));

	if (!(*entry))
		return DS_ERR_ALLOC;

	(*entry)->value = _strdup(value);
	(*entry)->hash = hash;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status set_insert(HashSet *set, char *value)
{
	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	if (set_is_full(set))
		return DS_ERR_FULL;

	size_t hash;

	Status st = set->hash_function(value, &hash);

	if (st != DS_OK)
		return st;

	size_t pos = hash % set->max_size;

	if ((set->buckets)[pos] == NULL) {

		st = set_make_entry(&((set->buckets)[pos]), value, hash);

		if (st != DS_OK)
			return st;

		(set->size)++;
	}
	else {

		if (((set->buckets)[pos])->hash == hash)
			return DS_OK;

		bool found = false;

		size_t i, rehash = hash;
		for (i = 1; i <= 10; i++) {
			
			st = set->rehash_function(&rehash);

			if (st != DS_OK)
				return st;

			pos = (hash + i * rehash) % set->max_size;

			if ((set->buckets)[pos] == NULL) {

				st = set_make_entry(&((set->buckets)[pos]), value, hash);

				if (st != DS_OK)
					return st;

				(set->size)++;

				found = true;

				break;
			}
			else if (((set->buckets)[pos])->hash == hash)
				return DS_OK;

		}

		if (!found) {

			while (!found)
			{
				pos++;

				if ((set->buckets)[pos % set->max_size] == NULL) {

					st = set_make_entry(&((set->buckets)[pos % set->max_size]), value, hash);

					if (st != DS_OK)
						return st;

					(set->size)++;

					found = true;
				}
				else if (((set->buckets)[pos % set->max_size])->hash == hash)
					return DS_OK;

			}
		}

	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status set_remove(HashSet *set, char *value)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status set_display_entry(HashSetEntry *entry)
{
	if (entry == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n| %21zu | %52s |", entry->hash, entry->value);

	return DS_OK;
}

Status set_display_entry_raw(HashSetEntry *entry)
{
	if (entry == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n %21zu %52s ", entry->hash, entry->value);

	return DS_OK;
}

Status set_display_table(HashSet *set)
{
	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n+------------------------------------------------------------------------------+");
	printf("\n|                                 Hash Set                                     |");
	printf("\n+-----------------------+------------------------------------------------------+");
	printf("\n|         HASH          |                         VALUE                        |");

	Status st;

	size_t i;
	for (i = 0; i < set->max_size; i++) {

		printf("\n+-----------------------+------------------------------------------------------+");

		if ((set->buckets)[i] == NULL)
			printf("\n|         NULL          |                           NULL                       |");
		else {

			st = set_display_entry((set->buckets)[i]);

			if (st != DS_OK)
				return st;
		}
	}

	printf("\n+-----------------------+------------------------------------------------------+");

	printf("\n");

	return DS_OK;
}

Status set_display_table_raw(HashSet *set)
{
	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	Status st;

	size_t i;
	for (i = 0; i < set->max_size; i++) {

		if ((set->buckets)[i] == NULL)
			printf("\n");
		else {

			st = set_display_entry_raw((set->buckets)[i]);

			if (st != DS_OK)
				return st;
		}
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status set_delete_table(HashSet **set)
{
	if ((*set) == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < (*set)->max_size; i++) {

		if (((*set)->buckets)[i] != NULL)
			free((((*set)->buckets)[i])->value);

		free(((*set)->buckets)[i]);
	}

	free((*set)->buckets);
	free(*set);

	*set = NULL;

	return DS_OK;
}

Status set_erase_table(HashSet **set)
{
	if ((*set) == NULL)
		return DS_ERR_NULL_POINTER;

	size_t size = (*set)->max_size;
	Status(*hash_function) (char *, size_t *) = (*set)->hash_function;
	Status(*rehash_function) (size_t*) = (*set)->rehash_function;

	Status st = set_delete_table(set);

	if (st != DS_OK)
		return st;

	st = set_init_table(set, size, hash_function, rehash_function);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

bool set_is_full(HashSet *set)
{
	return (set->max_size == set->size);
}

bool set_is_empty(HashSet *set)
{
	return (set->size == 0);
}

Status set_contains(HashSet *set, char *value, bool *result)
{
	*result = false;

	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	if (set_is_empty(set))
		return DS_OK;

	size_t hash;

	Status st = set->hash_function(value, &hash);

	if (st != DS_OK)
		return st;

	size_t pos = hash % set->max_size;

	if ((set->buckets)[pos] != NULL) {

		if (((set->buckets)[pos])->hash == hash)
			*result = true;
		else {

			bool found = false;

			size_t i, rehash = hash;

			for (i = 0; i < 10; i++) {

				st = set->rehash_function(&rehash);

				if (st != DS_OK)
					return st;

				pos = (hash + i * rehash) % set->max_size;

				if ((set->buckets)[pos] != NULL) {

					if (((set->buckets)[pos])->hash == hash) {

						*result = true;

						found = true;

						break;
					}
				}
			}

			if (!found) {

				for (i = 0; i < set->max_size; i++, pos++) {

					if ((set->buckets)[pos % set->max_size] != NULL) {

						if (((set->buckets)[pos % set->max_size])->hash == hash) {

							*result = true;

							found = true;

							break;
						}
					}
				}

			}
		}
	}
	else
		*result = false;

	return DS_OK;
}

bool set_exists(HashSet *set, char *value)
{
	if (set == NULL)
		return false;

	if (set_is_empty(set))
		return false;

	size_t hash;

	Status st = set->hash_function(value, &hash);

	if (st != DS_OK)
		return st;

	size_t pos = hash % set->max_size;

	if ((set->buckets)[pos] != NULL) {

		if (((set->buckets)[pos])->hash == hash)
			return true;
		else {

			size_t i, rehash = hash;

			for (i = 0; i < 10; i++) {

				st = set->rehash_function(&rehash);

				if (st != DS_OK)
					return st;

				pos = (hash + i * rehash) % set->max_size;

				if ((set->buckets)[pos] != NULL) {

					if (((set->buckets)[pos])->hash == hash) {

						return true;
					}
				}
			}

			for (i = 0; i < set->max_size; i++, pos++) {

				if ((set->buckets)[pos % set->max_size] != NULL) {

					if (((set->buckets)[pos % set->max_size])->hash == hash) {

						return true;
					}
				}
			}

			
		}
	}
	else
		return false;

	return false;
}

Status set_count_elements(HashSet *set, size_t *result)
{
	*result = 0;

	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < set->max_size; i++) {

		if ((set->buckets)[i] != NULL)
			(*result)++;
	}

	return DS_OK;
}

Status set_count_empty(HashSet *set, size_t *result)
{
	*result = 0;

	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < set->max_size; i++) {

		if ((set->buckets)[i] == NULL)
			(*result)++;
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Set                                                 |
// +-------------------------------------------------------------------------------------------------+

//Status set_union(HashSet *set1, HashSet *set2, HashSet **result)
//Status set_intersection(HashSet *set1, HashSet *set2, HashSet **result)
//Status set_difference(HashSet *set1, HashSet *set2, HashSet **result)
//Status set_complement(HashSet *set1, HashSet *set2, HashSet **result)
//Status set_sym_diff(HashSet *set1, HashSet *set2, HashSet **result)

// +-------------------------------------------------------------------------------------------------+
// |                                             Hash                                                |
// +-------------------------------------------------------------------------------------------------+

Status set_hash_string_djb2(char *key, size_t *hash)
{
	*hash = 5381;

	int c;

	while (c = *key++)
		(*hash) = (((*hash) << 5) + (*hash)) + c;

	return DS_OK;
}

Status set_hash_string_sdbm(char *key, size_t *hash)
{
	*hash = 0;

	int c;

	while (c = *key++)
		(*hash) = c + (((*hash) << 6) + ((*hash) << 16)) - (*hash);

	return DS_OK;
}

Status set_hash_string_fnv(char *key, size_t *hash)
{
	*hash = 2166136261;

	int c;

	while (c = *key++)
		*hash = ((*hash) * 16777619) ^ key[c];

	return DS_OK;
}

Status set_rehash_rj(size_t *hash)
{
	*hash = ((*hash) + 0x7ed55d16) + ((*hash) << 12);
	*hash = ((*hash) ^ 0xc761c23c) ^ ((*hash) >> 19);
	*hash = ((*hash) + 0x165667b1) + ((*hash) << 5);
	*hash = ((*hash) + 0xd3a2646c) ^ ((*hash) << 9);
	*hash = ((*hash) + 0xfd7046c5) + ((*hash) << 3);
	*hash = ((*hash) ^ 0xb55a4f09) ^ ((*hash) >> 16);

	return DS_OK;
}

Status set_rehash_prime(size_t *hash)
{
	size_t prime = 7;

	*hash = prime - ((*hash) % prime);

	return DS_OK;
}
