class Solution {
  private:
    int Longest(string& str1, string& str2, int index1, int index2, int& longest, vector<vector<int>>& dp){
    
        //base conditions
        if(index1 >= str1.length() || index2 >= str2.length()){
            return 0;
        }
        
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        
        //logic
        Longest(str1, str2, index1+1, index2, longest, dp);
        Longest(str1, str2, index1, index2+1, longest, dp);
        
        if(str1[index1] == str2[index2]){
            int substrLen = 1 + Longest(str1, str2, index1+1, index2+1, longest, dp);
            longest = max(longest, substrLen);
            return dp[index1][index2] = substrLen;
        }
        
        return dp[index1][index2] = 0;
        
    }
    
  public:
    int longestCommonSubstr(string str1, string str2) {
        int longest = 0;
        vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
        Longest(str1, str2, 0, 0, longest, dp);
        return longest;
    }

    //////////space optimized:
    class Solution2 {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        
        int longest = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                if(str1[i-1] == str2[j-1]){
                    curr[j] = 1 + prev[j-1];
                    longest = max(longest, curr[j]);
                }
                else{
                    curr[j] = 0;                    
                }
            }
            
            prev = curr;
        }
        
        return longest;
    }
};
};