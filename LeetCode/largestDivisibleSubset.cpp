class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 1);
        vector<int> prevIndexes(nums.size(), -1);

        for(int index = 0; index < nums.size(); index++){
            for(int prevIndex = 0; prevIndex < index; prevIndex++){

                if(nums[index] % nums[prevIndex] == 0){
                    if(dp[index] < 1 + dp[prevIndex]){
                        dp[index] = 1 + dp[prevIndex];
                        prevIndexes[index] = prevIndex;
                    }
               
                }

            }
        }

        //find max index
        int maxIndex = 0;
        for(int i = 0; i < dp.size(); i++){
            if(dp[i] > dp[maxIndex]){
                maxIndex = i;
            }
        }

        //generate the subset
        vector<int> ans;
        while(maxIndex >= 0){
            ans.push_back(nums[maxIndex]);
            maxIndex = prevIndexes[maxIndex];
        }

        return ans;
    }
};