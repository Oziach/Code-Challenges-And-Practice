class Solution {
public:
    bool canJump(vector<int>& nums) {;

        
        int maxPos = 0;

        for(int i = 0; i < nums.size(); i++){
            maxPos = max(maxPos, i + nums[i]);
            
            if(maxPos >= nums.size()-1){return true;}

            if(maxPos == i){return false;}
        }

        return true;
    }
};