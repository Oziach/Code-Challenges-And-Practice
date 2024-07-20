class Solution {
public:

    bool GetMatch(string& s, string& p, int index1, int index2, vector<vector<int>>& dp){

        if(index1 >= s.size()){
            for(index2; index2 < p.size() && p[index2] == '*'; index2++);
        }
        if(index1 >= s.size() && index2 >= p.size()){return true;}
        if(index1 >= s.size() || index2 >= p.size()){return false;}

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        //if characters match
        if(s[index1] == p[index2]){
            return GetMatch(s, p, index1+1, index2+1, dp);
        }
        else
        {
            //for '?'
            bool first = false;
            if(p[index2] == '?'){
                first = GetMatch(s, p, index1+1, index2+1, dp);
            }

            //for '*'
            bool second = false;
            if(p[index2] == '*'){
                second = GetMatch(s, p, index1+1, index2, dp) || GetMatch(s, p, index1, index2+1, dp);
            }

            return dp[index1][index2] = first || second;
        }
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return GetMatch(s, p, 0, 0, dp);
    }
};