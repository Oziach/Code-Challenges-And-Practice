class Solution {
private:
    bool IsValid(vector<int>& nums, int& k, int& maxSubarraySum){
        int currSum = 0;
        int partitions = 1;

        for(int num : nums){
            currSum += num;
            if(currSum > maxSubarraySum){
                currSum = num;
                partitions++;

                if(partitions > k){
                    return false;
                }
            }
        }

        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int s = INT_MIN;
        int e = 0;

        for(int num : nums){
            s = max(s, num);
            e += num;
        }

        while(s <= e){
            int mid = s + (e-s)/2;

            if(IsValid(nums, k, mid)){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return s;
    }
};