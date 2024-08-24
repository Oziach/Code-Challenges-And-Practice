class Solution {
private:
    int GetUniques(int m, int n, vector<vector<int>>& dp){

        if(m < 1 || n < 1){return 0;}
        if(m == 1 && n == 1){return 1;}

        if(dp[m][n] != -1){return dp[m][n];}

        int totalWays = 0;

        //move right
        totalWays += GetUniques(m-1, n, dp);

        //move down
        totalWays += GetUniques(m, n-1, dp);

        return dp[m][n] = totalWays;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return GetUniques(m, n, dp);
    }
};