#include<bits/stdc++.h>

void CreateAdjList(unordered_map<int, vector<int>>& m, vector<pair<int,int>>& edges){
    for(auto edge : edges){
        int u = edge.first;
        int v = edge.second;

        m[u].push_back(v);
		m[v].push_back(u);
    }
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
    vector<bool> visited(n, false);
	vector<int> parent(n);
	unordered_map<int, vector<int>> adj;
	CreateAdjList(adj, edges);

	parent[s-1] = -1;
	queue<int> q;
	q.push(s);
	visited[s-1] = true;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(int nb : adj[front]){
			if(!visited[nb-1]){
				visited[nb-1] = true;
				parent[nb-1] = front;
				q.push(nb);
			}
		}
	
	}


		vector<int> ans;
		int temp = t;
        while (temp > 0) {
                ans.push_back(temp);
                temp = parent[temp - 1];
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
}