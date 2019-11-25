//BinaryTree_Link head file
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
#define MaxOrder 50
#define MaxSize 100
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10


typedef int status;
typedef int ElemType;//type of data
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
}BiTNode, *BiTPos;//define of Node ADT


typedef BiTPos SElemType;//type of data


typedef struct SqStack//define of Stack Struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;





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
BiTPos CreateBiTree1(int* pre_start, int* pre_end, int* in_start, int* in_end, int&size);
BiTPos CreateBiTree2(int* post_start, int* post_end, int* in_start, int* in_end, int&size);
void CreateBiTree3(BiTPos&root, int&size,int&ch);
void CreateBiTree4(BiTPos&root,int&size,ElemType Array[],int&count);
void Destroy(BiTPos&root);
status visit(BiTPos&node);






status InitStack(SqStack&S);
status GetTop(SqStack&S, SElemType&e);
status Push(SqStack&S, SElemType e);
status Pop(SqStack&S, SElemType&e);
status StackEmpty(SqStack&S);



status CreateBiTree(BinaryTreePos&T, int definition)
{
	//error alarm
	if (T != NULL)
	{
		printf("*The BinaryTree is not NULL\n");
		return ERROR;
	}
	T=(BinaryTreePos)malloc(sizeof(BinaryTree));
	T->id=0;//Initilaze
	T->size=0;
	T->root=NULL;
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
			if (input == 0)
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
		if (i == 0)
		{
			printf("*Input NULL,Create a NULL Tree\n");
			T->root=NULL;
			return OK;
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
			if (input ==0)
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
		if (i==0)
		{
			printf("*Input NULL,Create a NULL Tree\n");
			T->root=NULL;
			return OK;
		}
		int *in_end = &in_order[i - 1];
		T->root = CreateBiTree1(pre_order, pre_end, in_order, in_end, T->size);
		if(T->root!=NULL)
		{
			printf("*Create Success\n");
			return OK;
		}
		else
		{
			printf("*Create Error\n");
			return ERROR;
		}
		
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
			if (input == 0)
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
		if (i==0)
		{
			printf("*Input NULL,Create a NULL Tree\n");
			T->root=NULL;
			return OK;
		}
		int *post_end = &post_order[i -1];
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
			if (input ==0)
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
		if (i ==0)
		{
			printf("*Input NULL,Create a NULL Tree\n");
			T->root=NULL;
			return OK;
		}
		int *in_end = &in_order[i - 1];
		T->root = CreateBiTree2(post_order, post_end, in_order, in_end, T->size);
		if(T->root!=NULL)
		{
			printf("*Create Success\n");
			return OK;
		}
		else
		{
			printf("*Create Error\n");
			return ERROR;
		}
		return OK;
	}
	else if (definition == 3)//PreOrder and NULL
	{
		printf("*input node value(positive int),null node donates by 0\n");
		int ch;
		int keydex=1;
		//scanf("%d",&ch);
		CreateBiTree3(T->root, T->size,ch);
		LevelOrderTraverse(T,keydex);
		printf("*Create Success\n");
		return OK;
		
	}
	else if (definition == 4)//PostOrder and NULL
	{
		printf("*input node value(positive int),null node donates by 0\n");
		printf("*end with -1\n");
		ElemType Array[MaxSize];
		int keydex=1;
		int count=0;
		ElemType input=1;
		while(input!=-1)
		{
			scanf("%d",&input);
			if(input==-1)printf("*Input end\n");
			else if(input<0)printf("*input error\n");
			else 
			{
				printf("*input success\n");
				Array[count]=input;
				count++;
			}
		}
		CreateBiTree4(T->root,T->size,Array,count);
		LevelOrderTraverse(T,keydex);
		printf("*Create Success\n");
		return OK;

	}
	else
	{
		printf("*Input error\n");
		return ERROR;
	}
}

status DestroyBiTree(BinaryTreePos&T)
{
	if (T== NULL)
	{
		printf("*The BiTree is NULL\n");
		return ERROR;
	}
	Destroy(T->root);
	free(T);
	T=NULL;
	printf("*Destroy Success\n");
	return OK;
}

status ClearBiTree(BinaryTreePos&T)
{
	if(T==NULL)
	{
		printf("*The BiTree is null\n");
		return ERROR;
	}
	Destroy(T->root);
	T->size=0;
	return OK;
}

status BiTreeEmpty(BinaryTreePos&T)
{
	if(T==NULL)
	{
		printf("*The BiTree is NULL\n");
		return FALSE;
	}
	if (T->root == NULL)
		return TRUE;
	else
		return FALSE;
}

int BiTreeDepth(BiTPos&root)
{
	if(root==NULL)return 0;
	int left = BiTreeDepth(root->lchild) + 1;
	int right = BiTreeDepth(root->rchild) + 1;
	return left > right ? left : right;
}

BiTPos LocateNode(BinaryTreePos&T, KeyType e)
{
	if(T==NULL)
	{
		printf("*The BiTree is NULL\n");
		return FALSE;
	}
	BiTPos result=NULL;
	if(LevelOrderTraverse(T,e,result)==OK)
		return result;
	else
		return NULL;
}

status Assign(BinaryTreePos&T, KeyType e, ElemType value)
{
	if(T==NULL)
	{
		printf("*The BiTree is NULL\n");
		return FALSE;
	}
	BiTPos target=LocateNode(T,e);
	if(target!=NULL)
	{
		target->value=value;
		printf("*value change\n");
		return OK;
	}
	else
		return ERROR;
}

BiTPos GetSibling(BinaryTreePos&T, KeyType e)
{
	if(T==NULL)
	{
		printf("*The BiTree is NULL\n");
		return FALSE;
	}
	BiTPos target=LocateNode(T,e);
	if(target!=NULL)
	{
		if(target->lchild!=NULL)
		{
			printf("*have left child\n");
			return target->lchild;
		}
		else if(target->rchild!=NULL)
		{
			printf("*don't have left child\n");
			printf("*have right child\n");
			return target->rchild;
		}
		else
		{
			printf("*don't have child\n");
			return NULL;
		}
	}
	else
		return NULL;
}

status InsertNode(BinaryTreePos&T, KeyType e, int LR, BiTPos&c)
{
	return OK;
}

status DeleteNode(BinaryTreePos&T, KeyType e)
{
	return OK;
}

status PreOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node))
{
	if(T==NULL)
	{
		printf("*The BiTree is null\n");
		return ERROR;
	}
	if (T->root == NULL)
	{
		printf("*The BiTree is Empty\n");
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
	if(T==NULL)
	{
		printf("*The BiTree is null\n");
		return ERROR;
	}
	if (T->root == NULL)
	{
		printf("*The BiTree is Empty\n");
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
	if(T==NULL)
	{
		printf("*The BiTree is null\n");
		return ERROR;
	}
	if (T->root == NULL)
	{
		printf("*The BiTree is Empty\n");
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
	if(T==NULL)
	{
		printf("*The BiTree is null\n");
		return ERROR;
	}
	if (T->root == NULL)
	{
		printf("*The BiTree is Empty\n");
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
		t=Sq[rear];
		if (!visit(t))return ERROR;//visit
		if (t->lchild != NULL)//lchild is not null,enqueue
		{
			Sq[front++] = t->lchild;//lchild enqueue
			//printf("*lchild enqueue\n");
		}
		if (t->rchild != NULL)
		{
			Sq[front++] = t->rchild;//rchild enqueue
			//printf("*rchild enqueue\n");
		}
		rear++;//dequeue
		
	}
	printf("*LevelOrderTraverse Success\n");
	return OK;
}



status LevelOrderTraverse(BinaryTreePos&T, int&keydex)
{
	if(T==NULL)
	{
		printf("*The BiTree is null\n");
		return ERROR;
	}
	if (T->root == NULL)
	{
		printf("*The BiTree is Empty\n");
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
		t=Sq[rear];
		t->index=keydex++;//visit
		if (t->lchild != NULL)//lchild is not null,enqueue
		{
			Sq[front++] = t->lchild;//lchild enqueue
			//printf("*lchild enqueue\n");
		}
		if (t->rchild != NULL)
		{
			Sq[front++] = t->rchild;//rchild enqueue
			//printf("*rchild enqueue\n");
		}
		rear++;//dequeue
		
	}
	printf("*LevelOrderTraverse Success\n");
	return OK;
}

status LevelOrderTraverse(BinaryTreePos&T, KeyType e,BiTPos&result)
{
	if(T==NULL)
	{
		printf("*The BiTree is null\n");
		return ERROR;
	}
	if (T->root == NULL)
	{
		printf("*The BiTree is Empty\n");
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
		t=Sq[rear];
		if(t->index==e)//visit
		{
			printf("*Found\n");
			result=t;
			return OK;
		}
		if (t->lchild != NULL)//lchild is not null,enqueue
		{
			Sq[front++] = t->lchild;//lchild enqueue
			//printf("*lchild enqueue\n");
		}
		if (t->rchild != NULL)
		{
			Sq[front++] = t->rchild;//rchild enqueue
			//printf("*rchild enqueue\n");
		}
		rear++;//dequeue
		
	}
	printf("*LevelOrderTraverse Success\n");
	printf("*Not Found\n");
	return ERROR;
}




BiTPos CreateBiTree1(int* pre_start, int* pre_end, int* in_start, int* in_end, int&size)
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
	root->value = 0;
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
		root->lchild = CreateBiTree1(pre_start + 1, left_preorder_end, in_start, root_inorder - 1, size);
	}

	int* right_preorder_start = left_preorder_end + 1;//前序遍历中右子树的最左边位置
	int right_length = pre_end - right_preorder_start + 1;

	if (right_length > 0)//构建右子树
	{
		root->rchild = CreateBiTree1(right_preorder_start, pre_end, root_inorder + 1, in_end, size);
	}

	return root;
}

BiTPos CreateBiTree2(int* post_start, int* post_end, int* in_start, int* in_end, int&size)
{
	//后序遍历的最后一个元素是根节点
	int root_value = *post_end;
	BiTPos root = (BiTPos)malloc(sizeof(struct BiTNode));
	if (!root)
	{
		printf("*OVERFLOW\n");
		exit(OVERFLOW);
	}
	root->lchild = NULL;
	root->rchild = NULL;
	root->index = root_value;
	root->value = 0;
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
	int* left_postorder_end = post_start + left_length-1;//后序遍历中左子树的最右边的位置

	if (left_length > 0)//构建左子树
	{
		//左子树的前序中序遍历序列的end指针都变化了
		root->lchild = CreateBiTree2(post_start, left_postorder_end, in_start, root_inorder - 1, size);
	}

	int* right_postorder_start = left_postorder_end + 1;//后序遍历中右子树的最左边位置
	int right_length = post_end - right_postorder_start;

	if (right_length > 0)//构建右子树
	{
		root->rchild = CreateBiTree2(right_postorder_start, post_end - 1, root_inorder + 1, in_end, size);
	}

	return root;
}


void CreateBiTree3(BiTPos&root, int &size,int&ch)
{
	scanf("%d",&ch);//input an node
	printf("*input success\n");
	if (ch ==0)root = NULL;
	else
	{
		root = (BiTPos)malloc(sizeof(struct BiTNode));//Generate root node
		if (!root)
		{
			printf("*OVERFLOW\n");
			exit(OVERFLOW);
		}
		size++;
		root->index = 0;
		root->lchild = NULL;
		root->rchild = NULL;
		root->value = ch;
		CreateBiTree3(root->lchild, size,ch);//Create left tree
		CreateBiTree3(root->rchild, size,ch);//Create right tree
	}
}

void CreateBiTree4(BiTPos&root,int&size,ElemType Array[],int&count)
{
	ElemType item=Array[count-1];
	count--;
	if(item==0)
	{
		root=NULL;
	}
	else
	{
		root=(BiTPos)malloc(sizeof(struct BiTNode));
		if(!root)
		{
			printf("*OVERFLOW\n");
			exit(OVERFLOW);
		}
		root->value=item;
		root->index=0;
		root->lchild=NULL;
		root->rchild=NULL;
		size++;
		CreateBiTree4(root->rchild,size,Array,count);//create right tree
		CreateBiTree4(root->lchild,size,Array,count);//create light tree
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
	printf("key:%d value:%d\n", node->index, node->value);
	return OK;
}

status visit(BiTPos&node,int&keydex)
{
	node->index=keydex++;
	return OK;
}

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
		//printf("*Empty\n");
		return TRUE;
	}
	else
	{
		//printf("*Not Empty\n");
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













