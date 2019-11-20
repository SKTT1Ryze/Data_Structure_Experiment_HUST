//���ݽṹ����һ
//test.cpp
#include <iostream>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
#include"LinearList.h"
#define ListNumber 10//��������Ա�������� 

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
int compare(ElemType x,ElemType e);
void visit(ElemType*e);
status ListSet(SqListP L);


int main(int argc,char*argv[])
{
	//������ 
	int op=1;
	ElemType e;
	int i=0;
	ElemType pre_e;
	ElemType next_e;
	ElemType cur;
	//�ļ���������
	FILE *fp;
	char writefilename[30];
	char readfilename[30];
	int j;
	//����һ�����Ա�����
	SqListP ListGroup[ListNumber];
	for(i=0;i<ListNumber;i++)
	{
		//Ϊÿ�����Ա������е�ÿ�����Ա����洢�ռ䲢��ʼ�� 
		ListGroup[i]=(SqListP)malloc(sizeof(SqList));
		ListGroup[i]->elem=NULL;
	} 
	SqListP L=ListGroup[0];//L��ʼ��Ϊ���Ա������еĵ�һ��Ԫ�� 
	int index=0;//index�洢��ǰ�����Ա��������е�λ�� 
	
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
		printf("    ��ѡ����Ĳ���[0~16]:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				//printf("\n----IntiList���ܴ�ʵ�֣�\n");
				if(InitList(L)==OK) printf("���Ա����ɹ���\n");
				else printf("���Ա���ʧ�ܣ�\n");
				getchar();
				getchar();
				break;
			case 2:
				//printf("\n----DestroyList���ܴ�ʵ�֣�\n");
				if(DestoryList(L)==OK)printf("���Ա�ɾ���ɹ�\n");
				else printf("���Ա�ɾ��ʧ�ܣ�\n");
				getchar();
				getchar();
				break;
			case 3:
				//printf("\n----ClearList���ܴ�ʵ�֣�\n");
				if(ClearList(L)==OK)printf("���Ա���ճɹ�\n");
				else printf("ʧ��\n");
				getchar();
				getchar();
				break;
			case 4:
				//printf("\n----ListEmpty���ܴ�ʵ�֣�\n"); 
				if(ListEmpty(L)==TRUE)printf("�ձ�\n");
				else printf("�ǿձ�\n"); 
				getchar();
				getchar();
				break;
			case 5:
				//printf("\n----ListLength���ܴ�ʵ�֣�\n");
				printf("��ĳ���Ϊ��%d\n",ListLength(L));
				getchar();
				getchar();
				break;
			case 6:
				//printf("\n----GetElem���ܴ�ʵ�֣�\n");
				printf("����i,i��ʾL�е�i��Ԫ�أ�");
				scanf("%d",&i);
				if(GetElem(L,i,& e)==OK)printf("��i��Ԫ�ص�ֵΪ��%d\n",e);
				else printf("ʧ��\n");
				getchar();
				getchar();
				break;
			case 7:
				//printf("\n----LocateElem���ܴ�ʵ�֣�\n");
				printf("����e��eΪĿ��ֵ��");
				scanf("%d",&e);
				printf("��һ������������λ��Ϊ��%d\n",LocateElem(L,e,compare) );
				getchar();
				getchar();
				break;
			case 8:
				//printf("\n----PriorElem���ܴ�ʵ�֣�\n");
				printf("����cur,���潫���cur��ǰ�� ��");
				scanf("%d",&cur);
				if(PriorElem(L,cur,pre_e)==OK)printf("ǰ��Ϊ��%d",pre_e);
				else printf("ʧ��\n");
				getchar();
				getchar();
				break;
			case 9:
				//printf("\n----NextElem���ܴ�ʵ�֣�\n");
				printf("����cur,���潫���cur�ĺ�����");
				scanf("%d",&cur);
				if(NextElem(L,cur,next_e)==OK)printf("����Ϊ��%d",next_e);
				else printf("ʧ��\n");
				getchar();
				getchar();
				break;
			case 10:
				//printf("\n----ListInsert���ܴ�ʵ�֣�\n");
				printf("����i��iΪ����Ԫ�ص�λ��");
				scanf("%d",&i);
				printf("����e��eΪ����Ԫ�ص�ֵ��");
				scanf("%d",&e);
				if(ListInsert(L,i,e)==OK)printf("����ɹ�");
				else printf("ʧ��\n");
				getchar();
				getchar();
				break;
			case 11:
				//printf("\n----ListDelete���ܴ�ʵ�֣�\n");
				printf("����i��iΪɾ��Ԫ�ص�λ��");
				scanf("%d",&i);
				if(ListDelete(L,i,&e)==OK)
				{
					printf("ɾ���ɹ�");
					printf("ɾ����Ԫ���ǣ�%d",e);
				} 
				else printf("ʧ��\n");
				getchar();
				getchar();
				break;
			case 12:
				//printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");
				if(ListTrabverse(L,visit)==OK)printf("�����ɹ�\n");
				else printf("ʧ��\n");
				getchar();
				getchar();
				break;
			case 13:
				if(L->elem==NULL)//�ж�L�Ƿ����
				{
					printf("���Ա�����\n");
					getchar();
					getchar();
		            break;
				}
				//save
				//д�ļ� 
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
				printf("�ļ�д��ɹ�");
				getchar();
				getchar();
				break;
			case 14:
				if(L->elem==NULL)//�ж�L�Ƿ����
				{
					printf("���Ա�����\n");
					getchar();
					getchar();
		            break;
				}
				//load
				//���ļ�
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
				printf("�ļ���ȡ�ɹ�");
				getchar();
				getchar();
				break;
			case 15:
				if(ListSet(L)==OK)printf("�ɹ�����\n");
				else printf("ʧ��\n");
				getchar();
				getchar();
				break;
			case 16:
				//�л����Ա�
				int tempdex;
				printf("������Ҫ�л������Ա������");
				scanf("%d",&tempdex);
				if(tempdex<0||tempdex>=ListNumber)//�������Ϸ� 
				{
					printf("OVERFLOW");
					getchar();
					getchar();
					break; 
				}
				index=tempdex;
				//printf("%d",index);
				if(ListGroup[index]->elem==NULL)//�����Ҫ�л������Ա����� 
					printf("���Ա�����,����InitList��������\n");
				L=ListGroup[index];//�л�
				printf("���Ա��л��ɹ�\n"); 
				getchar();
				getchar();
				break; 
			case 0:
				break;
				
		}//end of switch
		printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	}//end of while 
}

int compare(ElemType x,ElemType e)
{
	return x==e;
}

void visit(ElemType*e)
{
	printf("%d\t",*e);//��ӡ 
}
