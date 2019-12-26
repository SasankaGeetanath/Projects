#include<stdio.h>
#include<stdlib.h>
#define INF 999999
#define V 5

int graph[V][V];

int main() {
	int no_of_edge = 0;
	int selected[V] = {0};
	printf("\nEnter the adjacency matrix with weights :\n");
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) 
			scanf("%d", &graph[i][j]);
	}
	int x, y;
	selected[0] = 1;
	printf("\n\tEdge  :  Weight\n");
	while (no_of_edge < V - 1) {
		int min = INF;
		x = 0;
		y = 0;
		for (int i = 0; i < V; ++i) {
			if (selected[i]) {
				for (int j = 0; j < V; ++j) {
					if (!selected[j] && graph[i][j]) {
						if (min > graph[i][j]) {
							min = graph[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		printf("\n\t%d - %d  :  %d\n", x, y, graph[x][y]);
		selected[y] = 1;
		no_of_edge++;
	}
	return 0;
}