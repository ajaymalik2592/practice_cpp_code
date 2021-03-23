#include<stdio.h>
int n = 10, m = 10;
int parent[10], leaf[10], entry_time[10], exit_time[10], number_of_node[10];
int matrix[10][10];
int timer = 0;
void dfs(int node, int pa){
	parent[node] = pa;
	entry_time[node] = timer;
	timer++;
	int g = 0;
	number_of_node[node] = 1;
		
	for(int x =0; x<5; x++)
	{
		if(matrix[node][x] == 1 && x != pa)
		{
			dfs(x, node);
			number_of_node[node] += number_of_node[x];
			g++;
		}
	}
	exit_time[node] = timer;
	if(g == 0)leaf[node] = 1;
}
int main()
{
	for(int x =0; x<n; x++){
		for(int y =0; y<n; y++)
			matrix[x][y] = 0;
		leaf[x] = 0;
		parent[x] = 0;
		entry_time[x] = 0;
		exit_time[x] = 0;
		number_of_node[x] = 0;
	}
	
	matrix[0][1] = 1;
	matrix[1][0] = 1;
	matrix[2][1] = 1;
	matrix[1][2] = 1;
	matrix[2][3] = 1;
	matrix[3][2] = 1;
	matrix[4][1] = 1;
	matrix[1][4] = 1;
	dfs(0 , -1);
	for(int x =0; x<5; x++){
		printf("%d\n", number_of_node[x]);
	}
	
}