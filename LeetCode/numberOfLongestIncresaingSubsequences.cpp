class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        vector<pair<int,int>> dp(nums.size(), {1, 1});

        for(int i = 0; i < nums.size(); i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] > nums[prev]){
                    
                    if(dp[i].first < 1 + dp[prev].first){
                        dp[i] = {1 + dp[prev].first , dp[prev].second };
                    }
                    else if(dp[i].first == 1 + dp[prev].first){
                        dp[i].second += dp[prev].second;
                    }

                }
            }
        }

        //find length of lis
        int maxi = 0;
        for(int i = 0; i < dp.size(); i++){
            maxi = max(maxi, dp[i].first);
        }

        int ans = 0;
        //find number of lis with length maxi
        for(int i = 0; i < dp.size(); i++){
            if(dp[i].first == maxi){
                ans += dp[i].second;
            }
        }

        return ans;
    }
};