#include<stdio.h>
#include<iostream>
#define MAX 10
using namespace std;
int adj[MAX][MAX];
int visited[MAX];
int n;
int parent[MAX];

void DFS(int i) {
	int j;
	cout <<  i << " ";
	visited[i] = 1;

	for(j = 0 ; j < n; j++)
		if(!visited[j] && adj[i][j] == 1) {
			parent[j]=i;
			DFS(j);
		}
}
void DF_traversal() {
	int v, i;
	for(i=0; i<n; i++)
		visited[i] = 0;


	cin >> v;
	parent[v]=-1;
	DFS(v);

}



void create_graph() {
	cin>>n;
	int e,t,u;
	cin>>e;

	for(int i = 0 ; i < e; i++) {
		cin>>t>>u;
		adj[t][u] = 1;
	}
}





int main() {
	create_graph();
	DF_traversal();

	return 0;
}

