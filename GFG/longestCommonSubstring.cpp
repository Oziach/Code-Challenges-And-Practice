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
};