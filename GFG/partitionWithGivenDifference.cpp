#define MOD 1000000007

class Solution {
  private:
    int CountPartitions(vector<int>& arr, int sum1, int& totalSum, int index, int& d, vector<vector<int>>& dp){

        //base conditions
        
        if(sum1 + d > totalSum - sum1){return 0;}

        if(index >= arr.size()){
            return (sum1 + d == totalSum - sum1);
        }
        
        if(dp[index][sum1] != -1){
            return dp[index][sum1];
        }
        
        int total = 0;
        
        //pick
        total += CountPartitions(arr, sum1 + arr[index], totalSum, index+1, d, dp);
        
        //don't pick
        total += CountPartitions(arr, sum1, totalSum, index+1, d, dp);
        
        return dp[index][sum1] = total % MOD;
    }
    
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        
        int sum = 0;
        for(int num : arr){
            sum += num;
        }
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return CountPartitions(arr, 0, sum, 0, d, dp);
    }
};