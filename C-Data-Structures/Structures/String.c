/**
 * @file String.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Source file for @c String implementations in C
 *
 * In this source file, a string will be implemented to support most operations
 * that a String class has in a higher level language.
 *
 */

#include "..\Headers\String.h"

Status str_make(String **str, char * content)
{
	size_t len = strlen(content);

	if (len == 0)
		return DS_ERR_INVALID_ARGUMENT;

	(*str) = malloc(sizeof(String));

	if (!(*str))
		return DS_ERR_ALLOC;

	(*str)->content = malloc(len * sizeof(char));

	if (!((*str)->content))
		return DS_ERR_ALLOC;

	(*str)->content = _strdup(content);

	(*str)->length = len;

	return DS_OK;
}

Status str_display(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n%s\n", str->content);

	return DS_OK;
}

size_t str_length(String *str)
{
	return str->length;
}

//Status str_compare(String *str1, String *str2, Relation *result)


//bool str_equals(String *str1, String *str2, bool case_sensitive)

Status str_delete(String **str)
{
	if ((*str) == NULL)
		return DS_ERR_NULL_POINTER;

	free((*str)->content);

	free(*str);

	*str = NULL;

	return DS_OK;
}