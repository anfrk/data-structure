#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

typedef struct graph{
	int vsize;		//그래프의 정점 개수 
	int adj[MAX_VERTEX][MAX_VERTEX];		//그래프에 대한 30x30 인접행렬 
	char vdata[MAX_VERTEX];		//정점에 저장할 데이터 배열 
}Graph;

void init_graph(Graph *g){		//그래프 초기화 
	int i, j;
	g->vsize = 0;		//정점 개수 초기화 
	for(i=0; i<MAX_VERTEX; i++){		//인접행렬 초기화 
		for(j=0; j<MAX_VERTEX; j++){
			g->adj[i][j] = 0;
		}
	}
}

void insert_Vertex(Graph *g, char name){		//정점에 name을 삽입 
	if((g->vsize)+1 > MAX_VERTEX){		//현재 그래프의 정점개수에 1개를 더했을때 최댓값을 넘는지 검사 
		printf("Error : 정점 개수를 초과 했습니다.");
	}
	else{		//정점 개수가 안넘을때 
		g->vdata[g->vsize++] = name;		//정점에 name값을 저정하고 정점개수를 증가 
	}
}

void insert_Edge1(Graph *g, int u, int v){		//그래프에 무방향 그래프 간선 (u, v)를 삽입 
	g->adj[u][v] = g->adj[v][u]	= 1;
} 

void insert_Edge2(Graph *g, int u, int v){		//그래프에 방향 그래프 간선 <u, v>를 삽입 
	g->adj[u][v] = 1; 
}

void print_graph(Graph *g){
	int i, j;
	for(i=0; i<(g->vsize); i++){
		printf("\n\t\t");
		for(j=0; j<(g->vsize); j++){
			printf("%2d", g->adj[i][j]);
		}
	}
}

int main(void) {
	int i;
	Graph *G1, *G2, *G3;
	
	G1 = (Graph *)malloc(sizeof(Graph));		//그래프 G1과 G2, G3 동적할당 
	G2 = (Graph *)malloc(sizeof(Graph));
	G3 = (Graph *)malloc(sizeof(Graph));
	
	init_graph(G1);
	
	for(i=0; i<4; i++){		//그래프 G1의 정점에 각 삽입 
		insert_Vertex(G1, 'A'+i);
	}
	insert_Edge1(G1, 0, 1);
	insert_Edge1(G1, 0, 3);
	insert_Edge1(G1, 1, 2);
	insert_Edge1(G1, 1, 3);
	insert_Edge1(G1, 2, 3);
	printf("\n G1의 인접행렬");
	print_graph(G1);
	
	init_graph(G2);
	
	for(i=0; i<4; i++){		//그래프 G2의 정점에 각 삽입 
		insert_Vertex(G2, 'A'+i);
	}
	insert_Edge1(G2, 0, 1);
	insert_Edge1(G2, 0, 3);
	insert_Edge1(G2, 1, 2);
	insert_Edge1(G2, 1, 3);
	insert_Edge1(G2, 2, 3);
	printf("\n G2의 인접행렬");
	print_graph(G2);
	
	init_graph(G3);
	
	for(i=0; i<4; i++){		//그래프 G3의 정점에 각 삽입 
		insert_Vertex(G3, 'A'+i);
	}
	insert_Edge2(G3, 0, 1);
	insert_Edge2(G3, 0, 3);
	insert_Edge2(G3, 1, 2);
	insert_Edge2(G3, 1, 3);
	insert_Edge2(G3, 2, 3);
	printf("\n G3의 인접행렬");
	print_graph(G3);
	
	return 0;
}
