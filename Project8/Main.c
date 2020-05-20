#include"Functions.h"
DLIST *Q, *W;

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	float n, newn, pos;
	int i, m;

	DLIST *head = (DLIST*)malloc(sizeof(DLIST)), *tail = (DLIST*)malloc(sizeof(DLIST));
	DLIST *head2 = (DLIST*)malloc(sizeof(DLIST)), *tail2 = (DLIST*)malloc(sizeof(DLIST));
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
	printf("������� 1, ����� ��������� ������� addBeforeValue.\n");
	printf("������� 2, ����� ��������� ������� addBeforeCurrent.\n");
	printf("������� 3, ����� ��������� ������� deleteByValue.\n");
	printf("������� 4, ����� ��������� ������� deleteByPointer.\n");
	printf("������� 5, ����� ��������� ������� swapTwoElement.\n");
	printf("������� 6, ����� ��������� ������� splice.\n");
	scanf_s("%d", &m);
	switch (m)
	{
	case 1:
		printf("������� ����� ����� ������� ��������� �����:\n");
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
				printf("��� ������ �����!\n");
			}
		}
		break;
	case 2:
		printf("������� ����� ����� ������� ��������� �����:\n");
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
				printf("��� ������ �����!\n");
			}
		}
		break;
	case 3:
		printf("������� �����, ������� ������ �������:\n");
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
			printf("��� ������ �����!\n");
		}
		break;
	case 4:
		printf("������� �����, ������� ������ �������:\n");
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
			printf("��� ������ �����!\n");
		}
		break;
	case 5:
		printf("������� 2 �����, ������� ������ �������� �������.\n");
		scanf_s("%f", &n);
		scanf_s("%f", &newn);
		m = Proverka(head, n);
		if(m != 1)
		{
			printf("��� ������ �����!\n");
			system("pause");
			exit(1);
		}
		m = Proverka(head, newn);
		if (m != 1)
		{
			printf("��� ������ �����!\n");
			system("pause");
			exit(1);
		}
		if ((findByValue(head, n) == head && findByValue(head, newn) == tail) || (findByValue(head, n) == tail && findByValue(head, newn) == head))
		{
			DLIST *next1;
			head->next->prev = tail;
			tail->prev->next = head;
			next1 = head->next;
			head->next = NULL;
			head->prev = tail->prev;
			tail->next = next1;
			tail->prev = NULL;
			next1 = head;
			head = tail;
			tail = next1;
		}
		else
		{
			if (findByValue(head, n) == head)
			{
				head = swapTwoElement(findByValue(head, n), findByValue(head, newn), head, tail);
			}
			else if(findByValue(head, newn) == head)
			{
				head = swapTwoElement(findByValue(head, n), findByValue(head, newn), head, tail);
			}
			else if (findByValue(head, n) == tail)
			{
				tail = swapTwoElement(findByValue(head, n), findByValue(head, newn), head, tail);
			}
			else if (findByValue(head, newn) == tail)
			{
				tail = swapTwoElement(findByValue(head, n), findByValue(head, newn), head, tail);
			}
			else
			{
				swapTwoElement(findByValue(head, n), findByValue(head, newn), head, tail);
			}
		}
		
		outputToRight(head);
		outputToLeft(tail);
		break;
	case 6:
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

		printf("������ ������:\n");
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

		printf("������� �����, ����� �������� ����� ������� ������.\n");
		scanf_s("%f", &n);
		printf("������� �����, �� �������� ����� ������� ������.\n");
		scanf_s("%f", &newn);
		printf("������� �����, ����� �������� ����� ��������� ����� ������� ������ �� ������ ������.\n");
		scanf_s("%f", &pos);
		m = Proverka(head, n);
		if (m != 1)
		{
			printf("��� ������ �����!\n");
			system("pause");
			exit(1);
		}
		m = Proverka(head, newn);
		if (m != 1)
		{
			printf("��� ������ �����!\n");
			system("pause");
			exit(1);
		}
		m = Proverka(head2, pos);
		if (m != 1)
		{
			printf("��� ������ �����!\n");
			system("pause");
			exit(1);
		}
		DLIST *P;
		P = splice(findByValue(head, n), findByValue(head, newn), findByValue(head2, pos));
		if (P != NULL)
		{
			tail2 = P;
		}
		printf("������ ������:\n");
		outputToRight(head);
		outputToLeft(tail);
		printf("������ ������:\n");
		outputToRight(head2);
		outputToLeft(tail2);
		break;
	}
	system("pause");
	return 0;
}