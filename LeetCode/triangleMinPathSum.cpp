class Solution {
private:
    int MinTotal(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp){

        //base condition
        if(row > triangle.size() || col > triangle[row].size()){
            return INT_MAX;
        }

        if(row == triangle.size()-1){return triangle[row][col];}

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        //move left adjacent
        int minPathSum = MinTotal(triangle, row+1, col, dp);

        //move right adjacent
        minPathSum = min(minPathSum, MinTotal(triangle, row+1, col+1, dp));

        return dp[row][col] = triangle[row][col] + minPathSum;
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return MinTotal(triangle, 0, 0, dp);
    }
};