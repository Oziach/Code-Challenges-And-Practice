
class Solution{
    public:
    
    bool IsValid(int row, int col, vector<vector<int>>& m, vector<vector<bool>> visited, int n){
        
        if(row < 0 || row >= n || col < 0 || col >= n){
            return false;
        }
        
        if(m[row][col] == 0 || visited[row][col]){
            return false;
        }
        
        return true;
    }
    
    void move(vector<vector<int>>& m, vector<vector<bool>>& visited, int x, int y, 
        string& path, vector<string>& ans, int n){
        
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y] = true;
        //move in all directions
        int dir[] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            //next square co-ordinates
            int row = x + dir[i];
            int col = y + dir[i+1];
            
            if(IsValid(row, col, m, visited, n)){
                
                switch(i){
                    case 0: path += "U"; break;
                    case 1: path += "R"; break;
                    case 2: path += "D"; break;
                    case 3: path += "L"; break;
                }
            
                move(m, visited, row, col, path, ans, n);

                
                path.pop_back();
            }
        }
        visited[x][y] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
    
        if(m[0][0] == 0){return ans;}
        
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path = "";

        move(m, visited, 0, 0, path, ans, n);
        
        return ans;
    }
};

   