class Solution {
private:
    int GetTotalCombis(int amount, vector<int>& coins, int index,  vector<vector<int>>& dp){
        
        //base case
        
        if(index == 0){
            return amount % coins[0] == 0;
        }

        if(dp[amount][index] != -1){return dp[amount][index];}

        int totalCombis = 0;

        //pick
        if(amount - coins[index] >= 0){
            totalCombis += GetTotalCombis(amount - coins[index], coins, index, dp);
        }

        //move on
        totalCombis += GetTotalCombis(amount, coins, index-1, dp);

        return dp[amount][index] = totalCombis;
    }

public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
        return GetTotalCombis(amount, coins, coins.size()-1, dp);
    }
};