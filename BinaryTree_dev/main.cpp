#include<stdio.h>
#include<stdlib.h>
#include"BiTreeADT.h"


#define MaxTreeNumner 10

//Functions Declaration
status CreateBiTree(BinaryTreePos&T, int definition);
status DestroyBiTree(BinaryTreePos&T);
status ClearBiTree(BinaryTreePos&T);
status BiTreeEmpty(BinaryTreePos&T);
int BiTreeDepth(BiTPos&root);
BiTPos LocateNode(BinaryTreePos&T, KeyType e);
status Assign(BinaryTreePos&T, KeyType e, ElemType value);
BiTPos GetSibling(BinaryTreePos&T, KeyType e);
status InsertNode(BinaryTreePos&T, KeyType e, int LR, BiTPos&c);
status DeleteNode(BinaryTreePos&T, KeyType e);
status PreOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node));
status InOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node));
status PostOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node));
status LevelOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node));
status LevelOrderTraverse(BinaryTreePos&T, int&keydex);
status LevelOrderTraverse(BinaryTreePos&T, KeyType e,BiTPos&result);
void Destroy(BiTPos&root);
status visit(BiTPos&node);

int main(int argc, char *argv[])
{
	int op = 1;
	int i = 0;
	int definition = 1;
	
	KeyType e=0;
	BiTPos result=NULL;

	BinaryTreePos TreeGroup[MaxTreeNumner];
	for (i = 0; i < MaxTreeNumner; i++)//Initilaze
	{
		TreeGroup[i]=NULL;
	}
	BinaryTreePos *T = &TreeGroup[0];//T is the first tree
	int index=0;
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
		printf("    ÇëÑ¡ÔñÄãµÄ²Ù×÷[0~17]:");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("Your choise:1\n");
			printf("/*\n *Function Name:CreateBiTree\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T, int definition\n");
			printf(" *Return:status\n");
			printf(" *Use:Create a tree\n*/\n");
			printf("*Definition:\n*1.preorder and inorder\n*2.postorder and inorder\n*3.preorder and nullnode\n*4.postorder and nullnode\n");
			scanf("%d", &definition);
			if (CreateBiTree(*T, definition) == OK)
			{
				(*T)->id=index;
				printf("*size:%d\n",(*T)->size);
				printf("*Operator Success\n");
			}
			else
			{
				printf("*Operator Error\n");
			}

			getchar();
			getchar();
			break;
		case 2:
			printf("Your choise:2\n");
			printf("/*\n *Function Name:DestroyBiTree\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T\n");
			printf(" *Return:status\n");
			printf(" *Use:destroy the BinaryTree\n*/\n");
			if (DestroyBiTree(*T) == OK)
			{
				printf("*Operator Success\n");
			}
			else
			{
				printf("*Operator Error\n");
			}
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
			if(ClearBiTree(*T)==OK)
			{
				printf("*Operator Success\n");
			}
			else
			{
				printf("*Operator Error\n");
			}
			getchar();
			getchar();
			break;
		case 4:
			printf("Your choise:4\n");
			printf("/*\n *Function Name:BiTreeEmpty\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T\n");
			printf(" *Return:status\n");
			printf(" *Use:judge the BinaryTree null or not\n*/\n");
			if (BiTreeEmpty(*T) == TRUE)
			{
				printf("*Empty\n");
			}
			else
			{
				printf("*Not Empty\n");
			}
			getchar();
			getchar();
			break;
		case 5:
			printf("Your choise:5\n");
			printf("/*\n *Function Name:BiTreeDepth\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T\n");
			printf(" *Return:int\n");
			printf(" *Use:return the depth of the BinaryTree\n*/\n");
			if(*T==NULL)
			{
				printf("*The BinaryTree is NULL\n");
				getchar();
				getchar();
				break;
			}
			printf("*Depth:%d\n", BiTreeDepth((*T)->root));
			getchar();
			getchar();
			break;
		case 6:
			printf("Your choise:6\n");
			printf("/*\n *Function Name:LocateNode\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T, KeyType e\n");
			printf(" *Return:status\n");
			printf(" *Use:get the node with key e in the BiTree\n*/\n");
			printf("*Input the Key:");
			scanf("%d",&e);
			result=LocateNode(*T,e);
			if(result!=NULL)
			{
				printf("*Operator Success\n");
				printf("*key:%d value:%d\n",result->index,result->value);
			}
			else
			{
				printf("*Operator Error\n");
			}
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
			printf(" *Parameter:BinaryTreePos&T, status(*visit)(BiTPos&node)\n");
			printf(" *Return:status\n");
			printf(" *Use:Travel the BinaryTree in pre_order\n*/\n");
			if (PreOrderTraverse(*T, visit) == OK)
			{
				printf("*Operator Success\n");
			}
			else
			{
				printf("*Operator Error\n");
			}
			getchar();
			getchar();
			break;
		case 12:
			printf("Your choise:12\n");
			printf("/*\n *Function Name:InOrderTraverse\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T, status(*visit)(BiTPos&node)\n");
			printf(" *Return:status\n");
			printf(" *Use:Travel the BinaryTree in in_order\n*/\n");
			if (InOrderTraverse(*T, visit) == OK)
			{
				printf("*Operator Success\n");
			}
			else
			{
				printf("*Operator Error\n");
			}
			getchar();
			getchar();
			break;
		case 13:
			printf("Your choise:13\n");
			printf("/*\n");
			printf(" *Function Name:PostOrderTraverse\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T, status(*visit)(BiTPos&node)\n");
			printf(" *Return:status\n");
			printf(" *Use:Travel the BinaryTree in post_order\n");
			if (PostOrderTraverse(*T, visit) == OK)
			{
				printf("*Operator Success\n");
			}
			else
			{
				printf("*Operator Error\n");
			}
			getchar();
			getchar();
			break;
		case 14:
			printf("Your choise:14\n");
			printf("/*\n");
			printf(" *Function Name:LevelOrderTraverse\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T, status(*visit)(BiTPos&node)\n");
			printf(" *Return:status\n");
			printf(" *Use:Travel the BinaryTree in level_order\n");
			if (LevelOrderTraverse(*T, visit) == OK)
			{
				printf("*Operator Success\n");
			}
			else
			{
				printf("*Operator Error\n");
			}
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
}


