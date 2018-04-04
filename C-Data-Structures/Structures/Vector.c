/*
* Vector.c
*
* Author: Leonardo Vencovsky
* Created on 20/03/2018
*
* Vector implementations
*
*/

#include "..\Headers\Vector.h"



int buildNormalVector(double x, double y, double z, Vector **v)
{
	(*v) = malloc(sizeof(Vector));
	(*v)->x = x;
	(*v)->y = y;
	(*v)->z = z;
	(*v)->base = malloc(sizeof(Basis));
	buildSimpleVector(1, 0, 0, &((*v)->base->i));
	buildSimpleVector(0, 1, 0, &((*v)->base->j));
	buildSimpleVector(0, 0, 1, &((*v)->base->k));
	return 0;
}

int buildSimpleVector(double x, double y, double z, SimpleVector **v)
{
	(*v) = malloc(sizeof(SimpleVector));
	(*v)->x = x;
	(*v)->y = y;
	(*v)->z = z;
	return 0;
}

void displayVector(Vector *v)
{
	printf("\nVector\n[%8.2lf i ]\n[%8.2lf j ]\n[%8.2lf k ]", v->x, v->y, v->z);
	printf("\nBase\n[%4.2lf, %4.2lf, %4.2lf], [%4.2lf, %4.2lf, %4.2lf], [%4.2lf, %4.2lf, %4.2lf]\n",
		v->base->i->x, v->base->i->y, v->base->i->z,
		v->base->j->x, v->base->j->y, v->base->j->z,
		v->base->k->x, v->base->k->y, v->base->k->z);
}

Vector* vectorSum(Vector *v1, Vector *v2)
{
	Vector *v;
	buildNormalVector(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z, &v);
	return v;
}

Vector* vectorSubtraction(Vector *v1, Vector *v2)
{
	Vector *v;
	buildNormalVector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z, &v);
	return v;
}

double vectorModulus(Vector *v)
{
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

double vectorDotProduct(Vector *v1, Vector *v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void vectorScalarProduct(Vector *v, double scalar)
{
	v->x *= scalar;
	v->y *= scalar;
	v->z *= scalar;
}

double vectorAngle(Vector *v1, Vector *v2)
{
	return acos(vectorDotProduct(v1, v2) / (vectorModulus(v1) * vectorModulus(v2)));
}

Vector* copyVector(Vector *v)
{
	Vector *newVec;
	buildNormalVector(v->x, v->y, v->z, &newVec);
	return newVec;
}