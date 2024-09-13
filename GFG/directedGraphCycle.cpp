class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {

	    vector<int> indegree(V);
	    
	    for(int i = 0; i < V; i++){
	        for(int nb : adj[i]){
	            indegree[nb]++;
	        }
	    }
	    
	    queue<int> q;
	    vector<bool> visited(V, false);
	    
	    //traverse
	    for(int node = 0; node < V; node++){
	        if(visited[node] || indegree[node] > 0){continue;}
	        
	        //terra incognita
	        q.push(node);
	        visited[node] = true;
	        
	        while(!q.empty()){
	            
	            int currNode = q.front();
	            q.pop();
	            
	            
	            for(int nb : adj[currNode]){ //nb - neighbor
	                
	                indegree[nb]--;
	                
	                if(indegree[nb] == 0){
	                    visited[nb] = true;
	                    q.push(nb);
	                }
	            }
	            
	        }
	        
	    }
	    
	    for(int i = 0; i < V; i++){
	        if(visited[i] == false){
	            return true;
	        }
	    }
	    return false;
    }
};