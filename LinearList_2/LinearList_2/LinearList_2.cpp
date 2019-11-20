//LinearList_2
#include"pch.h"
#include<stdio.h>
#include<stdlib.h>
#include"LinearList_2.h"

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
int compare(ElemType x, ElemType e);
void visit(ElemType x);
#define ListNumber 10//the number of LinearLists

int main(int argc,char *argv[])
{
	//main function
	int op = 1;
	ElemType e = 0;
	ElemType cur = 0;
	ElemType pre_e;
	ElemType next_e;
	int i = 0;
	int j = 0;

	//define a LinearList group
	LinkList ListGroup[ListNumber];
	for (i = 0; i < ListNumber; i++)//initialize
		ListGroup[i] = NULL;
	int index = 0;
	int tempdex = 0;
	int index_a = 0;
	int index_b = 0;
	int index_c = 0;
	LinkList *L = &ListGroup[index];

	//define file pointer
	FILE *fp;
	char writeFileName[30];
	char readFileName[30];

	//define LinkList Pointer
	LinkList temp, semp;
	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("------index of present LinearList:%d--------------\n", index);
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList       7. LocateElem\n");
		printf("    	  2. DestroyList    8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty     10. ListInsert\n");
		printf("    	  5. ListLength     11. ListDelete\n");
		printf("    	  6. GetElem       12. ListTrabverse\n");
		printf("    	  13.save           14.load\n");
		printf("    	  15.ListSet        16. ChangeList\n");
		printf("          17.ListMerge      0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~17]:");
		scanf_s("%d", &op);
		switch (op)
		{
			case 1:
				printf("Your choise:1\n");
				printf("/*\n *Function Name:InitList\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:initialize the LinearList\n*/\n");
				if (InitList(*L) == OK) printf("*LinearList initialize success\n");
				else printf("*LinearList initialize error\n");
				getchar();
				getchar();
				break;
			case 2:
				printf("Your choise:2\n");
				printf("/*\n *Function Name:DestroyList\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:destroy the LinearList\n*/\n");
				if (DestroyList(*L) == OK)printf("*LinearList destroy success\n");
				else printf("*LinearList destroy error\n");
				getchar();
				getchar();
				break;
			case 3:
				printf("Your choise:3\n");
				printf("/*\n *Function Name:ClearList\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:reset the LinearList\n*/\n");
				if (ClearList(*L) == OK)printf("*LinearList reset success\n");
				else printf("*LinearList reset error\n");
				getchar();
				getchar();
				break;
			case 4:
				printf("Your choise:4\n");
				printf("/*\n *Function Name:ListEmpty\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:judge the LinearList null or not\n*/\n");
				if (ListEmpty(*L) == TRUE)
					printf("*LinearList is null\n");
				else
					printf("*LinearList is not null\n");
				getchar();
				getchar();
				break;
			case 5:
				printf("Your choise:5\n");
				printf("/*\n *Function Name:ListLength\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:int\n");
				printf(" *Use:return the length of the LinearList\n*/\n");
				printf("*the length of the LinearList is:%d\n", ListLength(*L));
				getchar();
				getchar();
				break;
			case 6:
				printf("Your choise:6\n");
				printf("/*\n *Function Name:GetElem\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,int order,ElemType& elem\n");
				printf(" *Return:status\n");
				printf(" *Use:get the No.order element of the LinearList\n*/\n");
				printf("*The order:");
				scanf_s("%d", &i);
				if (GetElem(*L, i, e) == OK)
				{
					printf("*GetElem Success\n");
					printf("*The element is:%d\n", e);
				}
				else
					printf("*GetElem Error\n");
				getchar();
				getchar();
				break;
			case 7:
				printf("Your choise:7\n");
				printf("/*\n *Function Name:LocateElem\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,ElemType elem,FunctionPointer compare\n");
				printf(" *Return:int\n");
				printf(" *Use:find the first element in the LinearList\n");
				printf(" *with the relationship compare with e\n*/\n");
				printf("*input e:");
				scanf_s("%d", &e);
				if (LocateElem(*L, e, compare) == ERROR)
				{
					printf("*The LinearList or such element do not exist\n");
					printf("*LocateElem Error\n");
					getchar();
					getchar();
					break;
				}
				printf("*LocateElem Success\n");
				printf("*The order of the element is:%d\n", LocateElem(*L, e, compare));
				getchar();
				getchar();
				break;
			case 8:
				printf("Your choise:8\n");
				printf("/*\n *Function Name:PriorElem\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,ElemType cur,ElemType&pre_e\n");
				printf(" *Return:status\n");
				printf(" *Use:find the pre element of cur in the LinearList\n*/\n");
				printf("*cur:");
				scanf_s("%d", &cur);
				if (PriorElem(*L, cur, pre_e) == OK)
				{
					printf("*PriorElem Success\n");
					printf("*the PriorElem of cur is:%d\n", pre_e);
				}
				else
					printf("*PriorElem Error\n");
				getchar();
				getchar();
				break;
			case 9:
				printf("Your choise:9\n");
				printf("/*\n *Function Name:NextElem\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,ElemType cur,ElemType&next_e\n");
				printf(" *Return:status\n");
				printf(" *Use:find the next element of cur in the LinearList\n*/\n");
				printf("*cur:");
				scanf_s("%d", &cur);
				if (NextElem(*L, cur, next_e) == OK)
				{
					printf("*NextElem Success\n");
					printf("*the NextElem of cur is:%d\n", next_e);
				}
				else
					printf("*NextElem Error\n");
				getchar();
				getchar();
				break;
			case 10:
				printf("Your choise:10\n");
				printf("/*\n *Function Name:ListInsert\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,int order,ElemType elem\n");
				printf(" *Return:status\n");
				printf(" *Use:insert an element into the LinearList\n*/\n");
				printf("*order:");
				scanf_s("%d", &i);
				printf("*element:");
				scanf_s("%d", &e);
				if (ListInsert(*L, i, e) == ERROR)
				{
					printf("*ListInsert Error\n");
					getchar();
					getchar();
					break;
				}
				else
					printf("*ListInsert Success\n");
				getchar();
				getchar();
				break;
			case 11:
				printf("Your choise:11\n");
				printf("/*\n *Function Name:ListDelete\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,int order,ElemType& elem\n");
				printf(" *Return:status\n");
				printf(" *Use:delete the No.order element of the LinearList\n*/\n");
				printf("*order:");
				scanf_s("%d", &i);
				if (ListDelete(*L, i, e) == ERROR)
				{
					printf("*ListDelete Error\n");
					getchar();
					getchar();
					break;
				}
				else
				{
					printf("*ListDelete Success\n");
					printf("*The element  be deleted is:%d\n", e);
				}
				getchar();
				getchar();
				break;
			case 12:
				printf("Your choise:12\n");
				printf("/*\n *Function Name:ListTraverse\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,FunctionPointer visit\n");
				printf(" *Return:status\n");
				printf(" *Use:travel the whole LinearList\n*/\n");
				if (ListTraverse(*L, visit) == OK)
					printf("*ListTraverse Success\n");
				else
					printf("*ListTraverse Error\n");
				getchar();
				getchar();
				break;
			case 13:
				printf("Your choise:13\n");
				printf("/*\n");
				printf(" *Function Name:Save\n");
				printf(" *Module:Data structures\n");
				printf(" *Use:save data in the LinearList as a file\n");
				printf("*/\n");
				//Error Alarm
				if (*L == NULL)//LinearList is null
				{
					printf("*The LinearList do not exist\n");
					getchar();
					getchar();
					break;
				}
				//save
				printf("*FileName:");
				scanf_s("%s", writeFileName,sizeof(writeFileName));
				if ((fp = fopen(writeFileName, "wb")) == NULL)
				{
					printf("*File open error\n ");
					getchar();
					getchar();
					break;
				}
				temp = *L;
				while (temp)
				{
					fwrite(&temp->data, sizeof(ElemType), 1, fp);
					temp = temp->next;
				}
				fclose(fp);
				printf("*Save File Success\n");
				getchar();
				getchar();
				break;
			case 14:
				printf("Your choise:14\n");
				printf("/*\n");
				printf(" *Function Name:Read\n");
				printf(" *Module:Data structures\n");
				printf(" *Use:read data in the LinearList as a file\n");
				printf("*/\n");
				//Error Alarm
				if (*L == NULL)//LinearList is null
				{
					printf("*The LinearList do not exist\n");
					getchar();
					getchar();
					break;
				}
				//read
				printf("*FileName:");
				scanf_s("%s", readFileName,sizeof(readFileName));
				if ((fp = fopen(readFileName, "rb")) == NULL)
				{
					printf("*File open error\n ");
					getchar();
					getchar();
					break;
				}
				temp = *L;
				fread(&temp->data, sizeof(ElemType), 1, fp);
				j = temp->data;
				while (j > 0)
				{
					semp = (LinkList)malloc(sizeof(LNode));
					if (semp == NULL)
					{
						printf("*space call error\n");
						exit(1);
					}
					semp->next = NULL;
					temp->next = semp;
					temp = semp;
					j--;
				}
				temp = (*L)->next;
				j = (*L)->data;
				while (j > 0&&temp)
				{
					fread(&temp->data, sizeof(ElemType), 1, fp);
					temp = temp->next;
					j--;
				}
				fclose(fp);
				printf("*Read File Success\n");
				getchar();
				getchar();
				break;
			case 15:
				printf("Your choise:15\n");
				printf("/*\n *Function Name:ListSort\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:sort the LinearList\n*/\n");
				if (ListSort(*L) == OK)
					printf("*ListSort Success\n");
				else
					printf("*ListSort Error\n");
				getchar();
				getchar();
				break;
			case 16:
				printf("Your choise:16\n");
				printf("/*\n *Function Name:ChangeList\n");
				printf(" *Module:Data structures\n");
				printf(" *Use:change the LinearList\n*/\n");
				printf("*index:");
				scanf_s("%d", &tempdex);
				if (tempdex < 0 || tempdex >= ListNumber)//index error
				{
					printf("*OVERFLOW\n");
					getchar();
					getchar();
					break;
				}
				index = tempdex;
				L = &ListGroup[index];//switch
				printf("*ChangeList Success\n");
				getchar();
				getchar();
				break;
			case 17:
				printf("Your choise:17\n");
				printf("/*\n *Function Name:ListMerge\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList La,LinkList Lb,Linklist Lc\n");
				printf(" *Return:status\n");
				printf(" *Use:merge two LinearList as new one\n*/\n");
				printf("*index of La:");
				scanf_s("%d", &index_a);
				if (index_a<0 || index_a>ListNumber - 1)
				{
					printf("OVERFLOW");
					getchar();
					getchar();
					break;
				}
				printf("*index of Lb:");
				scanf_s("%d", &index_b);
				if (index_b<0 || index_b>ListNumber - 1)
				{
					printf("OVERFLOW");
					getchar();
					getchar();
					break;
				}
				printf("*index of Lc:");
				scanf_s("%d", &index_c);
				if (index_c<0 || index_c>ListNumber - 1)
				{
					printf("*OVERFLOW\n");
					getchar();
					getchar();
					break;
				}
				if (ListMerger(ListGroup[index_a], ListGroup[index_b], ListGroup[index_c]) == OK)
					printf("*ListMerge and ListSort Success\n");
				getchar();
				getchar();
				break;
			case 0:
				break;
		}//end of switch
		printf("Welcome next time");
	}//end of while
	
}//end of main function

int compare(ElemType x, ElemType e)
{
	return x == e;
}

void visit(ElemType x)
{
	printf("\t%d",x);
}


