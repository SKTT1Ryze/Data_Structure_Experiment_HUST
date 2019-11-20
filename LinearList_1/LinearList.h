#include <iostream>
//数据结构试验一
//线性表顺序存储ADT定义
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//函数结果状态代码 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;//数据元素定义

#define LIST_INIT_SIZE 100//线性表初始容量大小
#define LISTINCREMENT 10//每次增加的表容量大小

typedef struct
{
	//顺序表（顺序存储）的定义
	ElemType*elem;//数据元素 
	int length;//表当前的长度 
	int listsize; //表当前容量 
} SqList,*SqListP;

//函数声明 
status InitList(SqListP L);
status DestroyList(SqListP L);
status ClearList(SqListP L);
status ListEmpty(SqListP L);
int ListLength(SqListP L);
status GetElem(SqListP L,int i,ElemType* e);
int LocateElem(SqListP L,ElemType e,int(*compare)(ElemType x,ElemType e)); 
status PriorElem(SqListP L,ElemType cur,ElemType*pre_e);
status NextElem(SqListP L,ElemType cur,ElemType*next_e);
status ListInsert(SqListP L,int i,ElemType e);
status ListDelete(SqListP L,int i,ElemType* e);
status ListTrabverse(SqListP L,void(*visit)(ElemType*e));
status ListSet(SqListP L);

status InitList(SqListP L)
{
	//构造一个空的线性表L
	if(L->elem!=NULL)//判断L是否存在 
	{
		printf("线性表存在\n");
		return ERROR;
	}
	//对L->elem分配存储空间 
	L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem)exit(OVERFLOW);//存储分配失败
	L->length=0;//空表长度为0
	L->listsize=LIST_INIT_SIZE;//初始化存储容量
	return OK;//创建空表成功	 
}//InitList

status DestoryList(SqListP L)
{ 
	//删除一个线性表L
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	free(L->elem);//删除表
	L->elem=NULL; 
	return OK;
}//DestoryList

status ClearList(SqListP L)
{
	//将L重置为空表
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	} 
	L->length=0;//表长重置为0 
	return OK;
}//ClearList

status ListEmpty(SqListP L)
{
	//判定是否为空表 
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	if(L->length==0)return TRUE;//判断表是否为空 
	else return FALSE;
} 

int ListLength(SqListP L)
{
	//返回L中数据元素的个数
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	return L->length;//返回表L的长度 
}

status GetElem(SqListP L,int i,ElemType* e)
{
	//用e返回L中第i个数据元素的值
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	//i的合法值为1<=i<=L->length
	if(i<1||i>L->length)//i值不合法 
	{
		printf("OVERFLOW");
		return ERROR;
	} 
	*e=L->elem[i-1];//将第i个数据元素赋值给*e 
	return OK;
}

int LocateElem(SqListP L,ElemType e,int(*compare)(ElemType x,ElemType e)) 
{
	//返回L中第1个与e满足关系的数据元素的位序
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	int i=0;//从表头开始遍历
	while(i<L->length&&!compare(L->elem[i],e))
		i++;//遍历
	if(i>=L->length)//满足条件的数据元素不存在
	{
		printf("满足条件的数据元素不存在\n");
		return 0;
	} 
	else return i+1;//返回位序 
} 

status PriorElem(SqListP L,ElemType cur,ElemType&pre_e)
{
	//获取前驱 
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	int i=0;
	while((i<L->length)&&(L->elem[i]!=cur))//找到cur对应的索引 
	{
		i++;
	}
	if(i==0)//cur是第一个 
	{
		printf("cur是第一个\n");
		return ERROR;
	}
	if(i>=L->length)//cur不在数据元素里面 
	{
		printf("cur不在数据元素里\n");
		return ERROR;
	}
	pre_e=L->elem[i-1];//将cur的前驱对应的指针赋值给pre_e
	return OK; 
}

status NextElem(SqListP L,ElemType cur,ElemType&next_e)
{
	//获取后驱 
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	int i=0;
	while((i<L->length)&&(L->elem[i]!=cur))//找到cur对应的索引 
	{
		i++;
	}
	if(i==(L->length-1))//cur是最后一个 
	{
		printf("cur是最后一个\n");
		return ERROR;
	}
	if(i>=L->length)//cur不在数据元素里面 
	{
		printf("cur不在数据元素里\n");
		return ERROR;
	}
	next_e=L->elem[i+1];//将cur的后驱对应的指针赋值给pre_e
	return OK; 
}

status ListInsert(SqListP L,int i,ElemType e)
{
	//在顺序线性表L中第i个位置之前插入新的元素e
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	//i的合法值为1<=i<=L->length+1
	if(i<1||i>L->length+1)//i值不合法 
	{
		printf("OVERFLOW");
		return ERROR;
	} 
	if(L->length>=L->listsize)
	{
		//当前存储空间已经满，增加分配
		ElemType* newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW);//分配内存失败
		L->elem=newbase;//新基址 
		L->listsize+=LISTINCREMENT;//增加存储容量 
	}
	ElemType* q=&(L->elem[i-1]);//q为插入位置
	for(ElemType*p=&(L->elem[L->length-1]);p>=q;--p)
		*(p+1)=*p;//插入位置及之后的元素右移
	*q=e;//插入e 
	++L->length;//表长增加1
	return OK; 
	
}//ListInsert

status ListDelete(SqListP L,int i,ElemType* e)
{
	//在顺序线性表L中删除第i个元素，并用e返回值
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	//i的合法值为1<=i<=L->length
	if(i<1||i>L->length)//i值不合法 
	{
		printf("OVERFLOW");
		return ERROR;
	}
	ElemType*p=&(L->elem[i-1]);//p为被删除元素的位置 
	*e=*p;//被删除元素的值赋给e
	ElemType*q=L->elem+L->length-1;//表尾元素的位置
	for(++p;p<=q;++p)
		*(p-1)=*p;//被删除元素之后的元素左移
	--L->length;//表长减1
	return OK; 
	 
}//ListDelete

status ListTrabverse(SqListP L,void(*visit)(ElemType*e))
{
	//依次对L的每个数据元素调用函数visit()
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	int i=0;//从表头开始遍历
	while(i<(L->length))
	{
		visit(&(L->elem[i]));//对每个数据元素调用visit
		i++;
	} 
	printf("\n");	
	return OK; 
}
status ListSet(SqListP L)
{
	//排序 
	if(L->elem==NULL)//判断L是否存在 
	{
		printf("线性表不存在\n");
		return ERROR;
	}
	int i=0;
	int j=0;
	for(i=0;i<L->length;i++)
	{
		for(j=0;j<L->length-i;j++)
		{
			if(L->elem[j]>L->elem[j+1])
			{
				ElemType temp=L->elem[j];
				L->elem[j]=L->elem[j+1];
				L->elem[j+1]=temp;
			}
		}
	}
	return OK;
}

