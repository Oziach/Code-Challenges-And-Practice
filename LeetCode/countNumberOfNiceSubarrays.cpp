class Solution {
private:
    int numberOfSubarraysLteK(vector<int>& nums, int k){
        int s = 0;
        int e = 0;
        int total = 0;
        int oddNos = 0;

        while(e < nums.size()){
            
            oddNos += nums[e] & 1; //evaluate state

            while(oddNos > k){  //correct state if invalid evaluation
                if(nums[s]&1){oddNos--;}
                s++;
            }

            total += e - s + 1;  //update ans

            e++;  //update state
        }

        return total;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysLteK(nums, k) -
            numberOfSubarraysLteK(nums, k-1);
    }
};