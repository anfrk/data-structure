#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

typedef struct graph{
	int vsize;		//�׷����� ���� ���� 
	int adj[MAX_VERTEX][MAX_VERTEX];		//�׷����� ���� 30x30 ������� 
	char vdata[MAX_VERTEX];		//������ ������ ������ �迭 
}Graph;

void init_graph(Graph *g){		//�׷��� �ʱ�ȭ 
	int i, j;
	g->vsize = 0;		//���� ���� �ʱ�ȭ 
	for(i=0; i<MAX_VERTEX; i++){		//������� �ʱ�ȭ 
		for(j=0; j<MAX_VERTEX; j++){
			g->adj[i][j] = 0;
		}
	}
}

void insert_Vertex(Graph *g, char name){		//������ name�� ���� 
	if((g->vsize)+1 > MAX_VERTEX){		//���� �׷����� ���������� 1���� �������� �ִ��� �Ѵ��� �˻� 
		printf("Error : ���� ������ �ʰ� �߽��ϴ�.");
	}
	else{		//���� ������ �ȳ����� 
		g->vdata[g->vsize++] = name;		//������ name���� �����ϰ� ���������� ���� 
	}
}

void insert_Edge1(Graph *g, int u, int v){		//�׷����� ������ �׷��� ���� (u, v)�� ���� 
	g->adj[u][v] = g->adj[v][u]	= 1;
} 

void insert_Edge2(Graph *g, int u, int v){		//�׷����� ���� �׷��� ���� <u, v>�� ���� 
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
	
	G1 = (Graph *)malloc(sizeof(Graph *));		//�׷��� G1�� G2, G3 �����Ҵ� 
	G2 = (Graph *)malloc(sizeof(Graph *));
	G3 = (Graph *)malloc(sizeof(Graph *));
	
	init_graph(G1);
	
	for(i=0; i<4; i++){		//�׷��� G1�� ������ �� ���� 
		insert_Vertex(G1, 'A'+i);
	}
	insert_Edge1(G1, 0, 1);
	insert_Edge1(G1, 0, 3);
	insert_Edge1(G1, 1, 2);
	insert_Edge1(G1, 1, 3);
	insert_Edge1(G1, 2, 3);
	printf("\n G1�� �������");
	print_graph(G1);
	
	init_graph(G2);
	
	for(i=0; i<4; i++){		//�׷��� G2�� ������ �� ���� 
		insert_Vertex(G2, 'A'+i);
	}
	insert_Edge1(G2, 0, 1);
	insert_Edge1(G2, 0, 3);
	insert_Edge1(G2, 1, 2);
	insert_Edge1(G2, 1, 3);
	insert_Edge1(G2, 2, 3);
	printf("\n G2�� �������");
	print_graph(G2);
	
	init_graph(G3);
	
	for(i=0; i<4; i++){		//�׷��� G3�� ������ �� ���� 
		insert_Vertex(G3, 'A'+i);
	}
	insert_Edge2(G3, 0, 1);
	insert_Edge2(G3, 0, 3);
	insert_Edge2(G3, 1, 2);
	insert_Edge2(G3, 1, 3);
	insert_Edge2(G3, 2, 3);
	printf("\n G3�� �������");
	print_graph(G3);
	
	return 0;
}
