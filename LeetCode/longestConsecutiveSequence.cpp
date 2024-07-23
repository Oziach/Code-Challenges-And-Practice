
//this is the set solution; map solution works similarly

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 0;

        unordered_set<int> s;
        for(int num : nums){
            s.insert(num);
        }

        for(int num : nums){
            if(s.find(num-1) != s.end()){
                continue;
            }
            else{
                //if first element in sequence
                int count = 1;
                for(int i = num; s.find(i + 1) != s.end(); i++){
                    count++;
                }
                longest = max(longest, count);
            }
        }

        return longest;
    }
};