class Solution {
private:
    void DFS(vector<vector<int>>& isConnected, int node, vector<bool>& visited){

        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[node][i] && !visited[i]){
                visited[i] = true;
                DFS(isConnected, i, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(visited[i]){continue;;}

            count++;
            visited[i] = true;
            DFS(isConnected, i, visited);
        }

        return count;
    }   
};