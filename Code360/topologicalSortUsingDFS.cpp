#include <bits/stdc++.h> 

void CreateAdjList(unordered_map<int, vector<int>>& m, vector<vector<int>>& edges){
    for(vector<int> edge : edges){
        int u = edge[0];
        int v = edge[1];

        m[u].push_back(v);
    }
}

void DFS( unordered_map<int, vector<int>>& adj, vector<bool>& visited, stack<int>& ansStack, int node){
    
    visited[node] = true;

    for(int i : adj[node]){
        if(visited[i]){continue;}
        DFS(adj, visited, ansStack, i);
    }

    ansStack.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {

    unordered_map<int, vector<int>> adj;
    CreateAdjList(adj, edges);
    vector<bool> visited(n, false);
    vector<int> ans;
    stack<int> ansStack;

    for(int i = 0; i < n; i++){
        if(visited[i]){continue;}

        //else
        DFS(adj, visited, ansStack, i);
    }

    while(!ansStack.empty()){
        ans.push_back(ansStack.top());
        ansStack.pop();
    }
    return ans;
}