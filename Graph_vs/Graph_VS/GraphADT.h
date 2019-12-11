#pragma once
//Graph head file
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//define return value
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
typedef int status;
typedef int ElemType;//type of data

typedef struct ArcNode
{
	int vex_index;
	struct ArcNode *nextarc;
	int weight;
}arcnode;

typedef struct VexNode
{
	int index;
	ElemType value;
	arcnode *first_arc;
	struct VexNode	*nextvex;
}vexnode;

typedef struct Graph
{
	int id;
	vexnode *first_vex;
	int vex_num;
	int arc_num;
}G,*GPos;

//Functions Declaration
status CreateGraph(GPos&G, int*vex, int*vex_arc);
status DestroyGraph(GPos&G);
status LocateVex(GPos&G, int u);
status PutVex(GPos&G, int u, ElemType value);
vexnode* FirstAdjVex(GPos&G, int u);
void DeleteLink(arcnode*head);



status CreateGraph(GPos&G, int*vex, int*vex_arc)
{
	//Graph NULL
	if (G == NULL)
	{
		printf("*The Graph struct is NULL\n");
		return ERROR;
	}
	if (G->first_vex != NULL)
	{
		printf("*The Graph is not NULL\n");
		return ERROR;
	}
	int vex_num = 0;
	int arc_num = 0;
	int i = 0;
	int *pos = vex;
	vexnode* vex_temp = NULL;
	vexnode* vex_travel = NULL;
	arcnode* arc_travel = NULL;
	arcnode* arc_temp = NULL;
	while (pos[i++]!= -1)
	{
		vex_num++;
		//pos++;
	}
	printf("*vex num:%d\n", vex_num);
	G->vex_num = vex_num;
	pos = vex_arc;
	i = 0;
	while (pos[i] != -1)
	{
		arc_num++;
		i += 2;
		//pos += 2;
	}
	printf("*arc num:%d\n", arc_num);
	G->arc_num = arc_num;
	if (vex_num == 0 || arc_num == 0)
	{
		printf("*input null\n");
		return ERROR;
	}
	i = 0;
	vex_temp = (vexnode*)malloc(sizeof(vexnode));
	if (!vex_temp)
	{
		printf("*overflow\n");
		exit(OVERFLOW);
	}
	vex_temp->index = *(vex + i);
	vex_temp->value = 0;
	vex_temp->first_arc = NULL;
	vex_temp->nextvex = NULL;
	G->first_vex = vex_temp;
	vex_travel = G->first_vex;
	for (i = 1; i < vex_num; i++)
	{
		vex_temp = (vexnode*)malloc(sizeof(vexnode));
		if (!vex_temp)
		{
			printf("*overflow\n");
			exit(OVERFLOW);
		}
		vex_temp->index = *(vex + i);
		vex_temp->value = 0;
		vex_temp->first_arc = NULL;
		vex_temp->nextvex = NULL;
		vex_travel->nextvex = vex_temp;
		vex_travel = vex_travel->nextvex;
	}
	vex_travel = G->first_vex;
	while (vex_travel)
	{
		printf("index:%d,value:%d\n", vex_travel->index, vex_travel->value);
		vex_travel = vex_travel->nextvex;
	}
	printf("*vex create success\n");
	int vex_index = 0;
	int arc_index = 0;
	for (i = 0; i < arc_num; i++)
	{
		vex_index = *(vex_arc + i * 2);
		arc_index = *(vex_arc + i * 2 + 1);
		printf("vex_index:%d,arc_index:%d\n", vex_index, arc_index);
		vex_travel = G->first_vex;
		while (vex_travel&&vex_travel->index != vex_index)
			vex_travel = vex_travel->nextvex;
		if (!vex_travel)
		{
			printf("*input error,VR has V not in V\n");
			return ERROR;
		}
		if (vex_travel->first_arc == NULL)
		{
			printf("*the first arc\n");
			vex_travel->first_arc = (arcnode*)malloc(sizeof(arcnode));
			if (vex_travel->first_arc == NULL)
			{
				printf("*overflow\n");
				exit(OVERFLOW);
			}
			vex_travel->first_arc->vex_index = arc_index;
			vex_travel->first_arc->nextarc = NULL;
			vex_travel->first_arc->weight = 1;
			printf("*first arc create success\n");
		}
		else
		{
			arc_travel = vex_travel->first_arc;
			while (arc_travel&&arc_travel->nextarc)
				arc_travel = arc_travel->nextarc;
			arc_temp = (arcnode*)malloc(sizeof(arcnode));
			if (arc_temp == NULL)
			{
				printf("*overflow\n");
				exit(OVERFLOW);
			}
			arc_temp->vex_index = arc_index;
			arc_temp->nextarc = NULL;
			arc_temp->weight = 1;
			arc_travel->nextarc = arc_temp;
			printf("*arc create success\n");
		}
	}
	//Travel
	printf("*Graph create success\n");
	return OK;
}

status DestroyGraph(GPos&G)
{
	//Graph NULL
	if (G == NULL)
	{
		printf("*The Graph struct is NULL\n");
		return ERROR;
	}
	if (G->first_vex == NULL)
	{
		printf("*The Graph is NULL\n");
		return ERROR;
	}
	vexnode*vex_pos = G->first_vex;
	while (vex_pos)
	{
		DeleteLink(vex_pos->first_arc);
		vex_pos->first_arc = NULL;
		vex_pos = vex_pos->nextvex;
	}
	vex_pos = G->first_vex;
	vexnode* vex_temp = NULL;
	do
	{
		vex_temp = vex_pos->nextvex;
		free(vex_pos);
		vex_pos = vex_temp;
	} while (vex_pos);
	G->first_vex = NULL;
	printf("*Destroy success\n");
	return OK;
}

status LocateVex(GPos&G, int u)
{
	return ERROR;
}

status PutVex(GPos&G, int u, ElemType value)
{
	//Graph NULL
	if (G == NULL)
	{
		printf("*The Graph struct is NULL\n");
		return ERROR;
	}
	if (G->first_vex == NULL)
	{
		printf("*The Graph is NULL\n");
		return ERROR;
	}
	vexnode*vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != u)
		vex_pos = vex_pos->nextvex;
	if (!vex_pos)
	{
		printf("*Not Found\n");
		return ERROR;
	}
	vex_pos->value = value;
	printf("*Assign success:%d\n", value);
	return OK;
}

vexnode* FirstAdjVex(GPos&G, int u)
{
	//Graph NULL
	if (G == NULL)
	{
		printf("*The Graph struct is NULL\n");
		return ERROR;
	}
	if (G->first_vex == NULL)
	{
		printf("*The Graph is NULL\n");
		return ERROR;
	}
	vexnode*vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != u)
		vex_pos = vex_pos->nextvex;
	if (!vex_pos)
	{
		printf("*Not Found\n");
		return ERROR;
	}
	if (vex_pos->first_arc == NULL)
	{
		printf("*dont have adj\n");
		return NULL;
	}
	int first_adj_index = vex_pos->first_arc->vex_index;
	vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != first_adj_index)
		vex_pos = vex_pos->nextvex;
	if (!vex_pos)
	{
		printf("*Not Found\n");
		return ERROR;
	}
	return vex_pos;
}

vexnode* NextAdjVex(GPos&G, int v, int w)
{
	//Graph NULL
	if (G == NULL)
	{
		printf("*The Graph struct is NULL\n");
		return ERROR;
	}
	if (G->first_vex == NULL)
	{
		printf("*The Graph is NULL\n");
		return ERROR;
	}
	vexnode*vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != v)
		vex_pos = vex_pos->nextvex;
	if (!vex_pos)
	{
		printf("*Not Found\n");
		return ERROR;
	}
	if (vex_pos->first_arc == NULL)
	{
		printf("*dont have adj\n");
		return NULL;
	}
	int i = 0;
	arcnode* arc_pos = vex_pos->first_arc;
	while (arc_pos&&i < w)
	{
		arc_pos = arc_pos->nextarc;
		i++;
	}
	if (arc_pos == NULL)
	{
		printf("*Not Found\n");
		return NULL;
	}
	if (arc_pos->nextarc == NULL)
	{
		printf("*the last adj\n");
		return NULL;
	}
	int adj_index = arc_pos->nextarc->vex_index;
	vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != adj_index)
	{
		vex_pos = vex_pos->nextvex;
	}
	if (!vex_pos)
	{
		printf("*Not Found\n");
		return NULL;
	}
	return vex_pos;
}








void DeleteLink(arcnode*head)
{
	if (head == NULL)return;
	arcnode *temp = NULL;
	arcnode *travel = head;
	do
	{
		temp = travel->nextarc;
		free(travel);
		travel = temp;
	} while (travel);
	return;
}

