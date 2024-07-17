class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if(n<=2){return n;}
        
        unordered_map<int,int> dp[n];
        
        int ans = 0;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                
                int len = 1;
                int diff = A[i] - A[j];
                
                if(dp[j].count(diff)){
                    len = dp[j][diff];
                }
                
                dp[i][diff] = len + 1;
                ans = max(ans, dp[i][diff]);
            }
        }
        
        return ans;
    }
};