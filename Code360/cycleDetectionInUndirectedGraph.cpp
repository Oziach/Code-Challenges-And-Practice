#include<map>
#include<unordered_map>
#include<queue>

void CreateAdjList(map<int, vector<int>>& m, vector<vector<int>>& edges){
    for(vector<int> edge : edges){
        int u = edge[0];
        int v = edge[1];

        m[u].push_back(v);
        m[v].push_back(u);
    }
}

bool BFS(map<int, vector<int>>& adj, int node, map<int, bool>& visited){
    unordered_map<int,int> parent;

    parent[node] = -1;
    visited[node] = 1;  
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(int nb : adj[front]){
            if(visited[nb] && nb != parent[front]){
                return true;
            }
            else if(!visited[nb]){
                visited[nb] = true;
                parent[nb] = front;
                q.push(nb);
            }
        }

    }

    return false;


}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    map<int, vector<int>> adj;
    CreateAdjList(adj, edges);
    map<int,bool> visited;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            vector<int> temp;
            bool ans = BFS(adj, i, visited);
            if(ans){
                return "Yes";
            }
        }
    }

    return "No";
}
