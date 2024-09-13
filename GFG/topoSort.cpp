class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
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
	            
	            ans.push_back(currNode);
	            
	            for(int nb : adj[currNode]){ //nb - neighbor
	                
	                indegree[nb]--;
	                
	                if(indegree[nb] == 0){
	                    visited[nb] = true;
	                    q.push(nb);
	                }
	            }
	            
	        }
	        
	    }
	    
	    return ans;
	}
};