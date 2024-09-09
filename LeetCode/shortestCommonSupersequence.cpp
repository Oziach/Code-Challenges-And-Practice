class Solution {
private:

   string LongestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int row = 1; row <= n; row++){
            for(int col = 1; col <= m; col++){

                if(text1[row-1] == text2[col-1]){
                    dp[row][col] = 1 + dp[row-1][col-1];
                }
                else{
                    dp[row][col] = max(dp[row][col-1], dp[row-1][col]);
                }
            }
        }

        int row = n;
        int col = m;
        string longest;
        while(row > 0 && col > 0){
            if(text1[row-1] == text2[col-1]){
                longest += text1[row-1];
                row--;
                col--;
            }
            else{
                if(dp[row][col] == dp[row-1][col]){
                    row--;
                }
                else{
                    col--;
                }
            }
        }

        reverse(longest.begin(), longest.end());
        return longest;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        
        string longest = LongestCommonSubsequence(str1, str2);

        int index1 = 0;
        int index2 = 0;
        int subIndex = 0;

        string ans = "";

        while(subIndex < longest.length()){
            if(str1[index1] == str2[index2]){
                ans += str1[index1];
                index1++;
                index2++;
                subIndex++;
           }
           else if(str1[index1] == longest[subIndex]){
                ans += str2[index2++];
           }
           else if(str2[index2] == longest[subIndex]){
                ans += str1[index1++];
           }
           else{
                ans += str1[index1++];
                ans += str2[index2++];
           }
        }

        for(index1; index1 < n; index1++){ans += str1[index1];}
        for(index2; index2 < m; index2++){ans += str2[index2];}

        return ans;
    }
};


//method 2:
class Solution {
private:

   string ShortestCommonSuper(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int row = 1; row <= n; row++){
            for(int col = 1; col <= m; col++){

                if(text1[row-1] == text2[col-1]){
                    dp[row][col] = 1 + dp[row-1][col-1];
                }
                else{
                    dp[row][col] = max(dp[row][col-1], dp[row-1][col]);
                }
            }
        }

        int row = n;
        int col = m;
        string longest;
        while(row > 0 && col > 0){
            if(text1[row-1] == text2[col-1]){
                longest += text1[row-1];
                row--;
                col--;
            }
            else{
                if(dp[row][col] == dp[row-1][col]){
                    longest += text1[row-1];
                    row--;
                }
                else{
                    longest += text2[col-1];
                    col--;
                }
            }
        }

        while(row > 0){longest += text1[row-1]; row--;}
        while(col > 0){longest += text2[col-1]; col--;}


        reverse(longest.begin(), longest.end());
        return longest;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        
        string longest = ShortestCommonSuper(str1, str2);

        return longest;
    }
};