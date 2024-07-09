void CreateAdjList(map<int, vector<int>>& m, vector<vector<int>>& edges){
    for(vector<int> edge : edges){
        int u = edge[0];
        int v = edge[1];

        m[u].push_back(v);
        m[v].push_back(u);
    }
}

void DFS(map<int, vector<int>>& adj, vector<int>& connected, int node, map<int, bool>& visited){

    connected.push_back(node);
    visited[node] = true;

    for(int i : adj[node]){
        if(!visited[i]){
            DFS(adj, connected, i, visited);
        }
    }


}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    map<int, vector<int>> adj;
    CreateAdjList(adj, edges);
    vector<vector<int>> ans;
    map<int,bool> visited;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int> temp;
            DFS(adj, temp, i, visited);
            ans.push_back(temp);
        }
    }

    return ans;
}