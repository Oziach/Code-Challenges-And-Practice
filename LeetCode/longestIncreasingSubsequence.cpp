class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        
        for(int i = 0; i < nums.size(); i++){
            int element = nums[i];

            if(arr.empty() || element > arr[arr.size()-1]){
                arr.push_back(element);
            }    
            else{
                auto lb = lower_bound(arr.begin(), arr.end(), element);
                *lb = element;
            }
        }

        return arr.size();
    }
};