struct Info{
    int first;
    int second;
    int distTravelled;

    Info(int f, int s, int dist){
        first = f;
        second = s;
        distTravelled = dist;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> ans(rows, vector<int>(cols, INT_MAX));
        queue<Info> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(mat[row][col] == 0){
                    ans[row][col] = 0;
                    q.push({row,col,0});
                    visited[row][col] = true;
                }
            }
        }

        //bfs
        while(!q.empty()){
            
            int currRow = q.front().first;
            int currCol = q.front().second;
            int distTravelled = q.front().distTravelled;
            q.pop();

            //check all directions
            int dirs[] = {-1, 0, 1, 0, -1};
            for(int dir = 0; dir < 4; dir++){
                
                int newRow = currRow + dirs[dir];
                int newCol = currCol + dirs[dir+1];

                if(newRow < 0 || newCol < 0){continue;}
                if(newRow >= rows || newCol >= cols){continue;}
                if(visited[newRow][newCol]){continue;}

                visited[newRow][newCol] = true;

                if(mat[newRow][newCol] == 1){
            
                    ans[newRow][newCol] = distTravelled + 1;

                    q.push({newRow, newCol, distTravelled+1});
                } 
            }
        }

        return ans;

    }
};