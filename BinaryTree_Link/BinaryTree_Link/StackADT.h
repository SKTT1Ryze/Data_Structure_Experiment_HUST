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
	//构造一个空栈
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
	//若栈不为空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR		
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
	//插入元素e为新的栈顶元素
	if (S.top - S.base >= S.stacksize)
	{
		//栈满，追加存储空间
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
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
	if (S.top == S.base)
	{
		printf("*Stack is Empty\n");
		return ERROR;
	}
	e = *--S.top;
	return OK;
}//Pop




