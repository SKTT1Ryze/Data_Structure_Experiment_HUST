#include<stdio.h>
#include<stdlib.h>
#include"BiTreeADT.h"


#define MaxTreeNumner 10
#define MaxNodeSize 100
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
status PreOrderTraverse(BinaryTreePos&T, int*key_save,int*value_save,int&size);
status PreOrderTraverse(BinaryTreePos&T, int*value);
status InOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node));
status InOrderTraverse(BinaryTreePos&T,int*key_save,int*value_save,int&size);
status PostOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node));
status PostOrderTraverse(BinaryTreePos&T, KeyType e,BiTPos&dad,int&isleft);
status PostOrderTraverse(BinaryTreePos&T,KeyType delkey);
status LevelOrderTraverse(BinaryTreePos&T, status(*visit)(BiTPos&node));
status LevelOrderTraverse(BinaryTreePos&T, int&keydex);
status LevelOrderTraverse(BinaryTreePos&T, KeyType e,BiTPos&result);
BiTPos CreateBiTree1(int* pre_start, int* pre_end, int* in_start, int* in_end, int&size);
BiTPos CreateBiTree2(int* post_start, int* post_end, int* in_start, int* in_end, int&size);
void CreateBiTree3(BiTPos&root, int&size,int&ch);
void CreateBiTree4(BiTPos&root,int&size,ElemType Array[],int&count);
void Destroy(BiTPos&root);
status visit(BiTPos&node);
status Show(BinaryTreePos&T);

int main(int argc, char *argv[])
{
	int op = 1;
	int i = 0;
	int definition = 1;
	
	KeyType e=0;
	BiTPos result=NULL;
	ElemType value=0;

	BiTPos c=NULL;

	int LR=0;
	
	BinaryTreePos TreeGroup[MaxTreeNumner];
	for (i = 0; i < MaxTreeNumner; i++)//Initilaze
	{
		TreeGroup[i]=NULL;
	}
	BinaryTreePos *T = &TreeGroup[0];//T is the first tree
	int index=0;
	
	//define file pointer
	FILE *fp;
	char writeFileName[30];
	char readFileName[30];
	
	int preKeyGroup[MaxNodeSize];
	int inKeyGroup[MaxNodeSize];
	int preValueGroup[MaxNodeSize];
	int inValueGroup[MaxNodeSize];
	int*pre_key=preKeyGroup;
	int*in_key=inKeyGroup;
	int*pre_value=preValueGroup;
	int*in_value=inValueGroup;
	int pre_size=0;
	int in_size=0;
	int*temp=NULL;
	
	for(i=0;i<MaxNodeSize;i++)
	{
		preKeyGroup[i]=0;
		inKeyGroup[i]=0;
		preValueGroup[i]=0;
		inValueGroup[i]=0;
	}
	
	
	
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
		printf("          -1.dir               -2.Show\n");
		printf("-------------------------------------------------\n");
		printf("    ÇëÑ¡ÔñÄãµÄ²Ù×÷[-2~17]:");
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
			printf(" *Return:BiTPos\n");
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
			printf(" *Parameter:BinaryTreePos&T, KeyType e, ElemType value\n");
			printf(" *Return:int\n");
			printf(" *Use:find the node with key e in the BiTree\n");
			printf(" *and change the value\n*/\n");
			printf("*Input the Key:");
			scanf("%d",&e);
			printf("*Input the value:\n");
			scanf("%d",&value);
			if(Assign(*T,e,value)==OK)
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
		case 8:
			printf("Your choise:8\n");
			printf("/*\n *Function Name:GetSibling\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T, KeyType e\n");
			printf(" *Return:BiTPos\n");
			printf(" *Use:find the node with key e in BiTree\n*/\n");
			printf(" *if node have lchild,return,else if have rchild\n*/\n");
			printf(" *return,else return null\n*/\n");
			printf("*Input the Key:");
			scanf("%d",&e);
			result=GetSibling(*T,e);
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
		case 9:
			printf("Your choise:9\n");
			printf("/*\n *Function Name:InsertNode\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T, KeyType e, int LR, BiTPos&c\n");
			printf(" *Return:status\n");
			printf(" *Use:insert a node \n*/\n");
			c=(BiTPos)malloc(sizeof(BiTNode));
			if(!c)
			{
				printf("*Space Call Error\n");
				getchar();
				getchar();
				break;
			}
			c->index=0;
			c->lchild=NULL;
			c->rchild=NULL;
			printf("*input the value of the node:");
			scanf("%d",&(c->value));
			printf("*Input the Key:");
			scanf("%d",&e);
			printf("*LR:0 or 1: ");
			scanf("%d",&LR);
			if(InsertNode(*T,e,LR,c)==OK)
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
		case 10:
			printf("Your choise:10\n");
			printf("/*\n *Function Name:DeleteNode\n");
			printf(" *Module:Data structures\n");
			printf(" *Parameter:BinaryTreePos&T, KeyType e\n");
			printf(" *Return:status\n");
			printf(" *Use:delete the node with key e\n*/\n");
			printf("*Input the key:");
			scanf("%d",&e);
			if(DeleteNode(*T,e)==OK)
			{
				printf("*Operator Success\n");
				(*T)->size--;
			}
			else
			{
				printf("*Operator Error\n");
			}
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
			printf(" *Use:save the BiTree as file\n*/\n");
			if(*T==NULL)//BiTree is NULL
			{
				printf("*The BiTree is NULL\n");
				getchar();
				getchar();
				break;
			}
			//save
			printf("*FileName:");
			scanf("%s",writeFileName);//input file name
			if((fp=fopen(writeFileName,"wb"))==NULL)
			{
				printf("*File open error\n");
				getchar();
				getchar();
				break;
			}
			pre_key=preKeyGroup;
			in_key=inKeyGroup;
			pre_value=preValueGroup;
			in_value=inValueGroup;
			
			if((PreOrderTraverse(*T,pre_key,pre_value,pre_size))==OK)
			{
				printf("*save_pre success\n");
				*(pre_key+pre_size)=-1;
				pre_size++;
				for(i=0;i<pre_size;i++)
				{
					printf("%d,%d\t",preKeyGroup[i],preValueGroup[i]);
				}
				printf("\n");
			}
			if((InOrderTraverse(*T,in_key,in_value,in_size))==OK)
			{
				printf("*save_in success\n");
				*(in_key+in_size)=-1;
				in_size++;
				for(i=0;i<in_size;i++)
				{
					printf("%d,%d\t",inKeyGroup[i],inValueGroup[i]);
				}
				printf("\n");
			}
			pre_key=preKeyGroup;
			in_key=inKeyGroup;
			pre_value=preValueGroup;
			in_value=inValueGroup;
			for(i=0;i<pre_size;i++)
			{
				fwrite(pre_key+i,sizeof(int),1,fp);
				fwrite(pre_value+i,sizeof(int),1,fp);
			}
			for(i=0;i<in_size;i++)
			{
				fwrite(in_key+i,sizeof(int),1,fp);
				fwrite(in_value+i,sizeof(int),1,fp);
			}
			fclose(fp);
			printf("*Save File Success\n");
			getchar();
			getchar();
			break;
		case 16:
			printf("Your choise:16\n");
			printf("/*\n *Function Name:LoadBiTree\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:load the BiTree from a file\n*/\n");
			
			//load
			printf("*FileName:");
			scanf("%s",readFileName);//input file name
			if((fp=fopen(readFileName,"rb"))==NULL)
			{
				printf("*File open error\n");
				getchar();
				getchar();
				break;
			}
			for(i=0;i<MaxNodeSize;i++)
			{
				preKeyGroup[i]=0;
				inKeyGroup[i]=0;
				preValueGroup[i]=0;
				inValueGroup[i]=0;
			}
			pre_key=preKeyGroup;
			in_key=inKeyGroup;
			pre_value=preValueGroup;
			in_value=inValueGroup;
			i=0;
			do
			{
				fread(pre_key+i,sizeof(int),1,fp);
				fread(pre_value+i,sizeof(int),1,fp);
				i++;
			
			}while(*(pre_key+i-1)!=-1);
			printf("*pre_load success\n");
			i=0;
			do
			{
				fread(in_key+i,sizeof(int),1,fp);
				fread(in_value+i,sizeof(int),1,fp);
				i++;
			
			}while(*(in_key+i-1)!=-1);
			printf("*in_load success\n");
			
			pre_size=0;
			in_size=0;
			i=0;
			while(preKeyGroup[i]!=-1)
			{
				i++;
				pre_size++;
			}
			i=0;
			while(inKeyGroup[i]!=-1)
			{
				i++;
				in_size++;
			}
			for(i=0;i<pre_size;i++)
			{
				printf("%d,%d\t",preKeyGroup[i],preValueGroup[i]);
			}
			
			printf("\n");
			printf("*Load Success\n");
			fclose(fp);
			if(*T)
			{
				DestroyBiTree(*T);
				printf("*Destroy Tree\n");
			}
			*T=(BinaryTreePos)malloc(sizeof(BinaryTree));
			(*T)->size=0;
			(*T)->id=index;
			(*T)->root=NULL;
			(*T)->root=CreateBiTree1(pre_key,&preKeyGroup[pre_size-1],in_key,&inKeyGroup[in_size-1],(*T)->size);
			if((*T)->root)
			{
				if(PreOrderTraverse(*T,preValueGroup)==OK)
				{
					printf("*Assign Value Success\n");
				}
				else
				{
					printf("*Assign Value Error\n");
				}
				printf("*Create Success\n");
			}
			else
			{
				printf("*Create Error\n");
			}
			getchar();
			getchar();
			break;
		case 17:
			printf("Your choise:17\n");
			printf("/*\n *Function Name:ChangeBiTree\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:chage BiTree\n*/\n");
			printf("*Index:");
			scanf("%d",&index);
			T=&TreeGroup[index];
			printf("*Change Success\n");	
			getchar();
			getchar();
			break;
		case -1:
			system("dir");
			getchar();
			getchar();
			break;
		case -2:
			Show(*T);
			getchar();
			getchar();
			break;
		case 0:
			break;
		}//end of switch
		printf("Welcome next time");
	}//end of while
}


