#include <iostream>
//���ݽṹ����һ
//���Ա�˳��洢ADT����
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//�������״̬���� 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;//����Ԫ�ض���

#define LIST_INIT_SIZE 100//���Ա��ʼ������С
#define LISTINCREMENT 10//ÿ�����ӵı�������С

typedef struct
{
	//˳���˳��洢���Ķ���
	ElemType*elem;//����Ԫ�� 
	int length;//��ǰ�ĳ��� 
	int listsize; //��ǰ���� 
} SqList,*SqListP;

//�������� 
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
	//����һ���յ����Ա�L
	if(L->elem!=NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա����\n");
		return ERROR;
	}
	//��L->elem����洢�ռ� 
	L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem)exit(OVERFLOW);//�洢����ʧ��
	L->length=0;//�ձ���Ϊ0
	L->listsize=LIST_INIT_SIZE;//��ʼ���洢����
	return OK;//�����ձ�ɹ�	 
}//InitList

status DestoryList(SqListP L)
{ 
	//ɾ��һ�����Ա�L
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	free(L->elem);//ɾ����
	L->elem=NULL; 
	return OK;
}//DestoryList

status ClearList(SqListP L)
{
	//��L����Ϊ�ձ�
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	} 
	L->length=0;//������Ϊ0 
	return OK;
}//ClearList

status ListEmpty(SqListP L)
{
	//�ж��Ƿ�Ϊ�ձ� 
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	if(L->length==0)return TRUE;//�жϱ��Ƿ�Ϊ�� 
	else return FALSE;
} 

int ListLength(SqListP L)
{
	//����L������Ԫ�صĸ���
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	return L->length;//���ر�L�ĳ��� 
}

status GetElem(SqListP L,int i,ElemType* e)
{
	//��e����L�е�i������Ԫ�ص�ֵ
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	//i�ĺϷ�ֵΪ1<=i<=L->length
	if(i<1||i>L->length)//iֵ���Ϸ� 
	{
		printf("OVERFLOW");
		return ERROR;
	} 
	*e=L->elem[i-1];//����i������Ԫ�ظ�ֵ��*e 
	return OK;
}

int LocateElem(SqListP L,ElemType e,int(*compare)(ElemType x,ElemType e)) 
{
	//����L�е�1����e�����ϵ������Ԫ�ص�λ��
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	int i=0;//�ӱ�ͷ��ʼ����
	while(i<L->length&&!compare(L->elem[i],e))
		i++;//����
	if(i>=L->length)//��������������Ԫ�ز�����
	{
		printf("��������������Ԫ�ز�����\n");
		return 0;
	} 
	else return i+1;//����λ�� 
} 

status PriorElem(SqListP L,ElemType cur,ElemType&pre_e)
{
	//��ȡǰ�� 
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	int i=0;
	while((i<L->length)&&(L->elem[i]!=cur))//�ҵ�cur��Ӧ������ 
	{
		i++;
	}
	if(i==0)//cur�ǵ�һ�� 
	{
		printf("cur�ǵ�һ��\n");
		return ERROR;
	}
	if(i>=L->length)//cur��������Ԫ������ 
	{
		printf("cur��������Ԫ����\n");
		return ERROR;
	}
	pre_e=L->elem[i-1];//��cur��ǰ����Ӧ��ָ�븳ֵ��pre_e
	return OK; 
}

status NextElem(SqListP L,ElemType cur,ElemType&next_e)
{
	//��ȡ���� 
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	int i=0;
	while((i<L->length)&&(L->elem[i]!=cur))//�ҵ�cur��Ӧ������ 
	{
		i++;
	}
	if(i==(L->length-1))//cur�����һ�� 
	{
		printf("cur�����һ��\n");
		return ERROR;
	}
	if(i>=L->length)//cur��������Ԫ������ 
	{
		printf("cur��������Ԫ����\n");
		return ERROR;
	}
	next_e=L->elem[i+1];//��cur�ĺ�����Ӧ��ָ�븳ֵ��pre_e
	return OK; 
}

status ListInsert(SqListP L,int i,ElemType e)
{
	//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	//i�ĺϷ�ֵΪ1<=i<=L->length+1
	if(i<1||i>L->length+1)//iֵ���Ϸ� 
	{
		printf("OVERFLOW");
		return ERROR;
	} 
	if(L->length>=L->listsize)
	{
		//��ǰ�洢�ռ��Ѿ��������ӷ���
		ElemType* newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW);//�����ڴ�ʧ��
		L->elem=newbase;//�»�ַ 
		L->listsize+=LISTINCREMENT;//���Ӵ洢���� 
	}
	ElemType* q=&(L->elem[i-1]);//qΪ����λ��
	for(ElemType*p=&(L->elem[L->length-1]);p>=q;--p)
		*(p+1)=*p;//����λ�ü�֮���Ԫ������
	*q=e;//����e 
	++L->length;//������1
	return OK; 
	
}//ListInsert

status ListDelete(SqListP L,int i,ElemType* e)
{
	//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e����ֵ
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	//i�ĺϷ�ֵΪ1<=i<=L->length
	if(i<1||i>L->length)//iֵ���Ϸ� 
	{
		printf("OVERFLOW");
		return ERROR;
	}
	ElemType*p=&(L->elem[i-1]);//pΪ��ɾ��Ԫ�ص�λ�� 
	*e=*p;//��ɾ��Ԫ�ص�ֵ����e
	ElemType*q=L->elem+L->length-1;//��βԪ�ص�λ��
	for(++p;p<=q;++p)
		*(p-1)=*p;//��ɾ��Ԫ��֮���Ԫ������
	--L->length;//����1
	return OK; 
	 
}//ListDelete

status ListTrabverse(SqListP L,void(*visit)(ElemType*e))
{
	//���ζ�L��ÿ������Ԫ�ص��ú���visit()
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
		return ERROR;
	}
	int i=0;//�ӱ�ͷ��ʼ����
	while(i<(L->length))
	{
		visit(&(L->elem[i]));//��ÿ������Ԫ�ص���visit
		i++;
	} 
	printf("\n");	
	return OK; 
}
status ListSet(SqListP L)
{
	//���� 
	if(L->elem==NULL)//�ж�L�Ƿ���� 
	{
		printf("���Ա�����\n");
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

