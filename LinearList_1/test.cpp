//数据结构试验一
//test.cpp
#include <iostream>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
#include"LinearList.h"
#define ListNumber 10//管理多线性表的最大个数 

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
int compare(ElemType x,ElemType e);
void visit(ElemType*e);
status ListSet(SqListP L);


int main(int argc,char*argv[])
{
	//主函数 
	int op=1;
	ElemType e;
	int i=0;
	ElemType pre_e;
	ElemType next_e;
	ElemType cur;
	//文件变量定义
	FILE *fp;
	char writefilename[30];
	char readfilename[30];
	int j;
	//定义一个线性表数组
	SqListP ListGroup[ListNumber];
	for(i=0;i<ListNumber;i++)
	{
		//为每个线性表数组中的每个线性表分配存储空间并初始化 
		ListGroup[i]=(SqListP)malloc(sizeof(SqList));
		ListGroup[i]->elem=NULL;
	} 
	SqListP L=ListGroup[0];//L初始化为线性表数组中的第一个元素 
	int index=0;//index存储当前的线性表在数组中的位序 
	
	while(op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("------index of present LinearList:%d--------------\n",index);
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList       7. LocateElem\n");
		printf("    	  2. DestroyList    8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty     10. ListInsert\n");
		printf("    	  5. ListLength     11. ListDelete\n");
		printf("    	  6. GetElem       12. ListTrabverse\n");
		printf("    	  13.save           14.load\n");
		printf("    	  15.ListSet        16. ChangeList\n");
		printf("          0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~16]:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				//printf("\n----IntiList功能待实现！\n");
				if(InitList(L)==OK) printf("线性表创建成功！\n");
				else printf("线性表创建失败！\n");
				getchar();
				getchar();
				break;
			case 2:
				//printf("\n----DestroyList功能待实现！\n");
				if(DestoryList(L)==OK)printf("线性表删除成功\n");
				else printf("线性表删除失败！\n");
				getchar();
				getchar();
				break;
			case 3:
				//printf("\n----ClearList功能待实现！\n");
				if(ClearList(L)==OK)printf("线性表清空成功\n");
				else printf("失败\n");
				getchar();
				getchar();
				break;
			case 4:
				//printf("\n----ListEmpty功能待实现！\n"); 
				if(ListEmpty(L)==TRUE)printf("空表\n");
				else printf("非空表\n"); 
				getchar();
				getchar();
				break;
			case 5:
				//printf("\n----ListLength功能待实现！\n");
				printf("表的长度为：%d\n",ListLength(L));
				getchar();
				getchar();
				break;
			case 6:
				//printf("\n----GetElem功能待实现！\n");
				printf("输入i,i表示L中第i个元素：");
				scanf("%d",&i);
				if(GetElem(L,i,& e)==OK)printf("第i个元素的值为：%d\n",e);
				else printf("失败\n");
				getchar();
				getchar();
				break;
			case 7:
				//printf("\n----LocateElem功能待实现！\n");
				printf("输入e，e为目标值：");
				scanf("%d",&e);
				printf("第一个满足条件的位序为：%d\n",LocateElem(L,e,compare) );
				getchar();
				getchar();
				break;
			case 8:
				//printf("\n----PriorElem功能待实现！\n");
				printf("输入cur,下面将获得cur的前驱 ：");
				scanf("%d",&cur);
				if(PriorElem(L,cur,pre_e)==OK)printf("前驱为：%d",pre_e);
				else printf("失败\n");
				getchar();
				getchar();
				break;
			case 9:
				//printf("\n----NextElem功能待实现！\n");
				printf("输入cur,下面将获得cur的后驱：");
				scanf("%d",&cur);
				if(NextElem(L,cur,next_e)==OK)printf("后驱为：%d",next_e);
				else printf("失败\n");
				getchar();
				getchar();
				break;
			case 10:
				//printf("\n----ListInsert功能待实现！\n");
				printf("输入i，i为插入元素的位序：");
				scanf("%d",&i);
				printf("输入e，e为插入元素的值：");
				scanf("%d",&e);
				if(ListInsert(L,i,e)==OK)printf("插入成功");
				else printf("失败\n");
				getchar();
				getchar();
				break;
			case 11:
				//printf("\n----ListDelete功能待实现！\n");
				printf("输入i，i为删除元素的位序：");
				scanf("%d",&i);
				if(ListDelete(L,i,&e)==OK)
				{
					printf("删除成功");
					printf("删除的元素是：%d",e);
				} 
				else printf("失败\n");
				getchar();
				getchar();
				break;
			case 12:
				//printf("\n----ListTrabverse功能待实现！\n");
				if(ListTrabverse(L,visit)==OK)printf("遍历成功\n");
				else printf("失败\n");
				getchar();
				getchar();
				break;
			case 13:
				if(L->elem==NULL)//判断L是否存在
				{
					printf("线性表不存在\n");
					getchar();
					getchar();
		            break;
				}
				//save
				//写文件 
				printf("input file name:");
				scanf("%s",writefilename);
				if((fp=fopen(writefilename,"wb"))==NULL)
				{
					printf("File open erroe\n ");
					getchar();
					getchar();
					break;
				}
				fwrite(L->elem,sizeof(ElemType),L->length,fp);
				fclose(fp);
				printf("文件写入成功");
				getchar();
				getchar();
				break;
			case 14:
				if(L->elem==NULL)//判断L是否存在
				{
					printf("线性表不存在\n");
					getchar();
					getchar();
		            break;
				}
				//load
				//读文件
				printf("input file name:");
				scanf("%s",readfilename);
				L->length=0;
				if((fp=fopen(readfilename,"rb"))==NULL) 
				{
					printf("File open error\n ");
					getchar();
					getchar();
					break;
				}
				while(fread(&L->elem[L->length],sizeof(ElemType),1,fp))
					L->length++;
				fclose(fp);
				printf("文件读取成功");
				getchar();
				getchar();
				break;
			case 15:
				if(ListSet(L)==OK)printf("成功排序\n");
				else printf("失败\n");
				getchar();
				getchar();
				break;
			case 16:
				//切换线性表
				int tempdex;
				printf("输入想要切换的线性表的索引");
				scanf("%d",&tempdex);
				if(tempdex<0||tempdex>=ListNumber)//索引不合法 
				{
					printf("OVERFLOW");
					getchar();
					getchar();
					break; 
				}
				index=tempdex;
				//printf("%d",index);
				if(ListGroup[index]->elem==NULL)//如果想要切换的线性表不存在 
					printf("线性表不存在,请用InitList函数创建\n");
				L=ListGroup[index];//切换
				printf("线性表切换成功\n"); 
				getchar();
				getchar();
				break; 
			case 0:
				break;
				
		}//end of switch
		printf("欢迎下次再使用本系统！\n");
	}//end of while 
}

int compare(ElemType x,ElemType e)
{
	return x==e;
}

void visit(ElemType*e)
{
	printf("%d\t",*e);//打印 
}
