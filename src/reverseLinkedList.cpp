/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (!head)
	{
		return NULL;
	}

	struct node *temp1, *temp2, *temp3 = NULL;
	temp1 = head;
	while (temp1 != NULL)
	{
		temp2 = temp3;
		temp3 = temp1;
		temp1 = temp1->next;
		temp3->next = temp2;
	}
	head = temp3;

	return head;
}
