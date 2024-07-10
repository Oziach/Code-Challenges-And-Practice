class Solution {
  public:
    
    void SetAdj(map<int, list<pair<int, int>>>& adj, vector<vector<int>>& edges){
        for(auto edge : edges){
            
            int first = edge[0];
            int second = edge[1];
            int cost = edge[2];
            adj[first].push_back({second, cost});
            
        }
    }
    
    void TopologicalDFS(map<int, list<pair<int, int>>>& adj, int node, stack<int>& st, map<int, bool>& visited){
        
        visited[node] = true;
        
        for(pair<int,int> nbPair : adj[node]){
            
            int nb = nbPair.first;
            if(!visited[nb]){
                TopologicalDFS(adj, nb, st, visited);   
            }
        }
        
        st.push(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        stack<int> st;
        map<int, bool> visited;
        map<int, list<pair<int, int>>> adj;
        SetAdj(adj, edges);
    
        TopologicalDFS(adj, 0, st, visited);
        
        vector<int> minCosts(N, -1);
        minCosts[0] = 0;
        
        while(!st.empty()){
            
            int i = st.top();
            st.pop();
            
            if(minCosts[i] == -1){continue;}
            
            for(pair<int,int> nodeCostPair : adj[i]){
                 int node = nodeCostPair.first;
                 int cost = minCosts[i] + nodeCostPair.second;
                 
                 if(minCosts[node] == -1 || minCosts[node] > cost){
                     minCosts[node] = cost;
                 }
            }
        }
        
        return minCosts;
        
    }
};
