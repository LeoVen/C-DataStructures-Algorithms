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
extern "C"
{
#endif

#include "Core.h"

#ifndef _STRING_SPEC
#define _STRING_SPEC

#define _STRING_INIT_SIZE 8
#define _STRING_GROW_RATE 2

#endif

	/**
	 * @brief A wrapper for an array of characters
	 *
	 * A @c String is an array of characters. The purpose of this structure is
	 * to make an abstraction on top of this array. It is a very useful
	 * abstraction and makes dealing with strings much easier.
	 *
	 * @b Advantages over <code> char* </code>
	 * - Dynamic size
	 * - Easy insertion/removal
	 *
	 * @b Drawbacks
	 * - None
	 *
	 * @b Functions
	 *
	 * @c SString.c
	 */
	typedef struct String
	{
		char *buffer;		/*!< Character buffer */
		size_t len;			/*!< Word length */
		size_t capacity;	/*!< Buffer capacity */
		size_t growth_rate; /*!< Buffer capacity growth rate */
	} String;

	Status str_init(String **str);
	Status str_make(String **str, char *content);

	Status str_get_string(String *str, const char **result);

	Status str_push_char_front(String *str, const char ch);
	Status str_push_char_at(String *str, const char ch, size_t index);
	Status str_push_char_back(String *str, const char ch);

	Status str_push_front(String *str, const char *ch);
	Status str_push_at(String *str, const char *ch, size_t index);
	Status str_push_back(String *str, const char *ch);

	Status str_prepend(String *str1, String *str2);
	Status str_add(String *str1, String *str2, size_t index);
	Status str_append(String *str1, String *str2);

	Status str_pop_char_front(String *str);
	Status str_pop_char_at(String *str, size_t index);
	Status str_pop_char_back(String *str);

	//Status str_remove(String *str, size_t from, size_t to);
	//Status str_slice(String *str, size_t from, size_t to, String *result);

	Status str_display(String *str);
	Status str_display_raw(String *str);

	Status str_delete(String **str);
	Status str_erase(String **str);

	Status str_back(String *str, char *result);
	Status str_front(String *str, char *result);

	size_t str_length(String *str);
	size_t str_len(char *ch);

	Status str_compare(String *str1, String *str2, int *result);
	bool str_greater(String *str1, String *str2);
	bool str_equals(String *str1, String *str2);
	bool str_lesser(String *str1, String *str2);

	bool str_equals_str(String *str, const char *string);

	//bool str_substring(String *str1, String *str2);
	//bool str_substr(String *str, const char *ch);

	//Status str_copy(String *str, String **result);
	//Status str_swap(String *str1, String *str2);

	bool str_buffer_full(String *str);
	bool str_buffer_empty(String *str);
	bool str_buffer_fits(String *str, size_t str_len);

	Status str_realloc(String *str);

#ifdef __cplusplus
}
#endif
