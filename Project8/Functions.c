#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct DList
{
	float value;
	struct DList* prev;
	struct DList* next;
};
typedef struct DList DLIST;



void outputToRight(DLIST *head)
{
	printf("Output from head: ");
	while (head != 0)
	{
		if (head->next != 0)
		{
			printf("%.8f -> ", head->value);
		}
		else
		{
			printf("%.8f\n", head->value);
		}
		head = head->next;
	}
}



void outputToLeft(DLIST *tail)
{
	printf("Output from tail: ");
	while (tail != 0)
	{
		if (tail->prev != 0)
		{
			printf("%.8f -> ", tail->value);
		}
		else
		{
			printf("%.8f\n", tail->value);
		}
		tail = tail->prev;
	}
}



DLIST* addToRight(DLIST *tail)
{
	tail->next = (DLIST*)malloc(sizeof(DLIST));
	tail->next->value = 1 + rand() % 100;
	tail->next->value = 1 / tail->next->value;
	tail->next->value = -100 + rand() % 102 + tail->next->value;
	tail->next->next = 0;
	tail->next->prev = tail;
	return tail->next;
}



DLIST* addToLeft(DLIST *head)
{
	head->prev = (DLIST*)malloc(sizeof(DLIST));
	head->prev->value = 1 + rand() % 100;;
	head->prev->value = 1 / head->prev->value;
	head->prev->value = -100 + rand() % 102 + head->prev->value;
	head->prev->next = head;
	head->prev->prev = 0;
	return head->prev;
}



void addBeforeValue(DLIST *head, float value_, float newValue)
{
	DLIST* tmp = head;
	while (tmp->next->value != value_)
	{
		tmp = tmp->next;
	}
	DLIST* curr = tmp->next;
	tmp->next = (DLIST*)malloc(sizeof(DLIST));
	tmp->next->value = newValue;
	tmp->next->prev = tmp;
	tmp->next->next = curr;
	curr->prev = tmp->next;
}



void addBeforeCurrent(DLIST *current, float value_)
{
	DLIST *currPrev = current->prev;
	currPrev->next = (DLIST*)malloc(sizeof(DLIST));
	currPrev->next->value = value_;
	currPrev->next->next = current;
	currPrev->next->prev = currPrev;
	current->prev = currPrev->next;
}



DLIST* deleteByPointer(DLIST *head)
{
	DLIST *p;
	p = NULL;
	DLIST *prev, *next;
	prev = head->prev;
	next = head->next;
	if (prev != NULL)
	{
		prev->next = head->next;
	}
	else
	{
		p = next;
	}
	if (next != NULL)
	{
		next->prev = head->prev;
	}
	else
	{
		p = prev;
	}
	free(head);
	return p;
}



DLIST* swapTwoElement(DLIST *list1, DLIST *list2, DLIST *head, DLIST *tail)
{
	DLIST *prev1, *prev2, *next1, *next2, *p = NULL;
	if (list1 == head)
	{
		p = list2;
	}
	if (list2 == head)
	{
		p = list1;
	}
	if (list1 == tail)
	{
		p = list2;
	}
	if (list2 == tail)
	{
		p = list1;
	}
	prev1 = list1->prev;
	prev2 = list2->prev;
	next1 = list1->next;
	next2 = list2->next;
	if (list2 == next1)
	{
		list2->next = list1;
		list2->prev = prev1;
		list1->next = next2;
		list1->prev = list2;
		if (next2 != NULL)
			next2->prev = list1;
		if (list1 != head)
			prev1->next = list2;
	}
	else if (list1 == next2)  // обмениваются соседние узлы
	{
		list1->next = list2;
		list1->prev = prev2;
		list2->next = next1;
		list2->prev = list1;
		if (next1 != NULL)
			next1->prev = list2;
		if (list2 != head)
			prev2->next = list1;
	}
	else
	{
		if (list1 != head)
		{
			prev1->next = list2;
		}
		list2->next = next1;
		if (list2 != head)
		{
			prev2->next = list1;
		}
		list1->next = next2;
		list2->prev = prev1;
		if (next2 != NULL)
		{
			next2->prev = list1;
		}
		list1->prev = prev2;
		if (next1 != NULL)
		{
			next1->prev = list2;
		}
	}
	return p;
}



DLIST* findByValue(DLIST *head, float value_)
{
	DLIST* tmp = head;
	while (tmp->value != value_)
	{
		tmp = tmp->next;
	}
	return tmp;
}



int Proverka(DLIST *head, float n)
{
	int k = 0;
	while (1)
	{
		if (head->value - n == 0)
		{
			k = 1;
			break;
		}
		if (head->next == 0)
		{
			break;
		}
		head = head->next;
	}
	return k;
}



DLIST* deleteByValue(DLIST *head, float value_)
{
	DLIST *p;
	p = NULL;
	while (head->value != value_)
	{
		head = head->next;
	}
	DLIST *prev, *next;
	prev = head->prev;
	next = head->next;
	if (prev != NULL)
	{
		prev->next = head->next;
	}
	else
	{
		p = next;
	}
	if (next != NULL)
	{
		next->prev = head->prev;
	}
	else
	{
		p = prev;
	}
	free(head);
	return p;
}



DLIST* splice(DLIST *one, DLIST* left, DLIST* right,DLIST *two, DLIST* position)
{
	int m;
	DLIST *one1, *two1;
	one1 = one;
	two1 = two;
	while (one1 != NULL)
	{
		if (one1->next == position)
		{
			m = 0;
			break;
		}
		if (one1->next == left)
		{
			m = 0;
		}
		if (one1->next == right)
		{
			m = 1;
		}
		one1 = one1->next;
	}
	while (two1 != NULL)
	{
		if (two1->next == left || two1->next == right)
		{
			m = 0;
			break;
		}
		two1 = two1->next;
	}
	if (m == 0)
	{
		printf("Incorrectly submitted parameters!\n");
		system("pause");
		exit(1);
	}
	if (left->next == right)
	{
		return NULL;
	}
	else
	{
		DLIST *p = NULL;
		if (position->next != NULL)
		{
			right->prev->next = position->next;
			left->next->prev = position;
			position->next->prev = right->prev;
			position->next = left->next;
			left->next = right;
			right->prev = left;
		}
		else
		{
			p = right->prev;
			right->prev->next = NULL;
			left->next->prev = position;
			position->next = left->next;
			left->next = right;
			right->prev = left;
		}
		return p;
	}
}

