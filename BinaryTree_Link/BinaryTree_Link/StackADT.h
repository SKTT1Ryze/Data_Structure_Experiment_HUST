#pragma once
//Stack ADT
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"BinaryTree_Link.h"
//define return value
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int status;
typedef BiTPos SElemType;//type of data

typedef struct//define of Stack Struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

status InitStack(SqStack&S);
status GetTop(SqStack&S, SElemType&e);
status Push(SqStack&S, SElemType e);
status Pop(SqStack&S, SElemType&e);

status InitStack(SqStack&S)
{
	//����һ����ջ
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack
status StackEmpty(SqStack&S)
{
	if (S.base == S.top)
	{
		printf("*Empty\n");
		return TRUE;
	}
	else
	{
		printf("*Not Empty\n");
		return FALSE;
	}
}


status GetTop(SqStack&S, SElemType&e)
{
	//��ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR		
	if (S.top == S.base)
	{
		printf("*Stack is Empty\n");
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}//GetTop

status Push(SqStack&S, SElemType e)
{
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize)
	{
		//ջ����׷�Ӵ洢�ռ�
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}//Push

status Pop(SqStack&S, SElemType&e)
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if (S.top == S.base)
	{
		printf("*Stack is Empty\n");
		return ERROR;
	}
	e = *--S.top;
	return OK;
}//Pop




