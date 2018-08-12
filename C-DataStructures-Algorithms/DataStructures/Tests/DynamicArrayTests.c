/**
 * @file DynamicArrayTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/03/2018
 *
 * @brief Test Cases for @c DynamicArray implementations in C
 *
 */

#include "DynamicArray.h"

int DAR_IO_TESTS(void);

int DynamicArrayTests(void)
{
	//DAR_IO_TESTS();

	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |           C Dynamic Array           |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	DynamicArray *array;

	dar_init(&array);

	size_t f;
	int i;
	for (i = 0; i < 100; i++)
	{
		dar_insert_back(array, i);
	}

	dar_display(array);

	for (i = 0; i < 100; i++)
	{
		dar_insert_front(array, i);
	}

	dar_display(array);

	dar_insert_at(array, 101, 100);

	dar_display(array);

	dar_remove_at(array, 100);

	dar_display(array);

	dar_delete(&array);

	int vector[100];

	for (i = 0; i < 100; i++)
	{
		vector[i] = rand();
	}

	printf("\nNormal Array:\n");

	for (i = 0; i < 100; i++)
	{
		printf("%d ", vector[i]);
	}

	printf("\n");

	dar_make(&array, vector, 100);

	dar_display(array);

	dar_delete(&array);

	dar_init(&array);

	for (i = 0; i < 100; i++)
		dar_insert_back(array, rand() % 10);

	dar_display(array);

	for (i = 0; i < 10; i++)
	{
		dar_frequency(array, i, &f);
		printf("\nThe number %d appears %zu times", i, f);
	}

	printf("\n\nRemoving keys 1, 2 and 3:");

	dar_remove_keys(array, 1);
	dar_remove_keys(array, 2);
	dar_remove_keys(array, 3);

	dar_display(array);

	for (i = 0; i < 10; i++)
	{
		dar_frequency(array, i, &f);
		printf("\nThe number %d appears %zu times", i, f);
	}

	dar_delete(&array);

	printf("\n");
	return 0;
}

int DAR_IO_TESTS(void)
{
	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- --------- Begin tests --------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	Status st = DS_OK;

	DynamicArray *array = NULL;

	dar_init(&array);

	size_t pos = 0, size = 0, l_max = 5, position = 0;
	int i, a, b, max = 100, value = 0;

	printf("\n---------- ---------- ---------- ---------- ----------");
	for (i = 0; i < 1000; i++)
	{
		printf("\n---------- ---------- ---------- ---------- ----------");

		a = rand();
		b = rand() % 3;

		size = dar_size(array);

		if (a % 2 == 0 && size < l_max)
		{
			// Insert
			if (b == 0)
			{
				// Insert front
				printf("\ndar_insert_front()");
				st = dar_insert_front(array, rand() % max);
			}
			else if (b == 1)
			{
				// Insert at
				printf("\ndar_insert_at()");
				if (size != 0)
					pos = rand() % array->size;
				printf(" position %zu", pos);
				st = dar_insert_at(array, rand() % max, pos);
			}
			else
			{
				// Insert back
				printf("\ndar_insert_back()");
				st = dar_insert_back(array, rand() % max);
			}
			// End Insert
		}
		else
		{
			// Remove
			if (b == 0)
			{
				// Remove front
				printf("\ndar_remove_front()");
				st = dar_remove_front(array);
			}
			else if (b == 1)
			{
				// Remove at
				printf("\ndar_remove_at()");
				if (size != 0)
					pos = rand() % array->size;
				printf(" position %zu", pos);
				st = dar_remove_at(array, pos);
			}
			else
			{
				// Remove back
				printf("\ndar_remove_back()");
				st = dar_remove_back(array);
			}

			// End Remove
		}

		dar_display(array);

		dar_find_max(array, &value);
		dar_find_max_pos(array, &position);
		printf("\nMaximum value: %d at position %zu", value, position);
		dar_find_min(array, &value);
		dar_find_min_pos(array, &position);
		printf("\nMinimum value: %d at position %zu", value, position);
		printf("\nSize: %zu", array->size);
		print_status_repr(st);

		printf("\n---------- ---------- ---------- ---------- ----------");
	}

	printf("\n---------- ---------- ---------- ---------- ----------");
	printf("\nFinal Dynamic Array size: %zu", array->size);

	dar_delete(&array);

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- End tests ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	return 0;
}