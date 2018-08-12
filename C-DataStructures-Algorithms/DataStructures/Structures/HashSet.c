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

Status set_init_set(HashSet **set, size_t max_size, hash_function_t hash_function, rehash_function_t rehash_function)
{
	if (max_size == 0)
		return DS_ERR_INVALID_SIZE;

	if (hash_function == NULL)
		return DS_ERR_INVALID_ARGUMENT;

	*set = malloc(sizeof(HashSet));

	if (!(*set))
		return DS_ERR_ALLOC;

	(*set)->hash_table = malloc(sizeof(HashSetEntry *) * max_size);

	if (!((*set)->hash_table))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < max_size; i++)
	{

		((*set)->hash_table)[i] = NULL;
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

	if ((set->hash_table)[pos] == NULL)
	{

		st = set_make_entry(&((set->hash_table)[pos]), value, hash);

		if (st != DS_OK)
			return st;

		(set->size)++;
	}
	else
	{

		if (((set->hash_table)[pos])->hash == hash)
			return DS_OK;

		bool found = false;

		size_t i, rehash = hash;
		for (i = 1; i <= 10; i++)
		{

			st = set->rehash_function(&rehash);

			if (st != DS_OK)
				return st;

			pos = (hash + i * rehash) % set->max_size;

			if ((set->hash_table)[pos] == NULL)
			{

				st = set_make_entry(&((set->hash_table)[pos]), value, hash);

				if (st != DS_OK)
					return st;

				(set->size)++;

				found = true;

				break;
			}
			else if (((set->hash_table)[pos])->hash == hash)
				return DS_OK;
		}

		if (!found)
		{

			while (!found)
			{
				pos++;

				if ((set->hash_table)[pos % set->max_size] == NULL)
				{

					st = set_make_entry(&((set->hash_table)[pos % set->max_size]), value, hash);

					if (st != DS_OK)
						return st;

					(set->size)++;

					found = true;
				}
				else if (((set->hash_table)[pos % set->max_size])->hash == hash)
					return DS_OK;
			}
		}
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status set_remove(HashSet *set, char *value)
{
	if (set_is_empty(set))
		return DS_ERR_INVALID_OPERATION;

	if (!set_exists(set, value))
		return DS_ERR_NOT_FOUND;

	size_t hash;

	Status st = set->hash_function(value, &hash);

	if (st != DS_OK)
		return st;

	size_t pos = hash % set->max_size;

	if ((set->hash_table)[pos] != NULL)
	{

		if (((set->hash_table)[pos])->hash == hash)
		{

			free((set->hash_table)[pos]);
			(set->hash_table)[pos] = NULL;

			(set->size)--;
		}
		else
		{

			bool found = false;

			size_t i, rehash = hash;

			for (i = 0; i < 10; i++)
			{

				st = set->rehash_function(&rehash);

				if (st != DS_OK)
					return st;

				pos = (hash + i * rehash) % set->max_size;

				if ((set->hash_table)[pos] != NULL)
				{

					if (((set->hash_table)[pos])->hash == hash)
					{

						free((set->hash_table)[pos]);
						(set->hash_table)[pos] = NULL;

						(set->size)--;
					}
				}
			}

			if (!found)
			{

				for (i = 0; i < set->max_size; i++, pos++)
				{

					if ((set->hash_table)[pos % set->max_size] != NULL)
					{

						if (((set->hash_table)[pos % set->max_size])->hash == hash)
						{

							free((set->hash_table)[pos % set->max_size]);
							(set->hash_table)[pos % set->max_size] = NULL;

							(set->size)--;
						}
					}
				}
			}
		}
	}
	else
		return DS_ERR_NOT_FOUND;

	return DS_OK;
}

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

Status set_display_set(HashSet *set)
{
	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n+------------------------------------------------------------------------------+");
	printf("\n|                                 Hash Set                                     |");
	printf("\n+-----------------------+------------------------------------------------------+");
	printf("\n|         HASH          |                         VALUE                        |");

	Status st;

	size_t i;
	for (i = 0; i < set->max_size; i++)
	{

		printf("\n+-----------------------+------------------------------------------------------+");

		if ((set->hash_table)[i] == NULL)
			printf("\n|         NULL          |                           NULL                       |");
		else
		{

			st = set_display_entry((set->hash_table)[i]);

			if (st != DS_OK)
				return st;
		}
	}

	printf("\n+-----------------------+------------------------------------------------------+");

	printf("\n");

	return DS_OK;
}

Status set_display_set_raw(HashSet *set)
{
	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	Status st;

	size_t i;
	for (i = 0; i < set->max_size; i++)
	{

		if ((set->hash_table)[i] == NULL)
			printf("\n");
		else
		{

			st = set_display_entry_raw((set->hash_table)[i]);

			if (st != DS_OK)
				return st;
		}
	}

	printf("\n");

	return DS_OK;
}

Status set_display_elements(HashSet *set)
{
	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\nHash Set\n");

	if (set_is_empty(set))
		printf("[ empty ]\n");
	else
	{

		printf("( ");

		size_t i;
		for (i = 0; i < set->max_size; i++)
		{

			if ((set->hash_table)[i] != NULL)
				printf("< %s > ", ((set->hash_table)[i])->value);
		}

		printf(")");
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status set_delete_set(HashSet **set)
{
	if ((*set) == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < (*set)->max_size; i++)
	{

		if (((*set)->hash_table)[i] != NULL)
			free((((*set)->hash_table)[i])->value);

		free(((*set)->hash_table)[i]);
	}

	free((*set)->hash_table);
	free(*set);

	*set = NULL;

	return DS_OK;
}

Status set_erase_set(HashSet **set)
{
	if ((*set) == NULL)
		return DS_ERR_NULL_POINTER;

	size_t size = (*set)->max_size;
	Status (*hash_function)(char *, size_t *) = (*set)->hash_function;
	Status (*rehash_function)(size_t *) = (*set)->rehash_function;

	Status st = set_delete_set(set);

	if (st != DS_OK)
		return st;

	st = set_init_set(set, size, hash_function, rehash_function);

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

	if ((set->hash_table)[pos] != NULL)
	{

		if (((set->hash_table)[pos])->hash == hash)
			*result = true;
		else
		{

			bool found = false;

			size_t i, rehash = hash;

			for (i = 0; i < 10; i++)
			{

				st = set->rehash_function(&rehash);

				if (st != DS_OK)
					return st;

				pos = (hash + i * rehash) % set->max_size;

				if ((set->hash_table)[pos] != NULL)
				{

					if (((set->hash_table)[pos])->hash == hash)
					{

						*result = true;

						found = true;

						break;
					}
				}
			}

			if (!found)
			{

				for (i = 0; i < set->max_size; i++, pos++)
				{

					if ((set->hash_table)[pos % set->max_size] != NULL)
					{

						if (((set->hash_table)[pos % set->max_size])->hash == hash)
						{

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

	if ((set->hash_table)[pos] != NULL)
	{

		if (((set->hash_table)[pos])->hash == hash)
			return true;
		else
		{

			size_t i, rehash = hash;

			for (i = 0; i < 10; i++)
			{

				st = set->rehash_function(&rehash);

				if (st != DS_OK)
					return st;

				pos = (hash + i * rehash) % set->max_size;

				if ((set->hash_table)[pos] != NULL)
				{

					if (((set->hash_table)[pos])->hash == hash)
					{

						return true;
					}
				}
			}

			for (i = 0; i < set->max_size; i++, pos++)
			{

				if ((set->hash_table)[pos % set->max_size] != NULL)
				{

					if (((set->hash_table)[pos % set->max_size])->hash == hash)
					{

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
	for (i = 0; i < set->max_size; i++)
	{

		if ((set->hash_table)[i] != NULL)
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
	for (i = 0; i < set->max_size; i++)
	{

		if ((set->hash_table)[i] == NULL)
			(*result)++;
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Set                                                 |
// +-------------------------------------------------------------------------------------------------+

Status set_union(HashSet *set1, HashSet *set2, HashSet *result)
{
	if (set1 == NULL || set2 == NULL || result == NULL)
		return DS_ERR_NULL_POINTER;

	if (!set_is_empty(result))
		return DS_ERR_INVALID_ARGUMENT;

	if (set1->size + set2->size > result->max_size)
		return DS_ERR_INVALID_ARGUMENT;

	Status st;

	size_t i;
	for (i = 0; i < set1->max_size; i++)
	{

		if ((set1->hash_table)[i] != NULL)
		{

			st = set_insert(result, ((set1->hash_table)[i])->value);

			if (st != DS_OK)
				return st;
		}
	}

	for (i = 0; i < set2->max_size; i++)
	{

		if ((set2->hash_table)[i] != NULL)
		{

			st = set_insert(result, ((set2->hash_table)[i])->value);

			if (st != DS_OK)
				return st;
		}
	}

	return DS_OK;
}

Status set_intersection(HashSet *set1, HashSet *set2, HashSet *result)
{
	if (set1 == NULL || set2 == NULL || result == NULL)
		return DS_ERR_NULL_POINTER;

	if (!set_is_empty(result))
		return DS_ERR_INVALID_ARGUMENT;

	if (set1->size > result->max_size || set2->size > result->max_size)
		return DS_ERR_INVALID_ARGUMENT;

	Status st;

	bool exists;

	size_t i;
	for (i = 0; i < set1->max_size; i++)
	{

		if ((set1->hash_table)[i] != NULL)
		{

			st = set_contains(set2, ((set1->hash_table)[i])->value, &exists);

			if (st != DS_OK)
				return st;

			if (exists)
			{

				st = set_insert(result, ((set1->hash_table)[i])->value);

				if (st != DS_OK)
					return st;
			}
		}
	}

	return DS_OK;
}

Status set_difference(HashSet *set1, HashSet *set2, HashSet *result)
{
	if (set1 == NULL || set2 == NULL || result == NULL)
		return DS_ERR_NULL_POINTER;

	if (!set_is_empty(result))
		return DS_ERR_INVALID_ARGUMENT;

	if (set_is_empty(set1))
		return DS_OK;

	Status st;

	bool exists;

	size_t i;
	for (i = 0; i < set1->max_size; i++)
	{

		if ((set1->hash_table)[i] != NULL)
		{

			st = set_contains(set2, ((set1->hash_table)[i])->value, &exists);

			if (st != DS_OK)
				return st;

			if (!exists)
			{

				st = set_insert(result, ((set1->hash_table)[i])->value);

				if (st != DS_OK)
					return st;
			}
		}
	}

	return DS_OK;
}

Status set_complement(HashSet *set1, HashSet *set2, HashSet *result)
{
	Status st = set_difference(set2, set1, result);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status set_sym_diff(HashSet *set1, HashSet *set2, HashSet *result)
{
	if (set1 == NULL || set2 == NULL || result == NULL)
		return DS_ERR_NULL_POINTER;

	if (!set_is_empty(result))
		return DS_ERR_INVALID_ARGUMENT;

	if (set1->size + set2->size > result->max_size)
		return DS_ERR_INVALID_ARGUMENT;

	Status st;

	bool exists;

	size_t i;
	for (i = 0; i < set1->max_size; i++)
	{

		if ((set1->hash_table)[i] != NULL)
		{

			st = set_contains(set2, ((set1->hash_table)[i])->value, &exists);

			if (st != DS_OK)
				return st;

			if (!exists)
			{

				st = set_insert(result, ((set1->hash_table)[i])->value);

				if (st != DS_OK)
					return st;
			}
		}
	}

	for (i = 0; i < set2->max_size; i++)
	{

		if ((set2->hash_table)[i] != NULL)
		{

			st = set_contains(set1, ((set2->hash_table)[i])->value, &exists);

			if (st != DS_OK)
				return st;

			if (!exists)
			{

				st = set_insert(result, ((set2->hash_table)[i])->value);

				if (st != DS_OK)
					return st;
			}
		}
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Hash                                                |
// +-------------------------------------------------------------------------------------------------+

Status set_hash_djb2(char *key, size_t *hash)
{
	*hash = 5381;

	int c;

	while ((c = *key++) != 0)
		(*hash) = (((*hash) << 5) + (*hash)) + c;

	return DS_OK;
}

Status set_hash_sdbm(char *key, size_t *hash)
{
	*hash = 0;

	int c;

	while ((c = *key++) != 0)
		(*hash) = c + (((*hash) << 6) + ((*hash) << 16)) - (*hash);

	return DS_OK;
}

Status set_hash_prime(char *key, size_t *hash)
{
	*hash = 1279307;

	size_t prime = 37;

	int c;

	while ((c = *key++) != 0)
		*hash = ((*hash) * prime) + c * (*hash);

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
