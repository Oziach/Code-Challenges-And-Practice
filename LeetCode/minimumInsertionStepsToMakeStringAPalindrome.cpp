class Solution {
private:
    int MinInsertions(string& s, int index1, int index2, vector<vector<int>>& dp){
        //base conditions
        if(index1 >= index2){return 0;}
        
        if(dp[index1][index2] != -1){return dp[index1][index2];}

        //logic
        if(s[index1] == s[index2]){
            return dp[index1][index2] = MinInsertions(s, index1+1, index2 - 1, dp);
        }

        //else
        return dp[index1][index2] =  1 + min(MinInsertions(s, index1 + 1, index2, dp), MinInsertions(s, index1, index2-1, dp));
    }

    int LongestPalindromeSubsequence(string& s, int index1, int index2, vector<vector<int>>& dp){
         //base conditions
        if(index1 >= s.length() || index2 < 0){return 0;}
        
        if(dp[index1][index2] != -1){return dp[index1][index2];}

        //logic
        if(s[index1] == s[index2]){
            return dp[index1][index2] = 1 + LongestPalindromeSubsequence(s, index1+1, index2 - 1, dp);
        }

        //else
        return dp[index1][index2] =  max(LongestPalindromeSubsequence(s, index1 + 1, index2, dp), LongestPalindromeSubsequence(s, index1, index2-1, dp));
    }

public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return s.length() -  LongestPalindromeSubsequence(s, 0, s.length()-1, dp);
    }
};