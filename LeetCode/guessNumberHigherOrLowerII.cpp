class Solution {
public:

    int GetMinMem(int s, int e, vector<vector<int>>& dp){

        if(s >= e){return 0;}
        if(dp[s][e] != -1){
            return dp[s][e];
        }

        int maxi = 2147000000;
        for(int i = s; i < e; i++){
            maxi = min(maxi, i + max(GetMinMem(s, i-1, dp), GetMinMem(i+1, e, dp)));
        }

        return dp[s][e] = maxi;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return GetMinMem(1, n, dp);
    }
};