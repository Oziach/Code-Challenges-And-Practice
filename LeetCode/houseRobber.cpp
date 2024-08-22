class Solution {
private:
    
    int Robbin(vector<int>& nums, int index){
        //two options, rob or don't rob. Just return the max of the two
        if(index >= nums.size()){return 0;}

        return max(Robbin(nums, index+2) + nums[index], Robbin(nums, index+1));
    }

public:
    int rob(vector<int>& nums) {

        int next1, next2;
        next1 = next2 = 0;

        for(int i = nums.size()-1; i >= 0; i--){
            int curr = max(nums[i] + next2, next1);
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};