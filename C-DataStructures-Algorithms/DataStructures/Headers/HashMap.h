/**
 * @file HashMap.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/06/2018
 *
 * @brief Header file for @c HashMap implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "Core.h"

#ifndef HASH_FUNCTION_TYPE
#define HASH_FUNCTION_TYPE
	typedef Status(*hash_function_t)(char *, size_t *);
#endif

	typedef struct HashMapEntry {
		char *key;
		int value;
		size_t hash;
		struct HashMapEntry *next;
	} HashMapEntry;

	typedef struct HashMap {
		struct HashMapEntry **hash_table;
		size_t size;
		Status(*hash_function) (char *, size_t *);
	} HashMap;

	Status map_init_map(HashMap **map, size_t size, hash_function_t hash_function);
	Status map_init_entry(HashMapEntry **entry, int value);

	Status map_make_entry(HashMapEntry **entry, char *key, int value, size_t hash);

	Status map_insert(HashMap *map, char *key, int value);

	//Status map_remove(HashMap *map, char *key);

	Status map_display_entry(HashMapEntry *entry);
	Status map_display_map(HashMap *map);
	Status map_display_entry_raw(HashMapEntry *entry);
	Status map_display_map_raw(HashMap *map);

	Status map_delete_map(HashMap **map);
	Status map_erase_map(HashMap **map);

	Status map_search(HashMap *map, char *key, int *value);
	//Status map_search_all(HashMap *map, char *key, int **value);

	Status map_count_entries(HashMap *map, size_t *result);
	Status map_count_collisions(HashMap *map, size_t *result);
	Status map_count_empty(HashMap *map, size_t *result);
	Status map_count_collisions_max(HashMap *map, size_t *result);

	Status map_hash_string_java(char *key, size_t *hash);
	Status map_hash_string_djb2(char *key, size_t *hash);
	Status map_hash_string_sdbm(char *key, size_t *hash);
	
	
#ifdef __cplusplus
}
#endif