class Solution {
public:
    //the other method for doing this.
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int s = 0;
        int e = nums.size()-1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums[s] <= nums[e]){
                mini = min(mini, nums[s]);
                break;
            }
            
            if(nums[s] <= nums[mid]){
                 mini = min(mini, nums[s]);
                s = mid+1;
            }
            else{
                mini = min(mini, nums[mid]);
                e = mid -1;
            }
        }

        return mini;
    }
};  