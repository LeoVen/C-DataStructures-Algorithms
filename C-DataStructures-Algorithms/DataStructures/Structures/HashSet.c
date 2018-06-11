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

Status set_init_table(HashSet **set, size_t max_size, Status(*hash_function) (int, size_t *))
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

		((*set)->buckets)[i] = malloc(sizeof(HashSetEntry));

		if (!(((*set)->buckets)[i]))
			return DS_ERR_ALLOC;

		((*set)->buckets)[i] = NULL;
	}

	(*set)->size = 0;
	(*set)->max_size = max_size;

	(*set)->hash_function = hash_function;

	return DS_OK;
}

Status set_init_entry(HashSetEntry **entry, char *value)
{
	*entry = malloc(sizeof(HashSetEntry));

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

	(*entry)->value = _strdup(value);
	(*entry)->hash = hash;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

//Status set_insert(HashSet *set, char *value)

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status set_remove(HashSet *set, char *value)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

//Status set_display_entry(HashSetEntry *entry)
//Status set_display_table(HashSet *set)
//Status set_display_entry_raw(HashSetEntry *entry)
//Status set_display_table_raw(HashSet *set)

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

//Status set_delete_table(HashSet **set)
//Status set_erase_table(HashSet **set)

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

//Status set_search(HashSet *set, char *key, int *value)

//Status set_count_entries(HashSet *set, size_t *result)
//Status set_count_empty(HashSet *set, size_t *result)

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

	int c = 0;

	while (key[c]++)
		*hash = ((*hash) * 16777619) ^ key[c];
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
