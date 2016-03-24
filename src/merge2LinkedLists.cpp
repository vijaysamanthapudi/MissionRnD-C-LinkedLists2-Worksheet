/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	struct node *p1 = head1, *p2 = head2;
	while (p1->next)
	{
		p1 = p1->next;
	}
	p1->next = p2;
	
	struct node *prev = head1, *curr = head1->next;
	while (curr)
	{
		prev = head1;
		while (prev)
		{
			if (prev->num > curr->num)
			{
				int temp = prev->num;
				prev->num = curr->num;
				curr->num = temp;
			}
			prev = prev->next;

		}
		curr = curr->next;
	}
	
	return head1;
}


