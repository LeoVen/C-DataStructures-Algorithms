/**
 * @file SString.c
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

#include "SString.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

/**
* Initializes the string structure
*
*
*/
Status str_init(String **str)
{
	(*str) = malloc(sizeof(String));

	if (!(*str))
		return DS_ERR_ALLOC;

	(*str)->buffer = malloc(sizeof(char) * _STRING_INIT_SIZE);

	if (!((*str)->buffer))
		return DS_ERR_ALLOC;

	(*str)->capacity = _STRING_INIT_SIZE;
	(*str)->growth_rate = _STRING_GROW_RATE;

	(*str)->len = 0;

	return DS_OK;
}

/**
 * Initializes a null-terminated string
 *
 *
 */
Status str_make(String **str, char *content)
{
	size_t length = strlen(content);

	if (length == 0)
		return DS_ERR_INVALID_ARGUMENT;

	Status st = str_init(str);

	if (st != DS_OK)
		return st;

	if ((*str)->capacity <= length)
	{
		size_t new_capacity = _STRING_INIT_SIZE;

		while (new_capacity <= length)
		{
			new_capacity *= _STRING_GROW_RATE;
		}

		(*str)->buffer = realloc((*str)->buffer, sizeof(char) * new_capacity);

		if (!((*str)->buffer))
			return DS_ERR_ALLOC;

		(*str)->capacity = new_capacity;
	}

	(*str)->len = length;

	size_t i;
	for (i = 0; i < length; i++)
	{
		(*str)->buffer[i] = content[i];
	}

	(*str)->buffer[length] = '\0';

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status str_push_char_front(String *str, const char ch)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	if (str_buffer_full(str))
	{
		st = str_realloc(str);

		if (st != DS_OK)
			return st;
	}

	size_t i;
	for (i = str->len; i > 0; i--)
	{
		str->buffer[i] = str->buffer[i - 1];
	}

	str->buffer[0] = ch;

	(str->len)++;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

Status str_push_char_at(String *str, const char ch, size_t index)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (index > str->len)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = str_push_front(str, ch);

		if (st != DS_OK)
			return st;
	}
	else if (index == str->len)
	{
		st = str_push_front(str, ch);

		if (st != DS_OK)
			return st;
	}
	else
	{
		if (str_buffer_full(str))
		{
			st = str_realloc(str);

			if (st != DS_OK)
				return st;
		}

		size_t i;
		for (i = str->len; i > index; i--)
		{
			str->buffer[i] = str->buffer[i - 1];
		}

		str->buffer[index] = ch;

		(str->len)++;

		str->buffer[str->len] = '\0';
	}

	return DS_OK;
}

Status str_push_char_back(String *str, const char ch)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	if (str_buffer_full(str))
	{
		st = str_realloc(str);

		if (st != DS_OK)
			return st;
	}

	str->buffer[str->len] = ch;

	(str->len)++;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

//Status str_push_front(String *str, const char *ch)

//Status str_push_at(String *str, const char *ch, size_t index)

//Status str_push_back(String *str, const char *ch)

//Status str_append(String *str1, String *str2)

//Status str_add(String *str1, String *str2, size_t index)

//Status str_prepend(String *str1, String *str2)

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status str_pop_front(String *str)

//Status str_pop_at(String *str, size_t index)

//Status str_pop_back(String *str)

//Status str_slice(String *str, size_t from, size_t to, const char *result)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status str_display(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	printf("\nString\n%s\n", str->buffer);

	return DS_OK;
}

Status str_display_raw(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	printf("\n%s\n", str->buffer);

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status str_delete(String **str)
{
	if ((*str) == NULL)
		return DS_ERR_NULL_POINTER;

	free((*str)->buffer);

	free(*str);

	*str = NULL;

	return DS_OK;
}

Status str_erase(String **str)
{
	if ((*str) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = str_delete(str);

	if (st != DS_OK)
		return st;

	st = str_init(str);

	if (st != DS_OK)
		return st;
	
	return DS_OK;
}

// "clears" the buffer
Status str_clear(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	str->len = 0;

	str->buffer[0] = '\0';

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status str_length(String *str, size_t *result)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	*result = str->len;

	return DS_OK;
}

size_t str_len(String *str)
{
	return str->len;
}

//Status str_compare(String *str1, String *str2, int *result)

//bool str_equals(String *str1, String *str2, bool case_sensitive)

// +-------------------------------------------------------------------------------------------------+
// |                                            Buffer                                               |
// +-------------------------------------------------------------------------------------------------+

bool str_buffer_full(String *str)
{
	return (str->len + 1) >= str->capacity; // +1 So we are able to write '\0' at the end
}

bool str_buffer_empty(String *str)
{
	return str->len == 0;
}

bool str_buffer_fits(String *str, size_t str_len)
{
	return (str->len + str_len) < str->capacity;
}

Status str_realloc(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	str->capacity *= str->growth_rate;

	str->buffer = realloc(str->buffer, sizeof(char) * str->capacity);

	if (!(str->buffer))
		return DS_ERR_ALLOC;

	str->buffer[str->len] = '\0';

	return DS_OK;
}