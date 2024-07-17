class Solution {
public:


    int GetMinSwaps(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){

        if(index == nums1.size()){ return 0; }

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swapped){
            swap(prev1, prev2);
        }

        int dontSwap = INT_MAX;
        int swap = INT_MAX;

        //don't swap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            dontSwap = GetMinSwaps(nums1, nums2, index+1, false);
        
        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            swap = (1 + GetMinSwaps(nums1, nums2, index+1, true));
        }

        return min(swap, dontSwap);
    }

     int GetMinSwapsMem(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp){

        if(index == nums1.size()){ return 0; }

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }

        if(swapped){
            swap(prev1, prev2);
        }

        int dontSwap = INT_MAX;
        int swap = INT_MAX;

        //don't swap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            dontSwap = GetMinSwapsMem(nums1, nums2, index+1, false, dp);
        
        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            swap = (1 + GetMinSwapsMem(nums1, nums2, index+1, true, dp));
        }

         return dp[index][swapped] = min(swap, dontSwap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        return GetMinSwapsMem(nums1, nums2, 1, false, dp);
    }
};