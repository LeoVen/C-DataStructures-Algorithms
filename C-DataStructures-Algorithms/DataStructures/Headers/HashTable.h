/**
 * @file HashTable.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/06/2018
 *
 * @brief Header file for @c HashTable implementations in C
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

	typedef struct HashTableEntry {
		char *key;
		int value;
		size_t hash;
		struct HashTableEntry *next;
	} HashTableEntry;

	typedef struct HashTable {
		struct HashTableEntry **buckets;
		size_t size;
		Status(*hash_function) (char *, size_t *);
	} HashTable;

	Status hst_init_table(HashTable **hst, size_t size, hash_function_t hash_function);
	Status hst_init_entry(HashTableEntry **entry, int value);

	Status hst_make_entry(HashTableEntry **entry, char *key, int value, size_t hash);

	Status hst_insert(HashTable *hst, char *key, int value);

	//Status hst_remove(HashTable *hst, char *key);

	Status hst_display_entry(HashTableEntry *entry);
	Status hst_display_table(HashTable *hst);
	Status hst_display_entry_raw(HashTableEntry *entry);
	Status hst_display_table_raw(HashTable *hst);

	Status hst_delete_table(HashTable **hst);
	Status hst_erase_table(HashTable **hst);

	Status hst_search(HashTable *hst, char *key, int *value);
	//Status hst_search_all(HashTable *hst, char *key, int **value);

	Status hst_count_entries(HashTable *hst, size_t *result);
	Status hst_count_collisions(HashTable *hst, size_t *result);
	Status hst_count_empty(HashTable *hst, size_t *result);
	Status hst_count_collisions_max(HashTable *hst, size_t *result);

	Status hst_hash_string_java(char *key, size_t *hash);
	Status hst_hash_string_djb2(char *key, size_t *hash);
	Status hst_hash_string_sdbm(char *key, size_t *hash);
	
	
#ifdef __cplusplus
}
#endif