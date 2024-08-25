class Solution{
private:
    int Util(int W, int val[], int wt[], int index, vector<vector<int>>& dp){
        
        if(W == 0){return 0;}
        if(index < 0){return 0;}
        
        if(dp[W][index] != -1){
            return dp[W][index];
        }
        
        int maxVal = 0;
        
        //take item if possible
        if(W - wt[index] >= 0){
            maxVal = val[index] + Util(W-wt[index], val, wt, index, dp);
        }
        
        //move on to next item
        maxVal = max(maxVal, Util(W, val, wt, index-1, dp));
        
        return dp[W][index] = maxVal;
    }
    
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(W+1, vector<int>(N, -1));
        int ans = Util(W, val, wt, N-1, dp);
        
        if(ans == INT_MIN){return 0;}
        return ans;
    }
};