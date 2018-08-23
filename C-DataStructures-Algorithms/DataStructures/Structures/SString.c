/**
 * @file SString.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Source file for @c String implementations in C
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

	(*str)->buffer[0] = '\0';

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
Status str_make(String **str, char *string)
{
	size_t length = strlen(string);

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

		char *new_buffer = realloc((*str)->buffer, sizeof(char) * new_capacity);

		if (!new_buffer)
		{
			(*str)->capacity = _STRING_INIT_SIZE;

			return DS_ERR_ALLOC;
		}

		(*str)->buffer = new_buffer;

		(*str)->capacity = new_capacity;
	}

	(*str)->len = length;

	size_t i;
	for (i = 0; i < length; i++)
	{
		(*str)->buffer[i] = string[i];
	}

	(*str)->buffer[length] = '\0';

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Status str_get_string(String *str, const char **result)
{
	(*result) = NULL;

	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	char *string = malloc(sizeof(char) * (str->len + 1));

	if (!string)
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < str->len; i++)
		string[i] = str->buffer[i];

	string[str->len] = '\0';

	(*result) = string;

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
		st = str_push_char_front(str, ch);

		if (st != DS_OK)
			return st;
	}
	else if (index == str->len)
	{
		st = str_push_char_front(str, ch);

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

Status str_prepend(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str2))
		return DS_OK;

	Status st;

	while (!str_buffer_fits(str1, str2->len))
	{
		st = str_realloc(str1);

		if (st != DS_OK)
			return st;
	}

	size_t i;
	for (i = str1->len; i > 0; i--)
	{
		str1->buffer[i + str2->len - 1] = str1->buffer[i - 1];
	}

	for (i = 0; i < str2->len; i++)
	{
		str1->buffer[i] = str2->buffer[i];
	}

	str1->len += str2->len;

	str1->buffer[str1->len] = '\0';

	return DS_OK;
}

//Status str_add(String *str1, String *str2, size_t index)

Status str_append(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str2))
		return DS_OK;

	Status st;

	while (!str_buffer_fits(str1, str2->len))
	{
		st = str_realloc(str1);

		if (st != DS_OK)
			return st;
	}

	size_t i, j;
	for (i = str1->len, j = 0; i < str1->len + str2->len; i++, j++)
	{
		str1->buffer[i] = str2->buffer[j];
	}

	str1->len += str2->len;

	str1->buffer[str1->len] = '\0';

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status str_pop_char_front(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < str->len; i++)
	{
		str->buffer[i] = str->buffer[i + 1];
	}

	(str->len)--;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

Status str_pop_char_at(String *str, size_t index)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	if (index >= str->len)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = str_pop_char_front(str);

		if (st != DS_OK)
			return st;
	}
	else if (index == str->len - 1)
	{
		st = str_pop_char_back(str);

		if (st != DS_OK)
			return st;
	}
	else
	{
		size_t i;
		for (i = index; i < str->len; i++)
		{
			str->buffer[i] = str->buffer[i + 1];
		}

		(str->len)--;

		str->buffer[str->len] = '\0';
	}

	return DS_OK;
}

Status str_pop_char_back(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	(str->len)--;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

//Status str_remove(String *str, size_t from, size_t to)

//Status str_slice(String *str, size_t from, size_t to, const char *result)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status str_display(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	if (str_buffer_empty(str))
		return DS_OK;

	printf("String\n%s\n", str->buffer);

	return DS_OK;
}

Status str_display_raw(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	if (str_buffer_empty(str))
		return DS_OK;

	printf("%s", str->buffer);

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

// "clears" the buffer but doesn't shrinks
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

Status str_front(String *str, char *result)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	*result = str->buffer[0];

	return DS_OK;
}

Status str_back(String *str, char *result)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	*result = str->buffer[str->len - 1];

	return DS_OK;
}

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

Status str_compare(String *str1, String *str2, int *result)
{
	if (str1 == NULL || str2 == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_greater(str1, str2))
		*result = 1;
	else if (str_lesser(str1, str2))
		*result = -1;
	else
		*result = 0;

	return DS_OK;
}

// If str1 is greater than str2
bool str_greater(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return false;

	size_t i, len = (str1->len > str2->len) ? str2->len : str1->len;
	
	for (i = 0; i < len; i++)
	{
		if (str1->buffer[i] > str2->buffer[i])
			return true;
		else if (str1->buffer[i] < str2->buffer[i])
			return false;
	}

	if (str1->len > str2->len)
		return true;

	return false;
}

// If str1 equals str2
bool str_equals(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return false;

	if (str1->len != str2->len)
		return false;

	size_t i;
	for (i = 0; i < str1->len; i++)
		if (str1->buffer[i] != str2->buffer[i])
			return false;

	return true;
}

// If str1 is lesser than str2
bool str_lesser(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return false;

	size_t i, len = (str1->len > str2->len) ? str2->len : str1->len;

	for (i = 0; i < len; i++)
	{
		if (str1->buffer[i] < str2->buffer[i])
			return true;
		else if (str1->buffer[i] > str2->buffer[i])
			return false;
	}

	if (str1->len < str2->len)
		return true;

	return false;
}

bool str_equals_str(String *str, const char *string)
{
	if (str == NULL || string == NULL)
		return false;

	size_t len = strlen(string);

	if (str->len != len)
		return false;

	size_t i;
	for (i = 0; i < len; i++)
		if (str->buffer[i] != string[i])
			return false;

	return true;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

//Status str_copy(String *str, String **result)
//Status str_swap(String *str1, String *str2)

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

	char *new_buffer = realloc(str->buffer, sizeof(char) * str->capacity);

	if (!new_buffer)
	{
		str->capacity /= str->growth_rate;

		return DS_ERR_ALLOC;
	}

	str->buffer = new_buffer;

	str->buffer[str->len] = '\0';

	return DS_OK;
}