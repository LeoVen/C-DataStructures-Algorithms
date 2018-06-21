/**
 * @file HashMap.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/06/2018
 *
 * @brief Source file for @c HashMap implementations in C
 *
 */

#include "HashMap.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status map_init_map(HashMap **map, size_t size, hash_function_t hash_function)
{
	if (size == 0)
		return DS_ERR_INVALID_SIZE;

	*map = malloc(sizeof(HashMap));

	if (!(*map))
		return DS_ERR_ALLOC;

	(*map)->hash_table = malloc(sizeof(HashMapEntry *) * size);

	if (!((*map)->hash_table))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < size; i++) {

		((*map)->hash_table)[i] = NULL;
	}

	(*map)->size = size;

	(*map)->hash_function = hash_function;

	return DS_OK;
}

Status map_init_entry(HashMapEntry **entry, int value)
{
	*entry = malloc(sizeof(HashMapEntry));

	(*entry)->value = value;
	(*entry)->hash = 0;

	(*entry)->next = NULL;
	(*entry)->key = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Status map_make_entry(HashMapEntry **entry, char *key, int value, size_t hash)
{
	*entry = malloc(sizeof(HashMapEntry));

	(*entry)->key = _strdup(key);
	(*entry)->value = value;
	(*entry)->hash = hash;

	(*entry)->next = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status map_insert(HashMap *map, char *key, int value)
{
	if (map == NULL)
		return DS_ERR_NULL_POINTER;

	size_t hash;

	Status st = map->hash_function(key, &hash);

	if (st != DS_OK)
		return st;

	size_t pos = hash % map->size;

	if ((map->hash_table)[pos] == NULL) {

		st = map_make_entry(&((map->hash_table)[pos]), key, value, hash);

		if (st != DS_OK)
			return st;
	}
	else {

		HashMapEntry *scan = (map->hash_table)[pos];

		while (scan->next != NULL)
		{
			scan = scan->next;
		}

		HashMapEntry *entry;

		st = map_make_entry(&entry, key, value, hash);

		if (st != DS_OK)
			return st;

		scan->next = entry;

	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status map_remove(HashMap *map, char *key)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status map_display_entry(HashMapEntry *entry)
{
	if (entry == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n| %21zu | %10d | %40s |", entry->hash, entry->value, entry->key);

	return DS_OK;
}

Status map_display_entry_raw(HashMapEntry *entry)
{
	if (entry == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n%21zu\t%10d\t%40s", entry->hash, entry->value, entry->key);

	return DS_OK;
}

Status map_display_map(HashMap *map)
{
	if (map == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n+-------------------------------------------------------------------------------+");
	printf("\n|                                Hash map                                     |");
	printf("\n+-----------------------+------------+------------------------------------------+");
	printf("\n|         HASH          |   VALUE    |                    KEY                   |");

	Status st;

	size_t i;
	for (i = 0; i < map->size; i++) {

		printf("\n+-----------------------+------------+------------------------------------------+");

		if ((map->hash_table)[i] == NULL)
			printf("\n|         NULL          |    NULL    |                    NULL                  |");
		else {

			if ((map->hash_table)[i]->next != NULL) {

				HashMapEntry *scan = (map->hash_table)[i];

				while (scan != NULL)
				{
					st = map_display_entry(scan);

					if (st != DS_OK)
						return st;

					scan = scan->next;
				}

			}
			else {

				st = map_display_entry((map->hash_table)[i]);

				if (st != DS_OK)
					return st;
			}
		}
	}

	printf("\n+-----------------------+------------+------------------------------------------+");

	printf("\n");

	return DS_OK;
}

Status map_display_map_raw(HashMap *map)
{
	if (map == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	size_t i;
	for (i = 0; i < map->size; i++) {

		if ((map->hash_table)[i] == NULL)
			printf("\n");
		else {

			if ((map->hash_table)[i]->next != NULL) {

				HashMapEntry *scan = (map->hash_table)[i];

				while (scan != NULL)
				{
					st = map_display_entry_raw(scan);

					if (st != DS_OK)
						return st;

					scan = scan->next;
				}

			}
			else {

				st = map_display_entry_raw((map->hash_table)[i]);

				if (st != DS_OK)
					return st;
			}
		}
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status map_delete_map(HashMap **map)
{
	if ((*map) == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < (*map)->size; i++) {

		if (((*map)->hash_table)[i] != NULL) {
			if ((((*map)->hash_table)[i])->next != NULL) {

				HashMapEntry *prev = ((*map)->hash_table)[i];
				HashMapEntry *scan = ((*map)->hash_table)[i];

				while (scan != NULL)
				{
					scan = scan->next;

					free(prev->key);
					free(prev);

					prev = scan;
				}

			}
			else {

				free((((*map)->hash_table)[i])->key);
				free(((*map)->hash_table)[i]);
			}

		}
		else
			free(((*map)->hash_table)[i]);

	}

	free((*map)->hash_table);
	free(*map);

	*map = NULL;

	return DS_OK;
}

Status map_erase_map(HashMap **map)
{
	if ((*map) == NULL)
		return DS_ERR_NULL_POINTER;

	size_t size = (*map)->size;
	Status(*hash_function) (char *, size_t *) = (*map)->hash_function;

	Status st = map_delete_map(map);

	if (st != DS_OK)
		return st;

	st = map_init_map(map, size, hash_function);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status map_search(HashMap *map, char *key, int *value)
{
	*value = 0;

	if (map == NULL)
		return DS_ERR_NULL_POINTER;

	size_t hash;

	map->hash_function(key, &hash);

	size_t pos = hash % map->size;

	if ((map->hash_table)[pos] == NULL)
		return DS_ERR_NOT_FOUND;

	if (((map->hash_table)[pos])->next == NULL && ((map->hash_table)[pos])->hash == hash)
		*value = ((map->hash_table)[pos])->value;
	else {

		HashMapEntry *scan = (map->hash_table)[pos];

		bool found = false;

		while (scan != NULL)
		{
			if (scan->hash == hash) {

				*value = scan->value;

				found = true;

				break;
			}

			scan = scan->next;
		}

		if (!found)
			return DS_ERR_NOT_FOUND;

	}

	return DS_OK;
}

//Status map_search_all(HashMap *map, char *key, int **value)

Status map_count_entries(HashMap *map, size_t *result)
{
	*result = 0;

	if (map == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < map->size; i++) {

		if ((map->hash_table)[i] != NULL) {

			if (((map->hash_table)[i])->next != NULL) {
				
				HashMapEntry *scan = (map->hash_table)[i];

				while (scan != NULL)
				{
					(*result)++;

					scan = scan->next;
				}
			}
			else {

				(*result)++;
			}
		}
	}

	return DS_OK;
}

Status map_count_collisions(HashMap *map, size_t *result)
{
	*result = 0;

	if (map == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < map->size; i++)
		if ((map->hash_table)[i] != NULL)
			if (((map->hash_table)[i])->next != NULL)
				(*result)++;

	return DS_OK;
}

Status map_count_empty(HashMap *map, size_t *result)
{
	*result = 0;

	if (map == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < map->size; i++)
		if ((map->hash_table)[i] == NULL)
			(*result)++;

	return DS_OK;
}

Status map_count_collisions_max(HashMap *map, size_t *result)
{
	*result = 0;

	if (map == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i, total;
	for (i = 0; i < map->size; i++) {

		if ((map->hash_table)[i] != NULL) {

			if (((map->hash_table)[i])->next != NULL) {

				total = 0;

				HashMapEntry *scan = (map->hash_table)[i];

				while (scan != NULL)
				{
					total++;

					scan = scan->next;
				}

			}
			else
				total = 1;

			if (total > *result)
				*result = total;

		}
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Hash                                                |
// +-------------------------------------------------------------------------------------------------+

Status map_hash_string_java(char *key, size_t *hash)
{
	size_t len = strlen(key);

	*hash = 0;

	if (len == 0)
		return DS_OK;

	size_t i;
	for (i = 0; i < len; i++)
		(*hash) += (size_t)pow((double)(key[i] * 31), (double)(len - i));

	return DS_OK;
}

Status map_hash_string_djb2(char *key, size_t *hash)
{
	*hash = 5381;

	int c;

	while (c = *key++)
		(*hash) = (((*hash) << 5) + (*hash)) + c;

	return DS_OK;
}

Status map_hash_string_sdbm(char *key, size_t *hash)
{
	*hash = 0;

	int c;

	while (c = *key++)
		(*hash) = c + (((*hash) << 6) + ((*hash) << 16)) - (*hash);

	return DS_OK;
}
