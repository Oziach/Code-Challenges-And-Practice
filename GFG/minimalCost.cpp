class Solution {
  private:
    int MinCost(vector<int>& arr, int& k, int currIndex, vector<int>& dp){
        
        if(currIndex == arr.size()-1){return 0;}
        
        if(dp[currIndex] != -1){return dp[currIndex];}
        
        int minFromHere = INT_MAX;
        
        for(int i = 1; i <= k; i++){
            if(currIndex + i > arr.size()-1){break;}
            minFromHere = min(minFromHere, 
               abs(arr[currIndex] - arr[currIndex+i]) + MinCost(arr, k, currIndex + i, dp));
        }
  
        return dp[currIndex] = minFromHere;
    }
    
  public:
    int minimizeCost(vector<int>& arr, int& k) {
        vector<int> dp(arr.size(), -1);
        return MinCost(arr, k, 0, dp);
    }
};