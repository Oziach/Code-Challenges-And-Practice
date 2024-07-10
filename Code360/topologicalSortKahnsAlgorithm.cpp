#include <bits/stdc++.h> 

void CreateAdjList(unordered_map<int, vector<int>>& m, vector<vector<int>>& edges, vector<int>& inorder){
    for(vector<int> edge : edges){
        int u = edge[0];
        int v = edge[1];

        m[u].push_back(v);
        inorder[v]++;
    }
}

void BFS( unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<int>& inorder, vector<int>& ans, int n){

 
    queue<int> q;
    
    for(int i = 0; i < n; i++){
        if(inorder[i] == 0){ //indegree*****
            q.push(i);
        }
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(int nb : adj[front]){

            inorder[nb]--;
            if(inorder[nb] == 0){
                q.push(nb);
            }
            
        }

    }

}

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    vector<int> inorder(n, 0);

    unordered_map<int, vector<int>> adj;
    CreateAdjList(adj, edges, inorder);
    
    vector<int> ans;

    //visited map not necessary in kahn's algo
    BFS(adj, visited, inorder, ans, n);

    return ans;
}