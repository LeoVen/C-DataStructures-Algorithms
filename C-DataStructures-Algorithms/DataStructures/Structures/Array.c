/**
 * @file Array.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 19/03/2018
 *
 * @brief Source file for @c Array implementations in C
 *
 */

#include "Array.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

/**
 * @brief Initializes a new @c Array.
 *
 * This functions uses malloc to allocate a new @c Array and its buffer with a
 * fixed size. This buffer is where all data will be stored.
 *
 * @param[out] arr Reference to an empty @c Array
 * @param[in] size Desired buffer size for the @c Array
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_ALLOC if allocation failed
 *
 * @b Usage
 * @code{.c}
 * Array *arr;
 * arr_init(&arr, 10); // New initialized array with a fixed size of 10
 * @endcode
 */
Status arr_init(Array **arr, size_t size)
{
	if (size == 0)
		return DS_ERR_INVALID_ARGUMENT;

	(*arr) = malloc(sizeof(Array));

	if (!(*arr))
		return DS_ERR_ALLOC;

	(*arr)->buffer = calloc(size, sizeof(int));

	if (!(*arr)->buffer)
		return DS_ERR_ALLOC;

	(*arr)->size = size;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

/**
 * @brief Inserts a new value in an empty space
 *
 * This functions will try to insert a new value in an empty space. If that
 * space is not empty or if the @c index parameter is greater than the buffer
 * region @c DS_ERR_INVALID_POSITION is returned.
 *
 * @param[in] arr Reference to an @c Array
 * @param[in] index Index to insert new value
 * @param[in] value Integer value to be added to the buffer
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if referenced array points to @c NULL
 * @return @c DS_ERR_INVALID_POSITION if index is higher or equal to the buffer
 * size or if in that index the buffer value is not 0, that is, that position
 * is not empty
 *
 * @see arr_update()
 *
 * @b Usage
 * @code{.c}
 * Array *arr;
 * arr_init(&arr, 10); // New initialized array with a fixed size of 10
 *
 * arr_insert(arr, 2, 9);
 * arr_insert(arr, 5, 11);
 * // [ 0, 0, 9, 0, 0, 5, 0, 0, 0, 0 ]
 *
 * arr_insert(arr, 5, 22);  // DS_ERR_INVALID_POSITION (non-empty position)
 * arr_insert(arr, 12, 23); // DS_ERR_INVALID_POSITION (out of range)
 * @endcode
 */
Status arr_insert(Array *arr, size_t index, int value)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (index >= arr->size)
		return DS_ERR_INVALID_POSITION;

	if (arr->buffer[index] == 0)
	{

		arr->buffer[index] = value;

		return DS_OK;
	}

	return DS_ERR_INVALID_POSITION;
}

/**
 * @brief Inserts a new value in the first available empty space
 *
 * This functions will try to insert a new value in the first empty space it
 * can find. If there are no spaces left available then @c DS_ERR_FULL is
 * returned.
 *
 * @param[in] arr Reference to an @c Array
 * @param[in] value Integer value to be added to the buffer
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if referenced array points to @c NULL
 * @return @c DS_ERR_FULL if there are no empty spaces left for insertion
 *
 * @b Usage
 * @code{.c}
 * Array *arr;
 * arr_init(&arr, 10); // New initialized array with a fixed size of 10
 *
 * arr_push(arr, 9);
 * arr_push(arr, 11);
 * arr_push(arr, 15);
 * // [ 9, 11, 15, 0, 0, 0, 0, 0, 0, 0 ]
 * @endcode
 */
Status arr_push(Array *arr, int value)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	bool ok = false;

	size_t i;
	for (i = 0; i < arr->size; i++)
	{

		if (arr->buffer[i] == 0)
		{

			arr->buffer[i] = value;

			ok = true;

			break;
		}
	}

	if (ok)
		return DS_OK;

	return DS_ERR_FULL;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Update                                              |
// +-------------------------------------------------------------------------------------------------+

/**
 * @brief Updates the value of a non-empty position in the buffer
 *
 * This functions updates a non-empty position in the buffer. If the position
 * is greather than the buffer size of if that position is empty then @c
 * DS_ERR_INVALID_POSITION is returned. Note that if the new value is 0 then 
 * that position will be considered as empty.
 *
 * @param[in] arr Reference to an @c Array
 * @param[in] index Index to be updated
 * @param[in] value Integer value to be updated to the buffer
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if referenced array points to @c NULL
 * @return @c DS_ERR_INVALID_POSITION if index is higher or equal to the buffer
 * size or if in that index the buffer value is 0, that is, that position is
 * empty
 *
 * @b Usage
 * @code{.c}
 * Array *arr;
 * arr_init(&arr, 10); // New initialized array with a fixed size of 10
 *
 * arr_push(arr, 9);
 * arr_push(arr, 11);
 * // [ 9, 11, 0, 0, 0, 0, 0, 0, 0, 0 ]
 * arr_update(arr, 1, 9);
 * // [ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0 ]
 *
 * arr_update(arr, 4, 22);  // DS_ERR_INVALID_POSITION (empty position)
 * arr_update(arr, 12, 23); // DS_ERR_INVALID_POSITION (out of range)
 * @endcode
 */
Status arr_update(Array *arr, size_t index, int value)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (index >= arr->size)
		return DS_ERR_INVALID_POSITION;

	if (arr->buffer[index] != 0)
	{

		arr->buffer[index] = value;

		return DS_OK;
	}

	return DS_ERR_INVALID_POSITION;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

/**
 * @brief removes a non-empty position in the buffer
 *
 * This functions sets to 0 a given position in the buffer. If that position is
 * already 0 then @c DS_ERR_INVALID_POSITION is returned.
 *
 * @param[in] arr Reference to an @c Array
 * @param[in] index Index to be removed
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if referenced array points to @c NULL
 * @return @c DS_ERR_INVALID_POSITION if index is higher or equal to the buffer
 * size or if in that index the buffer value is 0, that is, that position is
 * already empty
 *
 * @b Usage
 * @code{.c}
 * Array *arr;
 * arr_init(&arr, 10); // New initialized array with a fixed size of 10
 *
 * arr_push(arr, 9);
 * arr_push(arr, 11);
 * arr_push(arr, 15);
 * // [ 9, 11, 15, 0, 0, 0, 0, 0, 0, 0 ]
 * arr_remove(arr, 1);
 * // [ 9, 0, 15, 0, 0, 0, 0, 0, 0, 0 ]
 *
 * arr_remove(arr, 8, 22);  // DS_ERR_INVALID_POSITION (already empty position)
 * arr_remove(arr, 12, 23); // DS_ERR_INVALID_POSITION (out of range)
 * @endcode
 */
Status arr_remove(Array *arr, size_t index)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (index >= arr->size)
		return DS_ERR_INVALID_POSITION;

	if (arr->buffer[index] != 0)
	{

		arr->buffer[index] = 0;

		return DS_OK;
	}

	return DS_ERR_INVALID_POSITION;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status arr_display(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr_is_empty(arr))
	{
		printf("\nArray\n[ empty ]\n");

		return DS_OK;
	}

	printf("\nArray\n[ ");

	size_t i;
	for (i = 0; i < arr->size - 1; i++)
	{

		printf("%d, ", arr->buffer[i]);
	}

	printf("%d ]\n", arr->buffer[arr->size - 1]);

	return DS_OK;
}

Status arr_display_raw(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	size_t i;
	for (i = 0; i < arr->size; i++)
	{

		printf("%d ", arr->buffer[i]);
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status arr_delete(Array **arr)
{
	if (*arr == NULL)
		return DS_ERR_NULL_POINTER;

	free((*arr)->buffer);
	free((*arr));

	(*arr) = NULL;

	return DS_OK;
}

Status arr_erase(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;

	for (i = 0; i < arr->size; i++)
	{

		arr->buffer[i] = 0;
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status arr_max(Array *arr, int *result)
{
	*result = 0;

	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	int min = arr->buffer[0];

	for (i = 1; i < arr->size; i++)
	{

		if (arr->buffer[i] > min)
		{

			min = arr->buffer[i];
		}
	}

	*result = min;

	return DS_OK;
}

Status arr_min(Array *arr, int *result)
{
	*result = 0;

	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	int min = arr->buffer[0];

	for (i = 1; i < arr->size; i++)
	{

		if (arr->buffer[i] < min)
		{

			min = arr->buffer[i];
		}
	}

	*result = min;

	return DS_OK;
}

Status arr_frequency(Array *arr, int key, int *result)
{
	*result = 0;

	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < arr->size; i++)
	{

		if (arr->buffer[i] == key)
			(*result)++;
	}

	return DS_OK;
}

Status arr_key_positions(Array *arr, Array **result, int key)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i, j = 0;
	int val = 0, total = 0;

	Status st = arr_frequency(arr, key, &total);

	if (st != DS_OK)
		return st;

	st = arr_init(result, total);

	if (st != DS_OK)
		return st;

	for (i = 0; i < arr->size; i++)
	{

		if (arr->buffer[i] == key)
		{

			(*result)->buffer[j] = val;
			j++;
		}

		val++;
	}

	return DS_OK;
}

bool arr_is_empty(Array *arr)
{
	size_t i;
	for (i = 0; i < arr->size; i++)
		if (arr->buffer[i] != 0)
			return false;

	return true;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

Status arr_copy(Array *arr, Array **result)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	arr_init(result, arr->size);

	if (!(*result))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < arr->size; i++)
		(*result)->buffer[i] = arr->buffer[i];

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                           Sorting                                               |
// +-------------------------------------------------------------------------------------------------+

Status arr_switch(Array *arr, size_t pos1, size_t pos2)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (pos1 >= arr->size || pos2 >= arr->size)
		return DS_ERR_INVALID_POSITION;

	int temp = arr->buffer[pos1];
	arr->buffer[pos1] = arr->buffer[pos2];
	arr->buffer[pos2] = temp;

	return DS_OK;
}

Status arr_reverse(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	size_t i;
	for (i = 0; i < arr->size / 2; i++)
	{

		st = arr_switch(arr, i, arr->size - i - 1);

		if (st != DS_OK)
			return st;
	}

	return DS_OK;
}

Status arr_blend(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size < 2)
		return DS_ERR_INVALID_OPERATION;

	size_t i;

	size_t loop = arr->size * 100;
	for (i = 0; i < loop; i++)
	{

		arr_switch(arr, (size_t)rand() % arr->size, (size_t)rand() % arr->size);
	}

	return DS_OK;
}

Status arr_sort_bubble(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size < 2)
		return DS_ERR_INVALID_OPERATION;

	size_t i, j;
	for (i = 0; i < arr->size - 1; i++)
	{

		for (j = 0; j < arr->size - i - 1; j++)
		{

			if (arr->buffer[j] > arr->buffer[j + 1])
			{

				arr_switch(arr, j, j + 1);
			}
		}
	}

	return DS_OK;
}

Status arr_sort_selection(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size < 2)
		return DS_ERR_INVALID_OPERATION;

	size_t i, j, min;

	for (i = 0; i < arr->size - 1; i++)
	{

		min = i;

		for (j = i + 1; j < arr->size; j++)
			if (arr->buffer[j] < arr->buffer[min])
				min = j;

		arr_switch(arr, min, i);
	}

	return DS_OK;
}

Status arr_sort_insertion(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size < 2)
		return DS_ERR_INVALID_OPERATION;

	size_t i, j;
	int num;
	for (i = 1; i < arr->size; i++)
	{

		num = arr->buffer[i];

		j = i - 1;

		while (arr->buffer[j] > num)
		{
			arr->buffer[j + 1] = arr->buffer[j];
			j--;
		}

		arr->buffer[j + 1] = num;
	}

	return DS_OK;
}
