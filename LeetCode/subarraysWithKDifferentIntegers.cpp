class Solution {
private:
    int subarraysWithUptoKDistinct(vector<int>& nums, int k){
        map<int,int> freq;

        int s = 0;
        int e = 0;
        int total = 0;

        while(e < nums.size()){
            freq[nums[e]]++; //read updated state

            while(freq.size() > k){ //correct state    
                freq[nums[s]]--;
                if(freq[nums[s]] == 0){
                    freq.erase(nums[s]);
                }
                s++;
            }

            total += e - s + 1; //update ans

            e++;    //update state
        }

        return total;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithUptoKDistinct(nums, k) - subarraysWithUptoKDistinct(nums, k-1);
    }
};