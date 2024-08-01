class Solution {
private:
    bool IsValid(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& visited){
        
        if(row < 0 || col < 0){return false;}
        if(row >= board.size() || col >= board[0].size()){return false;}
        if(visited[row][col]){return false;}

        return true;
    }

    bool SearchLocale(vector<vector<char>>& board, string word, int wordIndex, int row, int col, vector<vector<bool>>& visited){

        if(wordIndex >= word.length()){return true;}

        int dirs[] = {-1, 0, 1, 0, -1};
        for(int dir = 0; dir < 4; dir++){
            int nextRow = row + dirs[dir];
            int nextCol = col+dirs[dir+1];

            if(!IsValid(board, nextRow, nextCol, visited) || board[nextRow][nextCol] != word[wordIndex])
                continue;
            
            //else if found next letter
            visited[nextRow][nextCol] = true;
            bool ans = SearchLocale(board, word, wordIndex+1, nextRow, nextCol, visited);
            visited[nextRow][nextCol] = false;

            if(ans){return true;}
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                
                if(board[r][c] != word[0])
                    continue;
                
                //else
                visited[r][c] = true;
                bool ans = SearchLocale(board, word, 1, r, c, visited);
                visited[r][c] = false;

                if(ans){return true;}
            }
        }
        return false;
    }
};