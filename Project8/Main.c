#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
struct DList
{
	float value;
	struct DList* prev;
	struct DList* next;
};
typedef struct DList DLIST;







void outputToRight(DLIST *head)
{
	printf("Вывод с начала: ");
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
	printf("Вывод с конца: ");
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



void addBeforeCurrent(DLIST *current, int value_)
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



void swapTwoElement(DLIST *list1, DLIST *list2)
{
	float n;
	n = list1->value;
	list1->value = list2->value;
	list2->value = n;
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
		if (head->value == n)
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



DLIST* splice(DLIST* left, DLIST* right, DLIST* position)
{
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



int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	float n, newn, pos;
	int i, m;

	DLIST *head = (DLIST*)malloc(sizeof(DLIST)), *tail = (DLIST*)malloc(sizeof(DLIST));
	head->value = 1 + rand() % 100;
	head->value = 1 / head->value;
	head->value = -100 + rand() % 102 + head->value;
	head->next = tail;
	head->prev = 0;
	tail->value = 1 + rand() % 100;
	tail->value = 1 / tail->value;
	tail->value = rand() % 100 + tail->value;
	tail->prev = head;
	tail->next = 0;


	for (i = 0; i < 2; i++)
	{
		tail = addToRight(tail);
	}
	for (i = -1; i > -4; i--)
	{
		head = addToLeft(head);
	}
	outputToRight(head);
	outputToLeft(tail);

	printf("\n");
	printf("Введите 1, чтобы запустить функцию addBeforeValue.\n");
	printf("Введите 2, чтобы запустить функцию addBeforeCurrent.\n");
	printf("Введите 3, чтобы запустить функцию deleteByValue.\n");
	printf("Введите 4, чтобы запустить функцию deleteByPointer.\n");
	printf("Введите 5, чтобы запустить функцию swapTwoElement.\n");
	printf("Введите 6, чтобы запустить функцию splice.\n");
	scanf_s("%d", &m);
	switch (m)
	{
	case 1:
		printf("Введите число перед которым появиться число:\n");
		scanf_s("%f", &n);
		newn = 1 + rand() % 100;
		newn = 1 / newn;
		newn = -100 + rand() % 102 + newn;
		if (n == head->value)
		{
			DLIST* curr = (DLIST*)malloc(sizeof(DLIST));
			curr->value = newn;
			curr->prev = NULL;
			curr->next = head;
			head->next->prev = curr;
			head = curr;
			m = 0;
			outputToRight(head);
			outputToLeft(tail);
		}
		else
		{
			m = 1;
		}
		if (m == 1)
		{
			m = Proverka(head, n);
			if (m == 1)
			{
				addBeforeValue(head, n, newn);
				outputToRight(head);
				outputToLeft(tail);
			}
			else
			{
				printf("Нет такого числа!\n");
			}
		}
		break;
	case 2:
		printf("Введите число перед которым появиться число:\n");
		scanf_s("%f", &n);
		newn = 1 + rand() % 100;
		newn = 1 / newn;
		newn = -100 + rand() % 102 + newn;
		if (n == head->value)
		{
			DLIST* curr = (DLIST*)malloc(sizeof(DLIST));
			curr->value = newn;
			curr->prev = NULL;
			curr->next = head;
			head->next->prev = curr;
			head = curr;
			m = 0;
			outputToRight(head);
			outputToLeft(tail);
		}
		else
		{
			m = 1;
		}
		if (m == 1)
		{
			m = Proverka(head, n);
			if (m == 1)
			{
				addBeforeCurrent(findByValue(head, n), newn);
				outputToRight(head);
				outputToLeft(tail);
			}
			else
			{
				printf("Нет такого числа!\n");
			}
		}
		break;
	case 3:
		printf("Введите число, которое хотите удалить:\n");
		scanf_s("%f", &n);
		m = Proverka(head, n);
		if (m == 1)
		{
			DLIST *P, *A1, *A2;
			A1 = head->next;
			A2 = tail->prev;
			P = deleteByValue(head, n);
			if (P != NULL && P == A1)
			{
				head = P;
			}
			if (P != NULL && P == A2)
			{
				tail = P;
			}
			outputToRight(head);
			outputToLeft(tail);
		}
		else
		{
			printf("Нет такого числа!\n");
		}
		break;
	case 4:
		printf("Введите число, которое хотите удалить:\n");
		scanf_s("%f", &n);
		m = Proverka(head, n);
		if (m == 1)
		{
			DLIST *P, *A1, *A2;
			A1 = head->next;
			A2 = tail->prev;
			P = deleteByPointer(findByValue(head, n));
			if (P != NULL && P == A1)
			{
				head = P;
			}
			if (P != NULL && P == A2)
			{
				tail = P;
			}
			outputToRight(head);
			outputToLeft(tail);
		}
		else
		{
			printf("Нет такого числа!\n");
		}
		break;
	case 5:
		printf("Введите 2 числа, которые хотите поменять местами.\n");
		scanf_s("%f", &n);
		scanf_s("%f", &newn);
		m = Proverka(head, n);
		if(m != 1)
		{
			printf("Нет такого числа!\n");
			system("pause");
			exit(1);
		}
		m = Proverka(head, newn);
		if (m != 1)
		{
			printf("Нет такого числа!\n");
			system("pause");
			exit(1);
		}
		swapTwoElement(findByValue(head, n), findByValue(head, newn));
		outputToRight(head);
		outputToLeft(tail);
		break;
	case 6:
		DLIST *head2 = (DLIST*)malloc(sizeof(DLIST)), *tail2 = (DLIST*)malloc(sizeof(DLIST));
		head2->value = 1 + rand() % 100;
		head2->value = 1 / head2->value;
		head2->value = -100 + rand() % 102 + head2->value;
		head2->next = tail2;
		head2->prev = 0;
		tail2->value = 1 + rand() % 100;
		tail2->value = 1 / tail2->value;
		tail2->value = rand() % 100 + tail2->value;
		tail2->prev = head2;
		tail2->next = 0;

		printf("Второй список:\n");
		for (i = 0; i < 1; i++)
		{
			tail2 = addToRight(tail2);
		}
		for (i = -1; i > -2; i--)
		{
			head2 = addToLeft(head2);
		}
		outputToRight(head2);
		outputToLeft(tail2);

		printf("Введите число, после которого будет вырезан список.\n");
		scanf_s("%f", &n);
		printf("Введите число, до которого будет вырезан список.\n");
		scanf_s("%f", &newn);
		printf("Введите число, после которого будет вставлена часть первого списка во второй список.\n");
		scanf_s("%f", &pos);
		m = Proverka(head, n);
		if (m != 1)
		{
			printf("Нет такого числа!\n");
			system("pause");
			exit(1);
		}
		m = Proverka(head, newn);
		if (m != 1)
		{
			printf("Нет такого числа!\n");
			system("pause");
			exit(1);
		}
		m = Proverka(head2, pos);
		if (m != 1)
		{
			printf("Нет такого числа!\n");
			system("pause");
			exit(1);
		}
		DLIST *P;
		P = splice(findByValue(head, n), findByValue(head, newn), findByValue(head2, pos));
		if (P != NULL)
		{
			tail2 = P;
		}
		printf("Первый список:\n");
		outputToRight(head);
		outputToLeft(tail);
		printf("Второй список:\n");
		outputToRight(head2);
		outputToLeft(tail2);
		break;
	}
	system("pause");
	return 0;
}