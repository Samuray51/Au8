#include <stdio.h>
#include <stdlib.h>
/*
struct Complex
{
	double Re;
	double Im;
};
typedef struct Complex COMPLEX;
struct List
{
	COMPLEX entry;
	struct List* next;
};
typedef struct List LIST;
*/
struct DList
{
	int value;
	struct DList* prev;
	struct DList* next;
};
typedef struct DList DLIST;

void outputToRight(DLIST* head)
{
	printf("Output from head : ");
	while (head!=0)
	{
		if(head->next != 0)
			printf("%d ~> ", head->value);
		else
			printf("%d\n", head->value);
		head = head->next;
	}
}
void outputToLeft(DLIST* tail)
{
	printf("Output from tail : ");
	while (tail != 0)
	{
		if(tail->prev != 0)
			printf("%d ~> ", tail->value);
		else
			printf("%d\n", tail->value);
		tail = tail->prev;
	}
}
DLIST* addToRight(DLIST* tail, int value_)
{
	tail->next = (DLIST*)malloc(sizeof(DLIST));
	tail->next->value = value_;
	tail->next->next = 0;
	tail->next->prev = tail;
	return tail->next;
}
DLIST* addToLeft(DLIST* head, int value_)
{
	head->prev = (DLIST*)malloc(sizeof(DLIST));
	head->prev->value = value_;
	head->prev->next = head;
	head->prev->prev = 0;
	return head->prev;
}
///////////////////////////
void addBeforeValue(DLIST* head, int value_, int newValue)
{
	// реализовать через findByValue и addBeforeCurrent
	DLIST* tmp = head;
	while (tmp->next->value != value_)
		tmp = tmp->next;
	DLIST* curr = tmp->next;
	tmp->next = (DLIST*)malloc(sizeof(DLIST));
	tmp->next->value = newValue;
	tmp->next->prev = tmp;
	tmp->next->next = curr;
	curr->prev = tmp->next;
}
void addBeforeCurrent(DLIST* current, int value_)
{
	DLIST *currPrev = current->prev;
	currPrev->next = (DLIST*)malloc(sizeof(DLIST));
	currPrev->next->value = value_;
	currPrev->next->next = current;
	currPrev->next->prev = currPrev;
	current->prev = currPrev->next;
}
DLIST* findByValue(DLIST* head, int value_)
{
	DLIST* tmp = head;
	while (tmp->value != value_)
		tmp = tmp->next;
	return tmp;
}

int main()
{
	DLIST *head = (DLIST*)malloc(sizeof(DLIST)), *tail = (DLIST*)malloc(sizeof(DLIST));
	head->value = 0;
	head->next = tail;
	head->prev = 0;
	tail->value = 1;
	tail->prev = head;
	tail->next = 0;

	for(int i=2;i<4;++i)
		tail = addToRight(tail, i);
	for (int i = -1; i>-4; --i)
		head = addToLeft(head, i);
	outputToRight(head);
	outputToLeft(tail);

	addBeforeValue(head, 2, -100);
	addBeforeCurrent(findByValue(head, -100), -300);

	outputToRight(head);
	outputToLeft(tail);

	system("pause");
	return 0;
}