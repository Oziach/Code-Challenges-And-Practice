class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<int> next(m+1, INT_MAX);
        vector<int> curr(m+1, INT_MAX);

        for(int col = n-1; col >= 0; col--){


            for(int row = m-1; row >= 0; row--){

                //base condition
                if(row == m-1 && col == n-1){
                    curr[row] = grid[row][col]; 
                    continue;
                }

                curr[row] = grid[row][col] + min(curr[row+1], next[row]);
            }

            next = curr;

        }

        return next[0];
a
    }
};