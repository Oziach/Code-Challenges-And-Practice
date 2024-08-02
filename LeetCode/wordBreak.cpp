class Solution {
private:
    bool IsInDict(string word, vector<string>& dict){
        for(int i = 0; i < dict.size(); i++){
            if(dict[i] == word)
                return true;
        }

        return false;
    }

    bool WordBreak(string& s, int startIndex, int currIndex, vector<string>& dict, vector<vector<int>>& dp){

        if(currIndex == s.length()){
            if(startIndex == currIndex){return true;}
            return false;
        }

        if(dp[startIndex][currIndex] != -1){
            return dp[startIndex][currIndex];
        }


        //split here if possible
        if(IsInDict(s.substr(startIndex, currIndex - startIndex + 1), dict)){
            bool found = WordBreak(s, currIndex+1, currIndex+1, dict, dp);
            if(found){return true;}
        }

        //go to next
        if(WordBreak(s, startIndex, currIndex+1, dict, dp)){
            return true;
        }

        return false;

    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return WordBreak(s, 0, 0, wordDict, dp);
    }
};