class Solution {
public:

    int GetMinActions(string& word1, string& word2, int index1, int index2, vector<vector<int>>& dp){
        
        if(index2 >= word2.length()){
            return word1.length() - index1;
        }
        
        else if(index1 >= word1.length()){
            return word2.length() - index2;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        if(word1[index1] == word2[index2]){
            return dp[index1][index2] = GetMinActions(word1, word2, index1+1, index2+1, dp);
        }
        else{
            //if chars not equal

            //insert
            int insert = 1 + GetMinActions(word1, word2, index1, index2+1, dp);

            //delete
            int del = 1 + GetMinActions(word1, word2, index1+1, index2, dp);

            //replace
            int replace = 1 + GetMinActions(word1, word2, index1+1, index2+1, dp);

            return dp[index1][index2] = min(insert, min(del, replace));
        }
    }

    int GetMinTab(string& word1, string& word2){
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));

        for(int index1 = word1.length(); index1 >= 0; index1--){
            for(int index2 = word2.length(); index2 >= 0; index2--){
                
                //base cases
                if(index2 >= word2.length()){
                    dp[index1][index2] = word1.length() - index1;
                    continue;
                }
        
                else if(index1 >= word1.length()){
                    dp[index1][index2] = word2.length() - index2;
                    continue;
                }
                //base cases over


                if(word1[index1] == word2[index2]){
                    dp[index1][index2] = dp[index1+1][index2+1];
                }
                else{
                    //if chars not equal

                    //insert
                    int insert = 1 + dp[index1][index2+1];

                    //delete
                    int del = 1 + dp[index1+1][index2];

                    //replace
                    int replace = 1 + dp[index1+1][index2+1];

                    
                    dp[index1][index2] = min(insert, min(del, replace));
                }     
            }
        }

        return dp[0][0];
        
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return GetMinTab(word1, word2);
    }
};