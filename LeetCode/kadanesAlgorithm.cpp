class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;

        for(int num : nums){
            sum += num;                 //IMPPPPPPPPPPPp
            maxSum = max(maxSum, sum); //the order here is imp. First set max, then set to zero. ///////////
            if(sum < 0){sum = 0;}
           
        }

        return maxSum;
    }
};