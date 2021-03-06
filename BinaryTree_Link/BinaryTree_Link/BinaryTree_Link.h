#pragma once
//BinaryTree_Link head file
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"StackADT.h"
//define return value
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MaxOrder 50
#define MaxSize 100


typedef int status;
typedef char ElemType;//type of data
typedef int KeyType;//type of key

//the main struct of binary tree
typedef struct BinaryTree
{
	int id;//ID of BITree
	int size;//numbers of Nodes
	struct BiTNode *root;//root of BiTree
}BinaryTree, *BinaryTreePos;



typedef struct BiTNode
{
	KeyType index;
	ElemType value;
	struct BiTNode *lchild, *rchild;//left and right child
}BiTNode,*BiTPos;//define of Node ADT

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
BiTPos CreateBiTree1(int* pre_start, int* pre_end, int* in_start, int* in_end, int&size);
BiTPos CreateBiTree2(int* post_start, int* post_end, int* in_start, int* in_end, int&size);
void CreateBiTree3(BiTPos&root, int&size);
void Destroy(BiTPos&root);
status visit(BiTPos&node);

status CreateBiTree(BinaryTreePos&T, int definition)
{
	//error alarm
	if (T->root != NULL)
	{
		printf("*The BinaryTree is not NULL\n");
		return ERROR;
	}
	if (definition == 1)//PreOrder and InOrder
	{
		int pre_order[MaxOrder];
		int in_order[MaxOrder];
		int input = 1;
		int i = 0;
		printf("*Input positive pre_order,end with 0:\n");
		while (1)
		{
			if (i >= MaxOrder)
			{
				printf("*OVERFLOW\n");
				break;
			}
			printf("index:%d\n", i);
			scanf("%d", &input);
			if (input = 0)
			{
				printf("*Input end\n");
				break;
			}
			if (input < 0)
			{
				printf("*Input is negative\n");
				continue;
			}
			pre_order[i] = input;
			i++;
			printf("*Input success\n");
		}
		if (i = 0)
		{
			printf("*Input NULL\n");
			return ERROR;
		}
		int *pre_end = &pre_order[i - 1];
		i = 0;
		printf("*Input positive in_order,end with 0:\n");
		while (1)
		{
			if (i >= MaxOrder)
			{
				printf("*OVERFLOW\n");
				break;
			}
			printf("index:%d\n", i);
			scanf("%d", &input);
			if (input = 0)
			{
				printf("*Input end\n");
				break;
			}
			if (input < 0)
			{
				printf("*Input is negative\n");
				continue;
			}
			in_order[i] = input;
			i++;
			printf("*Input success\n");
		}
		if (i = 0)
		{
			printf("*Input NULL\n");
			return ERROR;
		}
		int *in_end = &in_order[i - 1];
		T->root = CreateBiTree1(pre_order, pre_end, in_order, in_end,T->size);
		printf("*Create Success\n");
		return OK;
	}
	else if (definition == 2)//PostOrder and InOrder
	{
		int post_order[MaxOrder];
		int in_order[MaxOrder];
		int input = 1;
		int i = 0;
		printf("*Input positive post_order,end with 0:\n");
		while (1)
		{
			if (i >= MaxOrder)
			{
				printf("*OVERFLOW\n");
				break;
			}
			printf("index:%d\n", i);
			scanf("%d", &input);
			if (input = 0)
			{
				printf("*Input end\n");
				break;
			}
			if (input < 0)
			{
				printf("*Input is negative\n");
				continue;
			}
			post_order[i] = input;
			i++;
			printf("*Input success\n");
		}
		if (i = 0)
		{
			printf("*Input NULL\n");
			return ERROR;
		}
		int *post_end = &post_order[i - 1];
		i = 0;
		printf("*Input positive in_order,end with 0:\n");
		while (1)
		{
			if (i >= MaxOrder)
			{
				printf("*OVERFLOW\n");
				break;
			}
			printf("index:%d\n", i);
			scanf("%d", &input);
			if (input = 0)
			{
				printf("*Input end\n");
				break;
			}
			if (input < 0)
			{
				printf("*Input is negative\n");
				continue;
			}
			in_order[i] = input;
			i++;
			printf("*Input success\n");
		}
		if (i = 0)
		{
			printf("*Input NULL\n");
			return ERROR;
		}
		int *in_end = &in_order[i - 1];
		T->root = CreateBiTree2(post_order, post_end, in_order, in_end,T->size);
		printf("*Create Success\n");
		return OK;
	}
	else if (definition == 3)//PreOrder and NULL
	{
		CreateBiTree3(T->root,T->size);
	}
	else if (definition == 4)//PostOrder and NULL
	{

	}
	else
	{
		printf("*Input error\n");
		return ERROR;
	}
}

status DestroyBiTree(BinaryTreePos&T)
{
	if (T->root == NULL)
	{
		printf("*The BiTree is NULL\n");
		return ERROR;
	}
	Destroy(T->root);
	printf("*Destroy Success\n");
	return OK;
}

status ClearBiTree(BinaryTreePos&T)
{
	return;

}

status BiTreeEmpty(BinaryTreePos&T)
{
	if (T->root == NULL)
		return FALSE;
	else
		return TRUE;
}

int BiTreeDepth(BiTPos&root)
{
	if (root == NULL)
	{
		printf("*The BiTree is NULL\n");
		return 0;
	}
	int left = BiTreeDepth(root->lchild) + 1;
	int right = BiTreeDepth(root->rchild) + 1;
	return left > right ? left : right;
}

BiTPos LocateNode(BinaryTreePos&T, KeyType e)
{
	return ;
}

status Assign(BinaryTreePos&T, KeyType e, ElemType value)
{
	return ;
}

BiTPos GetSibling(BinaryTreePos&T, KeyType e)
{
	return;
}

status InsertNode(BinaryTreePos&T, KeyType e, int LR, BiTPos&c)
{
	return ;
}

status DeleteNode(BinaryTreePos&T, KeyType e)
{
	return ;
}

status PreOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node))
{
	if (T->root == NULL)
	{
		printf("*The BiTree si NULL\n");
		return ERROR;
	}
	SqStack S;//Create a Stack
	InitStack(S);
	BiTPos p;
	Push(S, T->root);//push root
	while (!StackEmpty(S))
	{
		Pop(S, p);
		if (!visit(p))return ERROR;//visit
		if (p->rchild != NULL)
			Push(S, p->rchild);
		if (p->lchild != NULL)
			Push(S, p->lchild);
	}//end of while
	printf("*PreOderTravel Success\n");
	return OK;
}

status InOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node))
{
	if (T->root == NULL)
	{
		printf("*The BiTree si NULL\n");
		return ERROR;
	}
	SqStack S;//Create a Stack
	InitStack(S);
	BiTPos p = T->root;
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			Push(S, p);
			p = p->lchild;//push root,search left tree
		}
		else
		{
			Pop(S, p);
			if (!visit(p))return ERROR;//visit
			p = p->rchild;
		}//end of else
	}//end of while
	printf("*InOderTravel Success\n");
	return OK;
}

status PostOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node))
{
	if (T->root == NULL)
	{
		printf("*The BiTree si NULL\n");
		return ERROR;
	}
	BiTPos t = T->root;
	BiTPos St[MaxSize], pre;
	int flag = 0;
	int top = 0;
	do
	{
		while (t != NULL)
		{
			St[top++] = t;
			t = t->lchild;
		}
		pre = NULL;
		flag = 1;
		while (top&&flag)
		{
			t = St[top - 1];
			if (t->rchild == pre)
			{
				if (!visit(t))return ERROR;//visit
				top--;
				pre = t;
			}
			else
			{
				t = t->rchild;
				flag = 0;
			}
		}
	} while (top);
	printf("*PostOderTravel Success\n");
	return OK;
}

status LevelOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node))
{
	if (T->root == NULL)
	{
		printf("*The BiTree si NULL\n");
		return ERROR;
	}
	BiTPos t = T->root;
	BiTPos temp = NULL;//use for store
	BiTPos Sq[MaxSize];
	int rear = 0;
	int front = 0;
	Sq[front++] = t;//root enqueue
	while (rear != front)
	{
		if (front >= MaxOrder)
		{
			printf("*OVERFLOW\n");
			exit(OVERFLOW);
		}
		temp = Sq[front - 1];
		if (!visit(t))return ERROR;//visit
		if (temp->index != NULL)//lchild is not null,enqueue
		{
			Sq[front++] = temp->lchild;//lchild enqueue
			printf("*lchild enqueue\n");
		}
		if (temp->rchild != NULL)
		{
			Sq[front++] = temp->rchild;//rchild enqueue
			printf("*rchild enqueue\n");
		}
	}
	printf("*LevelOrderTraverse Success\n");
	return OK;
}

BiTPos CreateBiTree1(int* pre_start, int* pre_end, int* in_start, int* in_end,int&size)
{
	//前序遍历的第一个元素是根节点
	int root_value = pre_start[0];
	BiTPos root = (BiTPos)malloc(sizeof(struct BiTNode));
	if (!root)
	{
		printf("*OVERFLOW\n");
		exit(OVERFLOW);
	}
	root->lchild = NULL;
	root->rchild = NULL;
	root->index = root_value;
	root->value = 'N';
	size++;

	//如果只有一个元素，并且中序遍历和前序遍历元素相同
	if (pre_start == pre_end)
	{
		if ((in_start == in_end) && (*pre_start == *in_end))
		{
			return root;
		}
		else
		{
			printf("*Input error\n");
			return NULL;//输入错误，无法构建排序二叉树
		}
	}

	//在中序遍历序列中找到根节点
	int* root_inorder = in_start;
	bool is_find_root = false;
	while (root_inorder <= in_end)
	{
		if (*root_inorder == root_value)
		{
			is_find_root = true;
			break;
		}
		root_inorder++;
	}

	//在中序遍历中未找到根节点
	if (!is_find_root)
	{
		printf("*Input error\n");
		return NULL;//输入错误，无法构建排序二叉树
	}

	int left_length = root_inorder - in_start;
	int* left_preorder_end = pre_start + left_length;//前序遍历中左子树的最右边的位置

	if (left_length > 0)//构建左子树
	{
		//左子树的前序中序遍历序列的end指针都变化了
		root->lchild = CreateBiTree1(pre_start + 1, left_preorder_end, in_start, root_inorder - 1,size);
	}

	int* right_preorder_start = left_preorder_end + 1;//前序遍历中右子树的最左边位置
	int right_length = pre_end - right_preorder_start + 1;

	if (right_length > 0)//构建右子树
	{
		root->rchild = CreateBiTree1(right_preorder_start, pre_end, root_inorder + 1, in_end,size);
	}

	return root;
}

BiTPos CreateBiTree2(int* post_start, int* post_end, int* in_start, int* in_end,int&size)
{
	//后序遍历的最后一个元素是根节点
	int root_value = post_end[0];
	BiTPos root = (BiTPos)malloc(sizeof(struct BiTNode));
	if (!root)
	{
		printf("*OVERFLOW\n");
		exit(OVERFLOW);
	}
	root->lchild = NULL;
	root->rchild = NULL;
	root->index = root_value;
	root->value = 'N';
	size++;

	//如果只有一个元素，并且中序遍历和后序遍历元素相同
	if (post_start == post_end)
	{
		if ((in_start == in_end) && (*post_end == *in_end))
		{
			return root;
		}
		else
		{
			printf("*Input error\n");
			return NULL;//输入错误，无法构建排序二叉树
		}
	}

	//在中序遍历序列中找到根节点
	int* root_inorder = in_start;
	bool is_find_root = false;
	while (root_inorder <= in_end)
	{
		if (*root_inorder == root_value)
		{
			is_find_root = true;
			break;
		}
		root_inorder++;
	}

	//在中序遍历中未找到根节点
	if (!is_find_root)
	{
		printf("*Input error\n");
		return NULL;//输入错误，无法构建排序二叉树
	}

	int left_length = root_inorder - in_start;
	int* left_preorder_end = post_start + left_length;//后序遍历中左子树的最右边的位置

	if (left_length > 0)//构建左子树
	{
		//左子树的前序中序遍历序列的end指针都变化了
		root->lchild = CreateBiTree2(post_start , left_preorder_end, in_start, root_inorder - 1,size);
	}

	int* right_preorder_start = left_preorder_end + 1;//后序遍历中右子树的最左边位置
	int right_length = post_end - right_preorder_start + 1;

	if (right_length > 0)//构建右子树
	{
		root->rchild = CreateBiTree1(right_preorder_start, post_end-1, root_inorder + 1, in_end,size);
	}

	return root;
}


void CreateBiTree3(BiTPos&root,int &size)
{
	char ch;
	scanf("%c", &ch);//input an node
	if (ch == '#')
		root = NULL;
	else
	{
		root = (BiTPos)malloc(sizeof(struct BiTNode));//Generate root node
		if (!root)
		{
			printf("*OVERFLOW\n");
			exit(OVERFLOW);
		}
		size++;
		root->index = size;
		root->index = NULL;
		root->rchild = NULL;
		root->value = ch;
		CreateBiTree3(root->lchild,size);//Create left tree
		CreateBiTree3(root->rchild,size);//Create right tree
	}
}

void Destroy(BiTPos&root)
{
	if (!root)return;
	Destroy(root->lchild);
	Destroy(root->rchild);
	free(root);
	root = NULL;
}

status visit(BiTPos&node)
{
	printf("key:%d value:%c  ", node->index, node->value);
	return OK;
}
