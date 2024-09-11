class Solution {
private:
    int MaxCoins(vector<int>& nums, int start, int end, vector<vector<int>>& dp){
        
        //base case
        if(start > end){return 0;}

        //logic

        if(dp[start][end] != -1){return dp[start][end];}

        int maxCoins = 0;

        for(int i = start; i <= end; i++){

            int coinsLeft = start == 0 ? 1 : nums[start-1];
            int coinsRight = end == nums.size()-1 ? 1 : nums[end+1];

            int coinsEarned = nums[i] * coinsLeft * coinsRight;
            coinsEarned += MaxCoins(nums, start, i-1, dp) + MaxCoins(nums, i+1, end, dp);

            maxCoins = max(maxCoins, coinsEarned);
        }

        return dp[start][end] = maxCoins;
    }

public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, 0));

        for(int start = nums.size()-1; start >= 0; start--){
            for(int end = start; end < nums.size(); end++){

                int maxCoins = 0;

                for(int i = start; i <= end; i++){

                    int coinsLeft = start == 0 ? 1 : nums[start-1];
                    int coinsRight = end == nums.size()-1 ? 1 : nums[end+1];

                    int coinsEarned = nums[i] * coinsLeft * coinsRight;
                    coinsEarned += dp[start+1][i-1+1] + dp[i+1+1][end+1];

                    maxCoins = max(maxCoins, coinsEarned);
                }

                dp[start+1][end+1] = maxCoins;

            }
        }

        return dp[0+1][nums.size()-1+1];
    }
};