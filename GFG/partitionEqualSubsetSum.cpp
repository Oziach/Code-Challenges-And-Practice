class Solution{
public:
    
    bool IsPartable2(int N, int arr[], int sum1, int sum2, int index){
        
        if(index >= N){
            if(sum1 == sum2){return true;}
            return false;
        }
        
        //pick in first
        bool pickFirst = IsPartable2(N, arr, sum1 + arr[index], sum2, index+1);
        
        //pick in second
        bool pickSecond = IsPartable2(N, arr, sum1, sum2 + arr[index], index+1);
        
        return (pickFirst || pickSecond);
    }
    
    bool IsPartable(int N, int arr[], int sum1, int& targetSum, int index, vector<vector<int>>& dp){
        
        if(sum1 > targetSum){return false;}
        if(index >= N){
            if(sum1 == targetSum){return true;}
            return false;
        }
        
        if(dp[index][sum1] != -1){
            return dp[index][sum1];
        }
        
        //pick in first
        bool pickFirst = IsPartable(N, arr, sum1 + arr[index], targetSum, index+1, dp);
        
        //pick in second
        bool pickSecond = IsPartable(N, arr, sum1, targetSum, index+1, dp);
        
        return dp[index][sum1] = (pickFirst || pickSecond);
    }
    
    int equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for(int i = 0; i < N; i++){
            totalSum += arr[i];
        }
        
        if(totalSum & 1){return false;}
        
        vector<vector<int>> dp(N, vector<int>(totalSum, -1));
        
        int targetSum = totalSum/2;
        return IsPartable(N, arr, 0, targetSum, 0, dp);
    }
};