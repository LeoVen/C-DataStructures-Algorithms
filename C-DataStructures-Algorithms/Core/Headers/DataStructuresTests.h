/**
 * @file DataStructuresTests.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/03/2018
 *
 * @brief Header to Include Structure Test Functions in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	int SinglyLinkedListTests(void);
	int DoublyLinkedListTests(void);
	int CircularLinkedListTests(void);
	int SparseMatrixTests(void);

	int StackTests(void);
	//int StaticStackTests();

	int QueueTests(void);
	int DequeTests(void);
	int PriorityQueueTests(void);
	int CircularBufferTests(void);

	int BinaryTreeTests(void);
	int BinarySearchTreeTests(void);
	int AVLTreeTests(void);

	int ArrayTests(void);
	int DynamicArrayTests(void);

	int VectorTests(void);

	int StructureConversionsTests(void);

	int StringTests(void);

	int SortingTests(void);

#ifdef __cplusplus
}
#endif