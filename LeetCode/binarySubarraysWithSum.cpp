class Solution {
    
    int numSubarraysWithSumLTE(vector<int>& nums, int goal){
        int sum = 0;
        int ans = 0;
        int s = 0;
        int e = 0;

        while(s <= e && e < nums.size()){
            
            sum += nums[e]; //evaluate state
            
            while(s < e && sum > goal){ //first thing you do is correct the state
                sum -= nums[s++];
            }

            if(sum <= goal){ //update answer
                ans += e - s + 1;
            }

            e++; //update state
        }
        
        return ans;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumLTE(nums, goal)- numSubarraysWithSumLTE(nums, goal-1);
    }
};