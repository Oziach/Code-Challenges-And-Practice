class Solution {
  public:
  
  
void DFS(vector<int> adj[], vector<int>& disc, vector<int>& low, vector<bool>& visited, 
  int node, int parent, int& time, vector<int>& ap){

    disc[node] = time;
    low[node] = time;
    time++;
    visited[node] = true;
    int child = 0;
    
    for(int nb : adj[node]){

        if(nb == parent){ continue; }

        //check for backedge
        if(visited[nb]){
            low[node] = min(low[node], disc[nb]);
            continue;
        }

        DFS(adj, disc, low, visited, nb, node, time, ap);
        low[node] = min(low[node], low[nb]);
        
        if(parent != -1 && low[nb] >= disc[node]){
            ap[node] = true;
        }
        child++;    
    }
    
    if(parent == -1 && child > 1){
        ap[node] = true;
    }

}
  
  
    vector<int> articulationPoints(int n, vector<int>adj[]) {
    
        vector<int> ap(n, 0);
        vector<int> low(n, -1);
        vector<int> disc(n, -1);
        vector<bool> visited(n);
        int time = 0;
    
        for(int i = 0; i < n; i++){
            if(visited[i]){continue;}
            DFS(adj, disc, low, visited, i, -1, time, ap);
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(ap[i]){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0){ans.push_back(-1);}
        return ans;
        }
};