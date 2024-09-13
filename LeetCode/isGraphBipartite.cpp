class Solution {
private:
    bool IsBipartite(vector<vector<int>>& graph, map<int,int>& visited, int currVertex){

        int currColor = visited[currVertex];

        for(int nb : graph[currVertex]){
            
            if(visited.count(nb)){
                if(visited[nb] == currColor){
                    return false;
                }
                else{
                    continue;
                }
            }

            //if we find an uncolored neighbor, time to color it opposite!
            visited[nb] = !currColor; 

            bool ans = IsBipartite(graph, visited, nb);
            if(!ans){return false;}
        }

        return true;
    }

    bool IsBipartite2(vector<vector<int>>& graph, vector<int>& visited, int currVertex, int color){

        visited[currVertex] = color;

        for(int nb : graph[currVertex]){
            
            if(visited[nb] == -1){
                bool ans = IsBipartite2(graph, visited, nb, !color);
                if(!ans){return false;}
            }
            else if(visited[nb] == color){
                return false;
            }
           
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> color(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++){
            if(color[i] != -1){continue;}

            bool ans = IsBipartite2(graph, color, i, 0);
            
            if(!ans){return false;}
        }

        return true;

    }
};