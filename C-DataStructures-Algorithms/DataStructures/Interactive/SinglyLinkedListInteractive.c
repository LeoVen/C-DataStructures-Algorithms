/**
 * @file SinglyLinkedListInteractive.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/06/2018
 *
 * @brief Interactive version of @c SinglyLinkedList implementations in C
 *
 */

#include "UserInput.h"
#include "SinglyLinkedList.h"

#define MAX_LIST_SIZE 5

int SinglyLinkedListInteractive(void)
{
	SinglyLinkedList *lists[MAX_LIST_SIZE];

	SinglyLinkedNode *nodes[MAX_LIST_SIZE];

	bool exit = false;

	int i, oper, value;

	for (i = 0; i < MAX_LIST_SIZE; i++) {
		lists[i] = NULL;
		nodes[i] = NULL;
	}

	size_t pos, position;

	while (!exit)
	{
		system(CLEAR_SCREEN);
		printf("+----------------------------------------------------------------------------------------------------+\n");
		printf("|                                        Singly Linked List                                          |\n");
		printf("+----------------------------------------------------------------------------------------------------+\n");
		printf("|                                                                                                    |\n");
		printf("| Interactive Menu --------------------------------------------------------------------------------- |\n");
		printf("| [  0] Exit                                                                                         |\n");
		printf("|                                                                                                    |\n");
		printf("| List --------------------------------------------------------------------------------------------- |\n");
		printf("| [  1] Initialize List  | [  2] Delete List      | [  3] Initialize Node  | [  4] Delete Node       |\n");
		printf("|                                                                                                    |\n");
		printf("| Insert ------------------------------------------------------------------------------------------- |\n");
		printf("| [ 11] Insert at head            | [ 12] Insert at middle            | [ 13] Insert at tail         |\n");
		printf("| [ 14] Insert node at head       | [ 15] Insert node at middle       | [ 16] Insert node at tail    |\n");
		printf("|                                                                                                    |\n");
		printf("| Remove ------------------------------------------------------------------------------------------- |\n");
		printf("| [ 21] Remove at head            | [ 22] Remove at middle            | [ 23] Remove at tail         |\n");
		printf("| [ 24] Remove node at head       | [ 25] Remove node at middle       | [ 26] Remove node at tail    |\n");
		printf("|                                                                                                    |\n");
		printf("+----------------------------------------------------------------------------------------------------+\n");

		printf("\n");

		printf("+----------------------------------------------------------------------------------------------------+\n");
		printf("| Lists                                                                                              |\n");
		printf("+----------------------------------------------------------------------------------------------------+\n");

		for (i = 0; i < MAX_LIST_SIZE; i++) {

			printf("\n[ %d ]", i);
			if (lists[i] == NULL)
				printf("\n[ NULL ]\n");
			else
				sll_display(lists[i]);
		}

		printf("\n");

		printf("+----------------------------------------------------------------------------------------------------+\n");
		printf("| Nodes                                                                                              |\n");
		printf("+----------------------------------------------------------------------------------------------------+\n");

		printf("\n");

		for (i = 0; i < MAX_LIST_SIZE; i++) {

			printf("   <%d>[ %10d ]", i, (nodes[i] == NULL) ? 0 : nodes[i]->data);
		}
		
		printf("\n");
		printf("+----------------------------------------------------------------------------------------------------+\n");

		oper = input_int("> ");

		switch (oper)
		{
		case 0:
			exit = true;
			break;
		case 1:
			pos = input_size_t("Select List > ");

			if (pos > MAX_LIST_SIZE) {
				print_status_repr(DS_ERR_INVALID_OPERATION);
				break;
			}

			print_status_repr(sll_init_list(&(lists[pos])));
			break;
		case 2:
			pos = input_size_t("Select List > ");

			if (pos > MAX_LIST_SIZE) {
				print_status_repr(DS_ERR_INVALID_OPERATION);
				break;
			}

			print_status_repr(sll_delete_list(&(lists[pos])));
			break;
		case 3:
			pos = input_size_t("Select Node > ");

			if (pos > MAX_LIST_SIZE) {
				print_status_repr(DS_ERR_INVALID_OPERATION);
				break;
			}

			value = input_int("Node value > ");

			print_status_repr(sll_make_node(&(nodes[pos]), value));
			break;
		case 4:
			pos = input_size_t("Select Node > ");

			if (pos > MAX_LIST_SIZE) {
				print_status_repr(DS_ERR_INVALID_OPERATION);
				break;
			}

			print_status_repr(sll_delete_node(&(nodes[pos])));
			break;
		case 11:
			pos = input_size_t("Select List > ");

			if (pos > MAX_LIST_SIZE) {
				print_status_repr(DS_ERR_INVALID_OPERATION);
				break;
			}

			value = input_int("Node value > ");

			print_status_repr(sll_insert_head(lists[pos], value));
			break;
		case 12:
			pos = input_size_t("Select List > ");

			if (pos > MAX_LIST_SIZE) {
				print_status_repr(DS_ERR_INVALID_OPERATION);
				break;
			}

			position = input_size_t("Node Position > ");

			value = input_int("Node value > ");

			print_status_repr(sll_insert_at(lists[pos], value, position));
		case 13:
			pos = input_size_t("Select List > ");

			if (pos > MAX_LIST_SIZE) {
				print_status_repr(DS_ERR_INVALID_OPERATION);
				break;
			}

			value = input_int("Node value > ");

			print_status_repr(sll_insert_tail(lists[pos], value));
			break;
		default:
			print_status_repr(DS_ERR_INVALID_OPERATION);
			break;
		}

		if (!exit) {
			printf("\nPress enter to continue ... ");
			_getch();
		}
	}

	for (i = 0; i < MAX_LIST_SIZE; i++) {
		sll_delete_list(&(lists[i]));
		sll_delete_node(&(nodes[i]));
	}

	printf("\n");
	return 0;
}
