class Solution{
private:
    int MCM(int arr[], int start, int end, vector<vector<int>>& dp){
        
        if(start == end){return 0;}
        if(dp[start][end] != -1){return dp[start][end];}
   
        int minOps = INT_MAX;
        
        for(int i = start; i < end; i++){
            minOps = min(minOps, arr[start-1] * arr[i] * arr[end]
                + MCM(arr, start, i, dp) + MCM(arr, i+1, end, dp));
        }
        
        return dp[start][end] = minOps;
        
    }
    
    //by tabulation/bottomup/gorjfkdv;vbjk
        
    int MCMTab(int arr[], int N){
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        for(int start = N-1; start >= 1; start--){
            for(int end = start+1; end <= N-1; end++){
                        
                        
                int minOps = INT_MAX;
                
                for(int i = start; i < end; i++){
                    minOps = min(minOps, arr[start-1] * arr[i] * arr[end]
                        + dp[start][i] + dp[i+1][end]);
                }
                
                dp[start][end] = minOps;
                
            }
        }   
        
        return dp[1][N-1];
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return MCM(arr, 1, N-1, dp);
    }
};

