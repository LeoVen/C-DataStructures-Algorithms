/*
 * Vector.h
 *
 * Author: Leonardo Vencovsky
 * Created on 20/03/2018
 *
 * Header for Vector in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	typedef struct Vector Vector;
	typedef struct SimpleVector SimpleVector;
	typedef struct Basis Basis;

	struct Vector {
		double x;
		double y;
		double z;
		Basis *base;
	};
	
	struct Basis {
		SimpleVector *i;
		SimpleVector *j;
		SimpleVector *k;
	};

	struct SimpleVector {
		double x;
		double y;
		double z;
	};

	// +-------------------------------------+
	// |              Builders               |
	// +-------------------------------------+

	int buildNormalVector(double x, double y, double z, Vector **v);

	int buildSimpleVector(double x, double y, double z, SimpleVector **v);

	// +-------------------------------------+
	// |             Operations              |
	// +-------------------------------------+
	/* Vector Modulus or Magnitude or Absolute Value
	 *
	 * @Param [ Vector *v ] Vector to calculate its modulus
	 *
	 * @Returns [ double ] Modulus of vector
	 */
	double vectorModulus(Vector *v);

	/* Sum two vectors
	 *
	 * @Param [ Vector *v1 ] First vector
	 * @Param [ Vector *v2 ] Second vector
	 *
	 * @Returns [ Vector * ] Pointer to new vector that corresponds to the sum of
	 *                       first and second vectors
	 */
	Vector* vectorSum(Vector *v1, Vector *v2);

	/* Subtract second vector onto the first
	 *
	 * @Param [ Vector *v1 ] First vector
	 * @Param [ Vector *v2 ] Second vector
	 *
	 * @Returns [ Vector * ] Pointer to new vector that corresponds to the
	 *                       subtraction of the second vector onto the first
	 */
	Vector* vectorSubtraction(Vector *v1, Vector *v2);

	/* Performs a scalar product
	 *
	 * @Param [ Vector *v1 ] First vector
	 * @Param [ double scalar ] Scalar value
	 *
	 * @Returns [ int ] 
	 */
	void vectorScalarProduct(Vector *v, double scalar);

	/* Performs a dot product between vectors 1 and 2
	 *
	 * @Param [ Vector *v1 ] First vector
	 * @Param [ Vector *v2 ] Second vector
	 *
	 * @Returns [ double ] Dot product value
	 */
	double vectorDotProduct(Vector *v1, Vector *v2);

	/* Performs a dot product between vectors 1 and 2
	 *
	 * @Param [ Vector *v1 ] First vector
	 * @Param [ Vector *v2 ] Second vector
	 *
	 * @Returns [ double ] Dot product value
	 */
	double vectorAngle(Vector *v1, Vector *v2);
	// Cross Product

	// +-------------------------------------+
	// |                Misc                 |
	// +-------------------------------------+

	void displayVector(Vector *v);


	Vector* copyVector(Vector *v);

#ifdef __cplusplus
}
#endif