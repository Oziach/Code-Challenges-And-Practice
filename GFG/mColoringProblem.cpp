class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool IsColorable(bool graph[101][101], int m, int node, int col, int n, vector<int>& cols){

            for(int i = 1; i <= n; i++){
                if(i == node){continue;}
                if(graph[node][i] && cols[i] == col){
                    return false;
                }
            }
        
        return true;
    }
    
    bool GraphColoring(bool graph[101][101], int m, int n, int node, vector<int>& cols){
        
        if(node > n){return true;}
        
        //try every color
        for(int color = 0; color < m; color++){
            if(IsColorable(graph, m, node, color, n, cols)){
                
                cols[node] = color;
                bool ans = GraphColoring(graph, m, n, node+1, cols);
                cols[node] = -1;
                
                if(ans) return true;
            }
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> cols(n+1, -1);
        return GraphColoring(graph, m, n, 1, cols);
    }
};