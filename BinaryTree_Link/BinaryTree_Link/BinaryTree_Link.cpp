#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree_Link.h"

//Functions Declaration
status CreateBiTree(BinaryTreePos&T, int definition);
status DestroyBiTree(BinaryTreePos&T);
status ClearBiTree(BinaryTreePos&T);
status BiTreeEmpty(BinaryTreePos&T);
int BiTreeDepth(BinaryTreePos&T);
BiTPos LocateNode(BinaryTreePos&T, KeyType e);
status Assign(BinaryTreePos&T, KeyType e, ElemType value);
BiTPos GetSibling(BinaryTreePos&T, KeyType e);
status InsertNode(BinaryTreePos&T, KeyType e, int LR, BiTPos&c);
status DeleteNode(BinaryTreePos&T, KeyType e);
status PreOrderTraverse(BinaryTreePos&T, void(*visit)(BiTPos&node));
status InOrderTraverse(BinaryTreePos&T, void(*visit)(BiTPos&node));
status PostOrderTraverse(BinaryTreePos&T, void(*visit)(BiTPos&node));
status LevelOrderTraverse(BinaryTreePos&T, void(*visit)(BiTPos&node));

int main(int argc, char *argv[])
{
	int op = 1;
	int index;


	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("------index of present LinearList:%d--------------\n", index);
		printf("-------------------------------------------------\n");
		printf("    	  1. CreateBiTree      2. DestroyBiTree\n");
		printf("    	  3. ClearBiTree       4. BiTreeEmpty\n");
		printf("    	  5. BiTreeDepth       6. LocateNode\n");
		printf("    	  7. Assign            8. GetSibling\n");
		printf("    	  9. InsertNode        10.DeleteNode\n");
		printf("    	  11.PreOrderTraverse  12.InOrderTraverse\n");
		printf("    	  13.PostOrderTraverse 14.LevelOrderTraverse\n");
		printf("    	  15.SaveBiTree        16.LoadBiTree\n");
		printf("          17.ChangeBiTree      0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~17]:");
		scanf_s("%d", &op);
		switch (op)
		{
			case 1:
				printf("Your choise:1\n");
				printf("/*\n *Function Name:CreateBiTree\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:initialize the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 2:
				printf("Your choise:2\n");
				printf("/*\n *Function Name:DestroyBiTree\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:destroy the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 3:
				printf("Your choise:3\n");
				printf("/*\n *Function Name:ClearBiTree\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:reset the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 4:
				printf("Your choise:4\n");
				printf("/*\n *Function Name:BiTreeEmpty\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:judge the LinearList null or not\n*/\n");
				
				getchar();
				getchar();
				break;
			case 5:
				printf("Your choise:5\n");
				printf("/*\n *Function Name:BiTreeDepth\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:int\n");
				printf(" *Use:return the length of the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 6:
				printf("Your choise:6\n");
				printf("/*\n *Function Name:LocateNode\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,int order,ElemType& elem\n");
				printf(" *Return:status\n");
				printf(" *Use:get the No.order element of the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 7:
				printf("Your choise:7\n");
				printf("/*\n *Function Name:Assign\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,ElemType elem,FunctionPointer compare\n");
				printf(" *Return:int\n");
				printf(" *Use:find the first element in the LinearList\n");
				printf(" *with the relationship compare with e\n*/\n");
				
				getchar();
				getchar();
				break;
			case 8:
				printf("Your choise:8\n");
				printf("/*\n *Function Name:GetSibling\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,ElemType cur,ElemType&pre_e\n");
				printf(" *Return:status\n");
				printf(" *Use:find the pre element of cur in the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 9:
				printf("Your choise:9\n");
				printf("/*\n *Function Name:InsertNode\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,ElemType cur,ElemType&next_e\n");
				printf(" *Return:status\n");
				printf(" *Use:find the next element of cur in the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 10:
				printf("Your choise:10\n");
				printf("/*\n *Function Name:DeleteNode\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,int order,ElemType elem\n");
				printf(" *Return:status\n");
				printf(" *Use:insert an element into the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 11:
				printf("Your choise:11\n");
				printf("/*\n *Function Name:PreOrderTraverse\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,int order,ElemType& elem\n");
				printf(" *Return:status\n");
				printf(" *Use:delete the No.order element of the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 12:
				printf("Your choise:12\n");
				printf("/*\n *Function Name:InOrderTraverse\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L,FunctionPointer visit\n");
				printf(" *Return:status\n");
				printf(" *Use:travel the whole LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 13:
				printf("Your choise:13\n");
				printf("/*\n");
				printf(" *Function Name:PostOrderTraverse\n");
				printf(" *Module:Data structures\n");
				printf(" *Use:save data in the LinearList as a file\n");
				
				getchar();
				getchar();
				break;
			case 14:
				printf("Your choise:14\n");
				printf("/*\n");
				printf(" *Function Name:LevelOrderTraverse\n");
				printf(" *Module:Data structures\n");
				printf(" *Use:read data in the LinearList as a file\n");
				
				getchar();
				getchar();
				break;
			case 15:
				printf("Your choise:15\n");
				printf("/*\n *Function Name:SaveBiTree\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList L\n");
				printf(" *Return:status\n");
				printf(" *Use:sort the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 16:
				printf("Your choise:16\n");
				printf("/*\n *Function Name:LoadBiTree\n");
				printf(" *Module:Data structures\n");
				printf(" *Use:change the LinearList\n*/\n");
				
				getchar();
				getchar();
				break;
			case 17:
				printf("Your choise:17\n");
				printf("/*\n *Function Name:ChangeBiTree\n");
				printf(" *Module:Data structures\n");
				printf(" *Parameter:LinkList La,LinkList Lb,Linklist Lc\n");
				printf(" *Return:status\n");
				printf(" *Use:merge two LinearList as new one\n*/\n");
				
				getchar();
				getchar();
				break;
			case 0:
				break;
		}//end of switch
		printf("Welcome next time");
	}//end of while

























}//end of main

