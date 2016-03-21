/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>
struct node * createNode(int num);
struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 0)
	{
		return NULL;
	}
	struct node *h = head, *s = head->next;
	struct node *temp;
	int i = 1;
	//printf(" head is at %d\n", h->num);
	//printf(" second  is at %d\n", s->num);
	while (s)
	{
		if (i%K == 0)
		{
			temp = createNode(K);
			h->next = temp;
			temp->next = s;

		}
		i++;
		h = s;
		s = s->next;

	}
	if (i%K == 0)
	{

		temp = createNode(K);
		h->next = temp;
	}



	return head;
}

struct node * createNode(int num)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}
