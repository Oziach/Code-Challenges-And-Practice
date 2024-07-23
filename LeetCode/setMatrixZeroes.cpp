class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool rowZero = false;

        for(int r = 0; r < m ; r++){
            for(int c = 0; c < n; c++){
                if(matrix[r][c] == 0){
                    if(r == 0){rowZero = true;}
                    else {matrix[r][0] = 0;}
                    matrix[0][c] = 0;
                }
            }
        }

        //zero the respective rows and cols. the ORDERING IS VERY IMPORTANT HERE, based on
        //whether you store first row or column in the variable

        for(int r = 1; r < m; r++){
            if(matrix[r][0] == 0){
                for(int i = 0; i < n ; i++){
                    matrix[r][i] = 0;
                }
            }
        }

        for(int c = 0; c < n; c++){
            if(matrix[0][c] == 0){
                for(int i = 0; i < m ; i++){
                    matrix[i][c] = 0;
                }
            }
        }

        if(rowZero){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
    }
};