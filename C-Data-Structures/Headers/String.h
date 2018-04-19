/**
 * @file String.h
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

#include "..\Core\Core.h"

	typedef struct String {
		size_t length;
		char * content;
	} String;

	typedef enum Relation {
		R_LESSER    = -1,
		R_EQUAL     =  0,
		R_GREATER   =  1
	} Relation;

	Status str_make(String **str, char * content);

	Status str_display(String *str);

	size_t str_length(String *str);

	Status str_delete(String **str);

	//Status str_compare(String *str1, String *str2, Relation *result);

	//bool str_equals(String *str1, String *str2, bool case_sensitive);

	// Use str_compare function to determine return result
	//bool str_is_greater(String *str1, String *str2);
	//bool str_is_greater_eq(String *str1, String *str2);
	//bool str_is_lesser(String *str1, String *str2);
	//bool str_is_lesser_eq(String *str1, String *str2);

#ifdef __cplusplus
}
#endif
