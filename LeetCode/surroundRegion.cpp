class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int row = 0; row < rows; row++){
            if(board[row][0] == 'O'){q.push({row, 0}); visited[row][0] = true;}
            if(board[row][cols-1] == 'O'){q.push({row, cols-1}); visited[row][cols-1] = true;}
        }

        for(int col = 0; col < cols; col++){
            if(board[0][col] == 'O'){q.push({0, col}); visited[0][col] = true;}
            if(board[rows-1][col] == 'O'){q.push({rows-1, col}); visited[rows-1][col] = true;}
        }

        //bfs
        while(!q.empty()){

            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            //check in all directions
            int dirs[] = {-1, 0, 1, 0, -1};
            for(int dir = 0; dir < 4; dir++){
                int newRow = currRow + dirs[dir];
                int newCol = currCol + dirs[dir+1];

                if(newRow < 0 || newCol < 0){continue;}
                if(newRow >= rows || newCol >= cols){continue;}
                if(board[newRow][newCol] == 'X'){continue;}
                if(visited[newRow][newCol]){continue;}

                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
                
            }
        }

        //change Os to Xs
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(!visited[row][col]){
                    board[row][col] = 'X';
                }
            }
        }

    }
};class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int row = 0; row < rows; row++){
            if(board[row][0] == 'O'){q.push({row, 0}); visited[row][0] = true;}
            if(board[row][cols-1] == 'O'){q.push({row, cols-1}); visited[row][cols-1] = true;}
        }

        for(int col = 0; col < cols; col++){
            if(board[0][col] == 'O'){q.push({0, col}); visited[0][col] = true;}
            if(board[rows-1][col] == 'O'){q.push({rows-1, col}); visited[rows-1][col] = true;}
        }

        //bfs
        while(!q.empty()){

            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            //check in all directions
            int dirs[] = {-1, 0, 1, 0, -1};
            for(int dir = 0; dir < 4; dir++){
                int newRow = currRow + dirs[dir];
                int newCol = currCol + dirs[dir+1];

                if(newRow < 0 || newCol < 0){continue;}
                if(newRow >= rows || newCol >= cols){continue;}
                if(board[newRow][newCol] == 'X'){continue;}
                if(visited[newRow][newCol]){continue;}

                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
                
            }
        }

        //change Os to Xs
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(!visited[row][col]){
                    board[row][col] = 'X';
                }
            }
        }

    }
};