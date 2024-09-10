class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {

        
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        
        for(int index = 0; index < n; index++){
            for(int prevIndex = 0; prevIndex < index; prevIndex++){
                if(nums[prevIndex] < nums[index]){
                    dp1[index] = max(dp1[index], 1 + dp1[prevIndex]);
                }
            }
        }
        
        
        for(int index = n-1; index >= 0; index--){
            for(int prevIndex = n-1; prevIndex > index; prevIndex--){
                if(nums[prevIndex] < nums[index]){
                    dp2[index] = max(dp2[index], 1 + dp2[prevIndex]);
                }
            }
        }
        
        //extract the final ans
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(dp1[i] == 1 || dp2[i] == 1){continue;}
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        
        return maxi;
    }
};
