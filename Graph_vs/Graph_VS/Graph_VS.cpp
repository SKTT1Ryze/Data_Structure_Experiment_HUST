#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include"GraphADT.h"
//define return value
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define max_vex 100
#define max_arc 200
#define max_graph 10
//Functions Declaration
status CreateGraph(GPos&G, int*vex, int*vex_arc);
status DestroyGraph(GPos&G);
void DeleteLink(arcnode*head);




int main(int argc,char *argv[])
{
	int op = 1;
	int index = 0;
	int vex[max_vex];
	int vex_arc[max_arc];
	int i = 0;
	int vex_temp = 0;
	int arc_temp = 0;
	GPos GraphGroup[max_graph];
	for (i = 0; i < max_graph; i++)
	{
		GraphGroup[i] = (GPos)malloc(sizeof(G));
		if (!GraphGroup[i])
		{
			printf("*overflow\n");
			exit(OVERFLOW);
		}
		GraphGroup[i]->arc_num = 0;
		GraphGroup[i]->first_vex = NULL;
		GraphGroup[i]->id = i;
		GraphGroup[i]->vex_num = 0;
	}
	GPos *G = &GraphGroup[0];

	for (i = 0; i < max_vex; i++)
		vex[i] = 0;
	for (i = 0; i < max_arc; i++)
		vex_arc[i] = 0;

	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("------------index of present Graph:%d-------------\n", index);
		printf("-------------------------------------------------\n");
		printf("    	  1. CreateGraph      2. DestroyGraph\n");
		printf("    	  3. LocateVex        4. PutVex\n");
		printf("    	  5. FirstAdjVex      6. NextAdjVex \n");
		printf("    	  7. InsertVex        8. DeleteVex\n");
		printf("    	  9. InsertArc        10. DeleteArc\n");
		printf("    	  11. DFSTraverse     12. BFSTraverse\n");
		printf("    	  13.save             14.load\n");
		printf("    	  15.                 16.      \n");
		printf("          17.                 0. Exit\n");
		printf("          -1.dir\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[-1~17]:");
		scanf_s("%d", &op);
		switch (op)
		{
		case 1:
			printf("Your choise:1\n");
			printf("/*\n *Function Name:CreateGraph\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:Create a Graph\n*/\n");
			printf("*input vex set with positive int,end with -1\n");
			i = 0;
			do
			{
				scanf_s("%d", &vex_temp);
				if (vex_temp == -1)
				{
					printf("*input end\n");
					vex[i++] = vex_temp;
					break;
				}
				if (vex_temp <= 0)
				{
					printf("*input error\n");
					continue;
				}
				vex[i++] = vex_temp;
				if (i >= max_vex - 1)
				{
					printf("*input overflow\n");
					break;
				}
			} while (1);
			i = 0;
			printf("*input vex_arc set with positive int,end with -1\n");
			while (1)
			{
				scanf_s("%d", &arc_temp);
				if (arc_temp == -1)
				{
					printf("*input end\n");
					vex_arc[i++] = arc_temp;
					break;
				}
				if (arc_temp <= 0)
				{
					printf("*input error\n");
					continue;
				}
				vex_arc[i++] = arc_temp;
				if (i >= max_arc - 1)
				{
					printf("*input overflow\n");
					break;
				}
			}
			if (CreateGraph(*G, vex, vex_arc) == OK)
			{
				printf("*Operator Success\n");
			}
			else
			{
				printf("*Operator ERROR\n");
			}
			getchar();
			getchar();
			break;
		case 2:
			printf("Your choise:2\n");
			printf("/*\n *Function Name:DestroyGraph\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:destroy the Graph\n*/\n");
			if (DestroyGraph(*G) == OK)
			{
				printf("*Operator Success\n");
			}
			else
			{
				printf("*Operator ERROR\n");
			}
			getchar();
			getchar();
			break;
		case 3:
			printf("Your choise:3\n");
			printf("/*\n *Function Name:LocateVex\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:locate the vex node\n*/\n");
			
			getchar();
			getchar();
			break;
		case 4:
			printf("Your choise:4\n");
			printf("/*\n *Function Name:PutVex\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:Assign the value of the vex node\n*/\n");
			
			getchar();
			getchar();
			break;
		case 5:
			printf("Your choise:5\n");
			printf("/*\n *Function Name:FirstAdjVex\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:return first adjvex of the vex node\n*/\n");
		
			getchar();
			getchar();
			break;
		case 6:
			printf("Your choise:6\n");
			printf("/*\n *Function Name:NextAdjVex\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:get the next adjvex\n*/\n");
			
			getchar();
			getchar();
			break;
		case 7:
			printf("Your choise:7\n");
			printf("/*\n *Function Name:InsertVex\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:Insert a vex node\n");
			
			getchar();
			getchar();
			break;
		case 8:
			printf("Your choise:8\n");
			printf("/*\n *Function Name:DeleteVex\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:Delete a vex node\n*/\n");
			
			getchar();
			getchar();
			break;
		case 9:
			printf("Your choise:9\n");
			printf("/*\n *Function Name:InsertArc\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:Insert an arc node\n*/\n");
			
			getchar();
			getchar();
			break;
		case 10:
			printf("Your choise:10\n");
			printf("/*\n *Function Name:DeleteArc\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:Delete an arc node\n*/\n");
			
			getchar();
			getchar();
			break;
		case 11:
			printf("Your choise:11\n");
			printf("/*\n *Function Name:DFSTraverse\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:Travel the Graph in DFS order\n*/\n");
			
			getchar();
			getchar();
			break;
		case 12:
			printf("Your choise:12\n");
			printf("/*\n *Function Name:BFSTraverse\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:Travle the Graph in BFS order\n*/\n");
			
			getchar();
			getchar();
			break;
		case 13:
			printf("Your choise:13\n");
			printf("/*\n");
			printf(" *Function Name:save\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:save this Graph as a file\n");
			
			getchar();
			getchar();
			break;
		case 14:
			printf("Your choise:14\n");
			printf("/*\n");
			printf(" *Function Name:Load\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:Load a Graph from a file\n");
			printf("*/\n");
			
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
			
			getchar();
			getchar();
			break;
		case 16:
			printf("Your choise:16\n");
			printf("/*\n *Function Name:ChangeList\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:change the LinearList\n*/\n");
			
			getchar();
			getchar();
			break;
		case 17:
			printf("Your choise:17\n");
			printf("/*\n *Function Name:\n");
			printf(" *Module:Data structures\n");
			printf(" *Use:\n*/\n");
			
			getchar();
			getchar();
			break;
		case 0:
			break;
		case -1:
			
			getchar();
			getchar();
			break;

		}//end of switch
		printf("Welcome next time");
	}//end of while

}//end of main function



