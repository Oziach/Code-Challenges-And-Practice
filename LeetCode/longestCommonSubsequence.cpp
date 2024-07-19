class Solution {
public:

    int GetLongest(string text1, string text2, int index1, int index2){
        
        if(index1 >= text1.size() || index2 > text2.size()){return 0;}

        int longest = 0;

        if(text1[index1] == text2[index2]){
            longest = 1 + GetLongest(text1, text2, index1 + 1, index2 + 1);
        }
        else{
            //move forward first
            int first = GetLongest(text1, text2, index1+1, index2);

            //move forward second
            int second = GetLongest(text1, text2, index1, index2 + 1);  

            longest = max(first, second);
        }

        return longest;
    }

    int GetLongestMem(string text1, string text2, int index1, int index2, vector<vector<int>>& dp){
        
        if(index1 >= text1.size() || index2 > text2.size()){return 0;}
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        int longest = 0;

        if(text1[index1] == text2[index2]){
            longest = 1 + GetLongestMem(text1, text2, index1 + 1, index2 + 1, dp);
        }
        else
        {
            //move forward first
            int first = GetLongestMem(text1, text2, index1+1, index2, dp);

            //move forward second
            int second = GetLongestMem(text1, text2, index1, index2 + 1, dp);  

            longest = max(first, second);
        }

        return dp[index1][index2] = longest;
    }

    int GetLongestTab(string text1, string text2){
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        for(int index1 = text1.length() - 1; index1 >= 0; index1--){
            for(int index2 = text2.length() - 1; index2 >= 0; index2--){

                int longest = 0;

                if(text1[index1] == text2[index2]){
                    longest = 1 + dp[index1 + 1][index2 + 1];
                }
                else
                {
                    //move forward first
                    int first = dp[index1+1][index2];

                    //move forward second
                    int second = dp[index1][index2 + 1];  

                    longest = max(first, second);
                }

                dp[index1][index2] = longest;

            }
        }

        return dp[0][0];

    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        return GetLongestTab(text1, text2);
    }
};