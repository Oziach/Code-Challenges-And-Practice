class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s = 0;
        int e = 0;
        int longest = 0;

        while(e < nums.size()){
            
            if(nums[e] == 0){k--;}
            
            while(k < 0){
                if(nums[s] == 0){k++;}
                s++;
            }

            longest = max(longest, e - s + 1);
            e++;
        }

        return longest;
    }
};