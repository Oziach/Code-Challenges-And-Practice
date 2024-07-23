class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        map<int ,int> sumToInd;
        sumToInd[0] = -1;
        int sum = 0;
        int longest = 0;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(!sumToInd.count(sum)){
                sumToInd[sum] = i;
            }
            else{ //sum occured before
                longest = max(longest, i - sumToInd[sum]);
            }
        }
        
        return longest;
    }
};