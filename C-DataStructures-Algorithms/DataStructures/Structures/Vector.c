/**
 * @file Vector.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/03/2018
 *
 * @brief Source file for @c Vector implementations in C
 *
 */

#include "Vector.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status vec_build(double x, double y, double z, Vector **vec)
{
	(*vec) = malloc(sizeof(Vector));

	if (!(*vec))
		return DS_ERR_ALLOC;

	(*vec)->x = x;
	(*vec)->y = y;
	(*vec)->z = z;

	(*vec)->base = malloc(sizeof(Basis));

	if (!((*vec)->base))
		return DS_ERR_ALLOC;

	Status st = vec_build_simple(1, 0, 0, &((*vec)->base->i));

	if (st != DS_OK)
		return st;

	st = vec_build_simple(0, 1, 0, &((*vec)->base->j));

	if (st != DS_OK)
		return st;

	st = vec_build_simple(0, 0, 1, &((*vec)->base->k));

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status vec_build_simple(double x, double y, double z, SimpleVector **vec)
{
	(*vec) = malloc(sizeof(SimpleVector));

	if (!(*vec))
		return DS_ERR_ALLOC;

	(*vec)->x = x;
	(*vec)->y = y;
	(*vec)->z = z;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status vec_display(Vector *v)
{
	printf("\nVector\n[%8.2lf i ]\n[%8.2lf j ]\n[%8.2lf k ]", v->x, v->y, v->z);
	printf("\nBase\n[%4.2lf, %4.2lf, %4.2lf], [%4.2lf, %4.2lf, %4.2lf], [%4.2lf, %4.2lf, %4.2lf]\n",
		   v->base->i->x, v->base->i->y, v->base->i->z,
		   v->base->j->x, v->base->j->y, v->base->j->z,
		   v->base->k->x, v->base->k->y, v->base->k->z);

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                           Operations                                            |
// +-------------------------------------------------------------------------------------------------+

/**
 * @brief Calculates Vector Modulus or Magnitude or Absolute Value
 *
 * @param[in] vec Vector to calculate its modulus
 * @param[out] result Resultant vector modulus
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if @c vec parameter is @c NULL
 */
Status vec_mod(Vector *vec, double *result)
{
	*result = 0;

	if (vec == NULL)
		return DS_ERR_NULL_POINTER;

	*result = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);

	return DS_OK;
}

/**
 * @brief Calculates the sum of two @c Vector
 *
 * @param[in] vec1 First @c Vector
 * @param[in] vec2 Second @c Vector
 * @param[out] result Resultant @c Vector of operation
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if either @c vec1 or @c vec2 parameters are
 * @c NULL
 */
Status vec_sum(Vector *vec1, Vector *vec2, Vector **result)
{
	if (vec1 == NULL || vec2 == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = vec_build(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z, result);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

/**
 * @brief Subtracts the second @c Vector with the first
 *
 * @param[in] vec1 First @c Vector
 * @param[in] vec2 Second @c Vector
 * @param[out] result Resultant @c Vector of operation
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if either @c vec1 or @c vec2 parameters are
 * @c NULL
 */
Status vec_subtract(Vector *vec1, Vector *vec2, Vector **result)
{
	if (vec1 == NULL || vec2 == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = vec_build(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z, result);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

/**
 * @brief Performs a scalar product
 *
 * @param[in] vec Vector to perform a scalar product
 * @param[in] scalar Scalar value to multiply
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if @c vec parameter is @c NULL
 */
Status vec_product_scalar(Vector *vec, double scalar)
{
	if (vec == NULL)
		return DS_ERR_NULL_POINTER;

	vec->x *= scalar;
	vec->y *= scalar;
	vec->z *= scalar;

	return DS_OK;
}

/**
 * @brief Performs a dot product between @c Vector 1 and 2
 *
 * @param[in] vec1 First @c Vector
 * @param[in] vec2 Second @c Vector
 * @param[out] result Dot product result
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if either @c vec1 or @c vec2 parameters are
 * @c NULL
 */
Status vec_product_dot(Vector *vec1, Vector *vec2, double *result)
{
	if (vec1 == NULL || vec2 == NULL)
		return DS_ERR_NULL_POINTER;

	*result = vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z;

	return DS_OK;
}

/**
 * @brief Calculates the angle between @c Vector 1 and 2
 *
 * @param[in] vec1 First @c Vector
 * @param[in] vec2 Second @c Vector
 * @param[out] result Angle between the two vectors
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if either @c vec1 or @c vec2 parameters are
 * @c NULL
 */
Status vec_angle(Vector *vec1, Vector *vec2, double *result)
{
	if (vec1 == NULL || vec2 == NULL)
		return DS_ERR_NULL_POINTER;

	double dot, mod1, mod2;

	Status st = vec_product_dot(vec1, vec2, &dot);

	if (st != DS_OK)
		return st;

	st = vec_mod(vec1, &mod1);

	if (st != DS_OK)
		return st;

	st = vec_mod(vec2, &mod2);

	if (st != DS_OK)
		return st;

	*result = acos(dot / (mod1 * mod2));

	return DS_OK;
}

/**
 * @brief Copies a @c Vector
 *
 * @param[in] vec Reference to @c Vector to be copied
 * @param[out] result Copied @c Vector
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if @c vec parameter is @c NULL
 */
Status vec_copy(Vector *vec, Vector **result)
{
	if (vec == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = vec_build(vec->x, vec->y, vec->z, result);

	if (st != DS_OK)
		return st;

	return DS_OK;
}