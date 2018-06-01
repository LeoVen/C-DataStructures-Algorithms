/**
 * @file Vector.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/03/2018
 *
 * @brief Header file for @c Vector implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "Core.h"

	typedef struct Vector {
		double x;
		double y;
		double z;
		struct Basis *base;
	} Vector;
	
	typedef struct Basis {
		struct SimpleVector *i;
		struct SimpleVector *j;
		struct SimpleVector *k;
	} Basis;

	typedef struct SimpleVector {
		double x;
		double y;
		double z;
	} SimpleVector;

	Status vec_build(double x, double y, double z, Vector **vec);
	Status vec_build_simple(double x, double y, double z, SimpleVector **vec);

	Status vec_display(Vector *vec);
	
	Status vec_mod(Vector *vec, double *result);

	Status vec_sum(Vector *vec1, Vector *vec2, Vector **result);
	Status vec_subtract(Vector *vec1, Vector *vec2, Vector **result);

	Status vec_product_scalar(Vector *vec, double scalar);
	Status vec_product_dot(Vector *vec1, Vector *vec2, double *result);

	Status vec_angle(Vector *vec1, Vector *vec2, double *result);
	// Cross Product

	Status vec_copy(Vector *vec, Vector **result);

#ifdef __cplusplus
}
#endif