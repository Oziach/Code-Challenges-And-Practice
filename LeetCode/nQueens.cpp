//the weird ans filling method didn't work, for obvious reasons in hindsight (since we don't return all the way to the first column when we find an ans)
class Solution {
private:

    bool CanPlaceHere(int row, int col, vector<bool>& rowsStates, vector<bool>& colsStates, 
      unordered_map<int, bool>& diagStates1, unordered_map<int,bool>& diagStates2){

        if(rowsStates[row] || colsStates[col]){return false;}
        if(diagStates1[row - col] || diagStates2[row+col]){return false;}

        return true;
    }

    void PlaceQueenInCol(int colNo, vector<string>& board, vector<bool>& rowsStates, vector<bool>& colsStates, unordered_map<int, bool>& diagStates1, unordered_map<int,bool>& diagStates2, vector<vector<string>>& ans){
        
        int n = board.size();

        //base condition: if found a valid arrangement, update ans
        if(colNo >= n){
            ans.push_back(board);
            return;
        }
        

        //try to place at every row
        for(int r = 0; r < n; r++){
            if(!CanPlaceHere(r, colNo, rowsStates, colsStates, diagStates1, diagStates2))
                continue;
            
            //update state
            rowsStates[r] = true;
            colsStates[colNo] = true;
            diagStates1[r-colNo] = true;
            diagStates2[r+colNo] = true;
            board[r][colNo] = 'Q';

            //else place queen in current col and move to next col
            PlaceQueenInCol(colNo+1, board, rowsStates, colsStates, diagStates1, diagStates2, ans);

            //revert state (backtrack)
            rowsStates[r] = false;
            colsStates[colNo] = false;
            diagStates1[r-colNo] = false;
            diagStates2[r+colNo] = false;
            board[r][colNo] = '.';

        }

    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> rows(n, false);
        vector<bool> cols(n, false);
        unordered_map<int, bool> diagStates1;
        unordered_map<int, bool> diagStates2;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        
        PlaceQueenInCol(0, board, rows, cols, diagStates1, diagStates2, ans);
        return ans;
    }
};