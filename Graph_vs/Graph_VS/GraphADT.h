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
#define OVERFLOW -1
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
	struct ArcNode *first_arc;
	struct VexNode	*nextvex;
}vexnode;

typedef struct Graph
{
	int id;
	struct VexNode *first_vex;
	int vex_num;
	int arc_num;
}G, *GPos;

int visited[100];
vexnode*Queue[100];
//Functions Declaration
status CreateGraph(GPos&G, int*vex, int*vex_arc);
status DestroyGraph(GPos&G);
int LocateVex(GPos&G, int u);
status PutVex(GPos&G, int u, ElemType value);
int FirstAdjVex(GPos&G, int u);
int NextAdjVex(GPos&G, int v, int w);
status InsertVex(GPos&G, vexnode*v);
status DeleteVex(GPos&G, int v);
status InsertArc(GPos&G, int v, int w);
status DeleteArc(GPos&G, int v, int w);
status DFSTraverse(GPos&G, void(*visit)(vexnode*vex));
status BFSTraverse(GPos&G, void(*visit)(vexnode*vex));
status print_AdjList(GPos&G);
void DeleteLink(arcnode*head);
void DFS(GPos&G, vexnode*vex, void(*visit)(vexnode*vex));
void BFS(GPos&G, void(*visit)(vexnode*vex));
void visit(vexnode*vex);


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
	while (pos[i++] != -1)
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

int LocateVex(GPos&G, int u)
{
	//Graph NULL
	if (G == NULL)
	{
		printf("*The Graph struct is NULL\n");
		return -1;
	}
	if (G->first_vex == NULL)
	{
		printf("*The Graph is NULL\n");
		return -1;
	}
	int i = 0;
	vexnode*vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != u)
	{
		vex_pos = vex_pos->nextvex;
		i++;
	}
	if (!vex_pos)
	{
		printf("*Not Found\n");
		return -1;
	}
	printf("*Found\n");
	return i;
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
	printf("*Found\n");
	vex_pos->value = value;
	printf("*Assign success:%d\n", value);
	return OK;
}

int FirstAdjVex(GPos&G, int u)
{
	//Graph NULL
	if (G == NULL)
	{
		printf("*The Graph struct is NULL\n");
		return -1;
	}
	if (G->first_vex == NULL)
	{
		printf("*The Graph is NULL\n");
		return -1;
	}
	vexnode*vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != u)
		vex_pos = vex_pos->nextvex;
	if (!vex_pos)
	{
		printf("*Not Found u\n");
		return -1;
	}
	printf("*Found u\n");
	if (vex_pos->first_arc == NULL)
	{
		printf("*dont have adj\n");
		return -1;
	}
	int first_adj_index = vex_pos->first_arc->vex_index;
	vex_pos = G->first_vex;
	int i = 0;
	while (vex_pos&&vex_pos->index != first_adj_index)
	{
		vex_pos = vex_pos->nextvex;
		i++;
	}
	if (!vex_pos)
	{
		printf("*Not Found\n");
		return -1;
	}
	//printf("*Found\n");
	return i;
}

int NextAdjVex(GPos&G, int v, int w)
{
	//Graph NULL
	if (G == NULL)
	{
		printf("*The Graph struct is NULL\n");
		return -1;
	}
	if (G->first_vex == NULL)
	{
		printf("*The Graph is NULL\n");
		return -1;
	}
	vexnode*vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != v)
		vex_pos = vex_pos->nextvex;
	if (!vex_pos)
	{
		printf("*Not Found v\n");
		return -1;
	}
	printf("*Found v\n");
	if (vex_pos->first_arc == NULL)
	{
		printf("*dont have adj\n");
		return -1;
	}
	arcnode* arc_pos = vex_pos->first_arc;
	while (arc_pos&&arc_pos->vex_index != w)
		arc_pos = arc_pos->nextarc;
	if (arc_pos == NULL)
	{
		printf("*Not Found w\n");
		return -1;
	}
	printf("*Found w\n");
	if (arc_pos->nextarc == NULL)
	{
		printf("*the last adj\n");
		return -1;
	}
	int adj_index = arc_pos->nextarc->vex_index;
	vex_pos = G->first_vex;
	int i = 0;
	while (vex_pos&&vex_pos->index != adj_index)
	{
		vex_pos = vex_pos->nextvex;
		i++;
	}
	if (!vex_pos)
	{
		printf("*Not Found\n");
		return -1;
	}
	return i;
}

status InsertVex(GPos&G, vexnode*v)
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
	while (vex_pos->nextvex&&vex_pos)
		vex_pos = vex_pos->nextvex;
	vex_pos->nextvex = v;
	printf("*Insert vex success\n");
	return OK;
}

status DeleteVex(GPos&G, int v)
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
	if (vex_pos == NULL)
	{
		printf("*Not Found\n");
		return ERROR;
	}
	printf("*Found\n");
	DeleteLink(vex_pos->first_arc);
	vex_pos->first_arc = NULL;
	if (vex_pos == G->first_vex)
	{
		//the first vex node
		printf("*the first vex node\n");
		G->first_vex = vex_pos->nextvex;
		free(vex_pos);
		vex_pos = NULL;
	}
	else
	{
		vexnode*vex_pre = G->first_vex;
		while (vex_pre->nextvex&&vex_pre->nextvex->index != v)
			vex_pre = vex_pre->nextvex;
		vex_pre->nextvex = vex_pos->nextvex;
		free(vex_pos);
		vex_pos = NULL;
	}
	vex_pos = G->first_vex;
	arcnode*arc_pos = NULL;
	arcnode*arc_pre = NULL;
	while (vex_pos)
	{
		arc_pos = vex_pos->first_arc;
		while (arc_pos)
		{
			if (arc_pos->vex_index == v)
			{
				if (arc_pos == vex_pos->first_arc)
				{
					//the first arc node
					printf("*the first arc node\n");
					vex_pos->first_arc = arc_pos->nextarc;
					free(arc_pos);
					arc_pos = vex_pos->first_arc;
				}
				else
				{
					arc_pre->nextarc = arc_pos->nextarc;
					free(arc_pos);
					arc_pos = arc_pre->nextarc;
				}
				continue;
			}
			arc_pre = arc_pos;
			arc_pos = arc_pos->nextarc;
		}
		vex_pos = vex_pos->nextvex;


	}
	printf("*Delete vex success\n");
	return OK;
}

status InsertArc(GPos&G, int v, int w)
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
	while (vex_pos&&vex_pos->index != w)
		vex_pos = vex_pos->nextvex;
	if (!vex_pos)
	{
		printf("*the node w dont exist\n");
		return ERROR;
	}
	printf("*Found w\n");
	vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != v)
		vex_pos = vex_pos->nextvex;
	if (!vex_pos)
	{
		printf("*the node v dont exist\n");
		return ERROR;
	}
	printf("*Found v\n");
	arcnode*arc_pos = vex_pos->first_arc;
	if (arc_pos == NULL)
	{
		//dont have arc node
		printf("*dont have arc node yet\n");
		arc_pos = (arcnode*)malloc(sizeof(arcnode));
		if (arc_pos == NULL)
		{
			printf("*overflow\n");
			exit(OVERFLOW);
		}
		arc_pos->nextarc = NULL;
		arc_pos->vex_index = w;
		arc_pos->weight = 1;
		vex_pos->first_arc = arc_pos;
	}
	else
	{
		while (arc_pos&&arc_pos->nextarc)
			arc_pos = arc_pos->nextarc;
		arc_pos->nextarc = (arcnode*)malloc(sizeof(arcnode));
		arc_pos->nextarc->nextarc = NULL;
		arc_pos->nextarc->vex_index = w;
		arc_pos->weight = 1;
	}
	printf("*Insert arc success\n");
	return OK;
}

status DeleteArc(GPos&G, int v, int w)
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
		printf("*the vex node v dont exist\n");
		return ERROR;
	}
	printf("*Found v\n");
	if (vex_pos->first_arc == NULL)
	{
		printf("*dont have v_w\n");
		return ERROR;
	}
	arcnode*arc_pos = vex_pos->first_arc;
	while (arc_pos&&arc_pos->vex_index != w)
		arc_pos = arc_pos->nextarc;
	if (!arc_pos)
	{
		printf("*dont have v_w\n");
		return ERROR;
	}
	printf("*Found v_w\n");
	if (arc_pos == vex_pos->first_arc)
	{
		//the first arc node
		vex_pos->first_arc = arc_pos->nextarc;
		free(arc_pos);
		arc_pos = NULL;
		printf("*Delete arc success\n");
		return OK;
	}
	arcnode*arc_pre = vex_pos->first_arc;
	while (arc_pre&&arc_pre->nextarc&&arc_pre->nextarc->vex_index != w)
		arc_pre = arc_pre->nextarc;
	arc_pre->nextarc = arc_pos->nextarc;
	free(arc_pos);
	arc_pos = NULL;
	printf("*Delete arc success\n");
	return OK;
}

status DFSTraverse(GPos&G, void(*visit)(vexnode*vex))
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
	int i = 0;
	while (i < 100)
	{
		visited[i] = 0;
		i++;
	}
	printf("*from ? vex node begin:");
	int begin_index = 0;
	scanf_s("%d", &begin_index);
	vexnode*vex_pos = G->first_vex;
	while (vex_pos&&vex_pos->index != begin_index)
		vex_pos = vex_pos->nextvex;
	if (vex_pos == NULL)
	{
		printf("*input wrong,the vex node dont exist\n");
		return ERROR;
	}
	DFS(G, vex_pos, visit);
	printf("*DFS Traverse success\n");
	return OK;
}

status BFSTraverse(GPos&G, void(*visit)(vexnode*vex))
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
	int i = 0;
	while (i < 100)
	{
		visited[i] = 0;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		Queue[i] = NULL;
		i++;
	}
	BFS(G, visit);
	printf("*BFS Traverse success\n");
	return OK;
}

status print_AdjList(GPos&G)
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
	arcnode*arc_pos = NULL;
	while (vex_pos)
	{
		printf("%d->", vex_pos->index);
		arc_pos = vex_pos->first_arc;
		while (arc_pos)
		{
			printf("%d->", arc_pos->vex_index);
			arc_pos = arc_pos->nextarc;
		}
		printf("\n");
		vex_pos = vex_pos->nextvex;
	}
	printf("*print AdjList success\n");
	return OK;
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

void DFS(GPos&G, vexnode*vex, void(*visit)(vexnode*vex))
{
	visited[vex->index] = 1;
	visit(vex);
	arcnode*arc_pos = vex->first_arc;
	vexnode*vex_pos = NULL;
	while (arc_pos)
	{
		if (visited[arc_pos->vex_index] == 0)
		{
			vex_pos = G->first_vex;
			while (vex_pos&&vex_pos->index != arc_pos->vex_index)
				vex_pos = vex_pos->nextvex;
			if (vex_pos == NULL)
			{
				printf("*the Graph is wrong\n");
				exit(-1);
			}
			DFS(G, vex_pos, visit);
		}
		arc_pos = arc_pos->nextarc;
	}
}

void BFS(GPos&G, void(*visit)(vexnode*vex))
{
	int head = 0;
	int rear = 0;
	vexnode*vex_pos = G->first_vex;
	arcnode*arc_pos = NULL;
	vexnode*vex_temp = NULL;
	vexnode*vex_find = NULL;
	while (vex_pos)
	{
		if (visited[vex_pos->index] == 0)
		{
			visited[vex_pos->index] = 1;
			visit(vex_pos);
			Queue[rear++] = vex_pos;
			while (rear != head)
			{
				vex_temp = Queue[head];
				head++;
				arc_pos = vex_temp->first_arc;
				while (arc_pos)
				{
					if (visited[arc_pos->vex_index] == 0)
					{
						visited[arc_pos->vex_index] = 1;
						vex_find = G->first_vex;
						while (vex_find&&vex_find->index != arc_pos->vex_index)
							vex_find = vex_find->nextvex;
						if (vex_find == NULL)
						{
							printf("*the Graph is wrong\n");
							exit(-1);
						}
						visit(vex_find);
						Queue[rear++] = vex_find;
					}
					arc_pos = arc_pos->nextarc;
				}
			}
		}





		vex_pos = vex_pos->nextvex;
	}
}

void visit(vexnode*vex)
{
	printf("index:%d  value:%d\n", vex->index, vex->value);
}
