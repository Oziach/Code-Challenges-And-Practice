class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> squaresForRightBottomAt(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            squaresForRightBottomAt[i][0] = matrix[i][0];
        }

        for(int i = 0; i < m; i++){
            squaresForRightBottomAt[0][i] = matrix[0][i];
        }

        //mm
        for(int row = 1; row < n; row++){
            for(int col = 1; col < m; col++){

                if(matrix[row][col] == 0){continue;}

                int top = squaresForRightBottomAt[row-1][col];
                int left = squaresForRightBottomAt[row][col-1];
                int diag = squaresForRightBottomAt[row-1][col-1];

                squaresForRightBottomAt[row][col] = 1 + min(top, min(left, diag));
            }
        }

        int total = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                total += squaresForRightBottomAt[row][col];
            }
        }

        return total;
    }
};