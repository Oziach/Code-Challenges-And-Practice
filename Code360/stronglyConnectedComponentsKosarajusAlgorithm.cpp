#include<bits/stdc++.h>

void DFS(map<int, list<int>>& adj, vector<bool>& visited, stack<int>& st, int node){

	visited[node] = true;

	for(int nbr : adj[node]){
		if(visited[nbr]){continue;}
		
		DFS(adj, visited, st, nbr);
	}

	st.push(node);
}

void DFS(map<int, list<int>>& adj, vector<bool>& visited, int node){

	visited[node] = true;

	for(int nbr : adj[node]){

		if(visited[nbr]){continue;}
	
		DFS(adj, visited , nbr);
	}

}

int stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
	map<int,list<int>> adj;
	for(vector<int> edge : edges){
		int u = edge[0];
		int v = edge[1];

		adj[u].push_back(v);
	}

	vector<bool> visited(n);
	//pseudo topological sort
	stack<int> st;
	for(int i = 0; i < n; i++){
		if(visited[i]){continue;}
		DFS(adj, visited, st, i);
	}

	//transpose the graph
	map<int, list<int>> transpose;
	for(int i = 0; i < n; i++){
		for(int j : adj[i]){
			transpose[j].push_back(i);
		}
	}

	//dfs to find the components
	int componentsCount = 0;

	for(int i = 0; i < n; i++){
		visited[i] = false;
	}


	while(!st.empty()){
		int node = st.top();
		st.pop();

		if(visited[node]){continue;}

		DFS(transpose, visited, node);
		componentsCount++;
	}

	return componentsCount;
}