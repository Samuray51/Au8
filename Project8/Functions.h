#ifndef _Functions_H_
#define  _Functions_H_
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


void outputToRight(DLIST *head);
void outputToLeft(DLIST *tail);
DLIST* addToRight(DLIST *tail);
DLIST* addToLeft(DLIST *head);
void addBeforeValue(DLIST *head, float value_, float newValue);
void addBeforeCurrent(DLIST *current, float value_);
DLIST* deleteByPointer(DLIST *head);
DLIST* swapTwoElement(DLIST *list1, DLIST *list2, DLIST *head, DLIST *tail);
DLIST* findByValue(DLIST *head, float value_);
int Proverka(DLIST *head, float n);
DLIST* deleteByValue(DLIST *head, float value_);
DLIST* splice(DLIST* left, DLIST* right, DLIST* position);
#endif



