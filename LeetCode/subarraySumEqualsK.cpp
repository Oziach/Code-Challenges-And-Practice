class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        map<int, int> sumToCount;

        int sum = 0;
        int count = 0;

        for(int i = 0; i < n; i++){
            
            sum += nums[i];

            if(sum == k){
                count++;
            }

            int rem = sum - k;
            if(sumToCount.count(rem)){
                count += sumToCount[rem];
            }

            sumToCount[sum]++;
        }

        return count;
    }
};