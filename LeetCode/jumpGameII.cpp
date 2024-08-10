class Solution {
public:
    int jump(vector<int>& nums) {
        map<int, int> minJumpsTo;
        int maxIndex = 0;
        int jumpsNeededToMax = 0; //this is the same as jumps needed till here...
        int currIndex = 0;

        while(maxIndex < nums.size()-1){

            int newMaxIndex = maxIndex;

            for(currIndex; currIndex <= maxIndex; currIndex++){
                newMaxIndex = max(newMaxIndex, currIndex + nums[currIndex]);
            }

            maxIndex = newMaxIndex;
            jumpsNeededToMax++;
        }

        return jumpsNeededToMax;

    }
};