/**
 * @file SString.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Header file for @c String implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "Core.h"

#ifndef _STRING_SPEC
#define _STRING_SPEC

#define _STRING_INIT_SIZE 8
#define _STRING_GROW_RATE 2

#endif

	typedef struct String {
		char *buffer;
		size_t len;
		size_t capacity;
		size_t growth_rate;
	} String;

	Status str_init(String **str);
	Status str_make(String **str, char * content);

	Status str_push_char_front(String *str, const char ch);
	Status str_push_char_at(String *str, const char ch, size_t index);
	Status str_push_char_back(String *str, const char ch);

	//Status str_push_front(String *str, const char *ch);
	//Status str_push_at(String *str, const char *ch, size_t index);
	//Status str_push_back(String *str, const char *ch);

	//Status str_append(String *str1, String *str2);
	//Status str_add(String *str1, String *str2, size_t index);
	//Status str_prepend(String *str1, String *str2);

	//Status str_pop_front(String *str);
	//Status str_pop_at(String *str, size_t index);
	//Status str_pop_back(String *str);

	//Status str_slice(String *str, size_t from, size_t to, const char *result);

	Status str_display(String *str);
	Status str_display_raw(String *str);

	Status str_delete(String **str);
	Status str_erase(String **str);

	Status str_length(String *str, size_t *result);
	size_t str_len(String *str);

	//Status str_compare(String *str1, String *str2, int *result);

	//bool str_equals(String *str1, String *str2, bool case_sensitive);

	bool str_buffer_full(String *str);
	bool str_buffer_empty(String *str);
	bool str_buffer_fits(String *str, size_t str_len);

	Status str_realloc(String *str);

#ifdef __cplusplus
}
#endif
