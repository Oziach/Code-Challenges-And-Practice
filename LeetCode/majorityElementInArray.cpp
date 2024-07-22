class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;

        for(int num : nums){

            if(count == 0){
                element = num;
                count ++;
            }
            else if(num == element){
                count++;
            }
            else{
                count--;
            }
        }
            return element;

    }
};