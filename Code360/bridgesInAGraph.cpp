
void DFS(vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, vector<bool>& visited, 
  int node, int parent, int& time, vector<vector<int>>& ans){

    disc[node] = time;
    low[node] = time;
    time++;
    visited[node] = true;

    for(int nb : adj[node]){

        if(nb == parent){ continue; }

        //check for backedge
        if(visited[nb]){
            low[node] = min(low[node], disc[nb]);
            continue;
        }

        DFS(adj, disc, low, visited, nb, node, time, ans);
        low[node] = min(low[node], low[nb]);
        if(low[nb] > disc[node]){
            vector<int> temp = {node, nb};
            ans.push_back(temp);
        }

    }

}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int e) {
    vector<vector<int>> adj(n);
    for(vector<int> edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<int> low(n, -1);
    vector<int> disc(n, -1);
    vector<bool> visited(n);
    int time = 0;

    for(int i = 0; i < n; i++){
        if(visited[i]){continue;}
        DFS(adj, disc, low, visited, 0, -1, time, ans);
    }


    return ans;
}