/**
 * @file StructureConversions.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 02/04/2018
 *
 * @brief Structure Conversions Header in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"
#include "..\Core\Structures.h"

	// +-------------------------------------+
	// |              SLL -> X               |
	// +-------------------------------------+
	Status convert_sll_to_arr(SinglyLinkedList *sll, Array **array);

	Status convert_sll_to_darr(SinglyLinkedList *sll, DynamicArray **darr);

	// +-------------------------------------+
	// |              DAR -> X               |
	// +-------------------------------------+

	Status convert_darr_to_sll(DynamicArray **darr, SinglyLinkedList **sll);

	// +-------------------------------------+
	// |              AAR -> X               |
	// +-------------------------------------+

	Status convert_arr_to_darr(Array *arr, DynamicArray **darr);

#ifdef __cplusplus
}
#endif