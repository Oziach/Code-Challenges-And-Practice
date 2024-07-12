class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int S) {
        
        vector<int> costs(n, 10e7);
        costs[S] = 0;
        
        for(int i = 0; i < n-1; i++){
            for(vector<int> edge : edges){
                int u = edge[0];
                int v = edge[1];
                int cost = edge[2];
                
                if(costs[u] < 10e7 && costs[u] + cost < costs[v]){
                    costs[v] = costs[u] + cost;
                }
            }
        }

           for(vector<int> edge : edges){
                int u = edge[0];
                int v = edge[1];
                int cost = edge[2];
                
                if(costs[u] < 10e7 && costs[u] + cost < costs[v]){
                    vector<int> temp = {-1};
                    return temp;
                }
            }
        
        return costs;
    }
};
