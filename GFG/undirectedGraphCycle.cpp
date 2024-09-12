class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        map<int, int> parent;
        queue<int> q;
        
        for(int i = 0; i < V; i++){
                
                if(parent[i]){continue;} //already visited
                
                q.push(i);
                parent[i] = -1;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(int nb : adj[node]){
                        
                        if(parent.count(nb)){ //if nb is already visited
                            if(parent[node] == nb){continue;} //if nb is ur parent, continue
                            //else, someone else visited nb, so cycle
                            return true;
                        }
                        else{
                            parent[nb] = node;
                            q.push(nb);
                        }
                        
                    }
                }
        }
        
         return false;
    }
    
};

///dfs solution
class Solution {
  private:
  
  bool DFS(vector<int> adj[], int node, int parent, map<int,bool>& visited){
    
    for(int nb : adj[node]){
        
        if(nb == parent){continue;}
        
        if(visited[nb]){return true;}
        
        visited[nb] = true;
        bool ans = DFS(adj, nb, node, visited);
        
        if(ans){return true;}
    }    
    
    return false;
  }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        map<int,bool> visited;
        for(int i = 0; i < V; i++){
            
            if(visited[i]){continue;}
            
            bool ans = DFS(adj, i, -1, visited);
            if(ans){return true;}
        }
        
        return false;
    }
};