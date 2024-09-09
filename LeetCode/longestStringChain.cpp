class Solution {
private:
    bool IsPred(string& a, string& b){
        if(a.length() + 1 != b.length()){            
            return false;}

        int missingCount = 0;
        int i = 0;
        int j = 0;

        while(i < a.length() && j < b.length()){
            if(a[i] != b[j]){
                missingCount++;
                j++;
            }
            else{
                i++;
                j++;
            }

            if(missingCount > 1){
                return false;}
        }

        return true;
    }

    int Longest(vector<string>& words, int index, int prevIndex, vector<vector<int>>& dp){

        //base cases
        if(index >= words.size()){return 0;}
        if(dp[index][prevIndex+1] != -1){
            return dp[index][prevIndex+1];
        }

        //logic
        int longest = 0;
        

        //pick
        if(prevIndex == -1 || IsPred(words[prevIndex], words[index])){
            longest = 1 + Longest(words, index+1, index, dp);
        }

        //not pick, move to next
        longest = max(longest, Longest(words, index+1, prevIndex, dp));

        return dp[index][prevIndex+1] = longest;
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){return a.length() < b.length();});
        vector<vector<int>> dp(words.size(), vector<int>(words.size()+1, -1));
        return Longest(words, 0, -1, dp);
    }
};