#pragma once
//LinearList_chain head file
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//define return value
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;//type of data

typedef struct LNode//define of ADT
{
	ElemType data;//data area
	struct LNode *next;//pointer area
}LNode,*LinkList;


//Functions Declaration
status InitList(LinkList &L);
status DestroyList(LinkList &L);
status ClearList(LinkList &L);
status ListEmpty(LinkList &L);
int ListLength(LinkList &L);
status GetElem(LinkList &L, int i, ElemType&e);
status LocateElem(LinkList &L, ElemType e, int(*compare)(ElemType x, ElemType e));
status PriorElem(LinkList &L, ElemType cur, ElemType&pre_e);
status NextElem(LinkList &L, ElemType cur, ElemType&next_e);
status ListInsert(LinkList &L, int i, ElemType e);
status ListDelete(LinkList &L, int i, ElemType&e);
status ListTraverse(LinkList &L, void(*visit)(ElemType e));
status ListSort(LinkList &L);
status ListMerger(LinkList &La, LinkList &Lb, LinkList &Lc);

status InitList(LinkList &L)
{
	//Init a LinearList
	if (L != NULL)
	{
		printf("*LinearList is not null\n");
		return ERROR;
	}
	L = (LinkList)malloc(sizeof(LNode));
	L->data = 0;//initialize
	L->next = NULL;
	return OK;
}//InitList

status DestroyList(LinkList &L)
{
	//Destroy the LinearList
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	ClearList(L);//reset
	free(L);
	L = NULL;
	return OK;
}//DestroyList

status ClearList(LinkList &L)
{
	//Reset the LinearList
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	if (L->next == NULL)
	{
		printf("*This is a null list\n");
		return ERROR;
	}
	LinkList pos, temp;
	pos = L->next;//pos is the first node
	while (pos)
	{
		temp = pos->next;
		free(pos);
		pos = temp;
	}
	L->next = NULL;
	L->data = 0;
	return OK;
}//ClearList

status ListEmpty(LinkList &L)
{
	//judge the LinearList null or not
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	if (L->data > 0)return FALSE;
	else return TRUE;
}//ListEmpty

int ListLength(LinkList &L)
{
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	return L->data;
}//ListLength

status GetElem(LinkList &L, int i, ElemType&e)
{
	//Get the No.i element in LinearList
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	LinkList p = L->next; int j = 1;//initialize
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)//No.i element do not exist
	{
		printf("*No.i element do not exist\n");
		return ERROR;
	}
	e = p->data;
	return OK;
}//GetElem

int LocateElem(LinkList &L, ElemType e, int(*compare)(ElemType x, ElemType e))
{
	//find the first element has the relationship "compare" with e
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	int i = 1;
	LinkList pos = L->next;//initialize
	while (pos && (compare(pos->data, e) == 0))
	{
		pos = pos->next;
		i++;
	}
	if (pos == NULL)//such element in LinearList do not exist
	{
		printf("*such element in LinearList do not exist\n");
		return 0;
	}
	return i;
}//LocateElem

status PriorElem(LinkList &L, ElemType cur, ElemType&pre_e)
{
	//Get the pre element of cur
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	if (L->next == NULL)
	{
		printf("*LinearList is null\n");
		return ERROR;
	}
	if (L->next->next == NULL)
	{
		printf("*LinearList has only one element\n");
		return ERROR;
	}
	if (L->next->data == cur)
	{
		printf("*cur is the first element\n");
		return ERROR;
	}
	LinkList pos = L->next;
	while (pos->next && (pos->next->data != cur))
		pos = pos->next;
	if (pos->next == NULL)
	{
		printf("*cur is not in LinearList\n");
		return ERROR;
	}
	pre_e = pos->data;
	return OK;
}//PriorElem

status NextElem(LinkList &L, ElemType cur, ElemType&next_e)
{
	//Get the pre element of cur
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	if (L->next == NULL)
	{
		printf("*LinearList is null\n");
		return ERROR;
	}
	if (L->next->next == NULL)
	{
		printf("*LinearList has only one element\n");
		return ERROR;
	}
	LinkList pos = L->next;//initialize
	while (pos && (pos->data != cur))
		pos = pos->next;
	if (pos == NULL)
	{
		printf("*cur is not in LinearList\n");
		return ERROR;
	}
	if (pos->next == NULL)
	{
		printf("*cur is the last element\n");
		return ERROR;
	}
	next_e = pos->next->data;
	return OK;
}//NextElem

status ListInsert(LinkList &L, int i, ElemType e)
{
	//Insert an element into the LinearList
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	if (i<1 || i>L->data+1)
	{
		printf("*the value of i is overflow\n");
		return ERROR;
	}
	LinkList pos = L; int j = 0;//initialize
	while (pos&&j < i - 1)//to find the No.i-1 Node
	{
		pos = pos->next;
		++j;
	}
	LinkList newNode = (LinkList)malloc(sizeof(LNode));//generate new node
	newNode->next = NULL;
	newNode->data = e;
	newNode->next = pos->next;
	pos->next = newNode;
	L->data++;//Length add 1
	return OK;
}//ListInsert

status ListDelete(LinkList &L, int i, ElemType&e)
{
	//Delete No.i element of LinearList,return by e
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	if (i<1 || i>L->data)
	{
		printf("*the value of i is overflow\n");
		return ERROR;
	}
	LinkList pos = L;//initialize
	int j = 0;
	while (pos->next&&j < i - 1)//to find the No.i node,pos point to its pre_node
	{
		pos = pos->next;
		++j;
	}
	LinkList temp = pos->next;
	pos->next = temp->next;
	e = temp->data;
	free(temp);
	L->data--;
	return OK;
}//ListDelete

status ListTraverse(LinkList &L, void(*visit)(ElemType e))
{
	//Travel the LinearList
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	LinkList pos = L->next;//initialize
	while (pos)
	{
		visit(pos->data);//call visit()
		pos = pos->next;
	}
	printf("\n");
	return OK;
}//ListTraverse

status ListSort(LinkList &L)
{
	//sort the LinearList
	//Error Alarm
	if (L == NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	int i, j;
	LinkList temp;
	for (i = 0; i < L->data-1; i++)
	{
		for (j = 0, temp = L->next; j < L->data - i-1; j++)
		{
			if (temp->data > temp->next->data)
			{
				ElemType x = temp->data;
				temp->data = temp->next->data;
				temp->next->data = x;
			}
			temp = temp->next;
		}

	}
	return OK;
}//ListSort

status ListMerger(LinkList &La, LinkList &Lb, LinkList &Lc)
{
	//Merge two LinearList as a new one
	//Error Alarm
	if (La== NULL||Lb==NULL||Lc==NULL)
	{
		printf("*The LinearList do not exist\n");
		return ERROR;
	}
	Lc->data = La->data + Lb->data;//compute length
	LinkList temp,pos,semp_a,semp_b;
	pos = Lc;
	semp_a = La->next;
	semp_b = Lb->next;
	for (int i = 0; i < La->data; i++)//call for space
	{
		temp = (LinkList)malloc(sizeof(LNode));
		if (temp == NULL)
		{
			printf("*Space Call Error\n");
			return ERROR;
		}
		temp->next = NULL;
		temp->data = semp_a->data;
		pos->next = temp;
		pos = pos->next;
		semp_a = semp_a->next;
	}
	for (int i = 0; i < Lb->data; i++)//add element
	{
		temp = (LinkList)malloc(sizeof(LNode));
		if (temp == NULL)
		{
			printf("*Space Call Error\n");
			return ERROR;
		}
		temp->next = NULL;
		temp->data = semp_b->data;
		pos->next = temp;
		pos = pos->next;
		semp_b = semp_b->next;
	}
	printf("*ListMerge Success\n");
	if (ListSort(Lc) == OK)//ListSort
		return OK;
	else
		return ERROR;
}

































