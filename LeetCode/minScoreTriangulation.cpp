class Solution {
public:

    int GetMinAreaRec(vector<int>& values, int begin, int end){

        if(begin + 1 == end){ return 0; }

        int minScore = INT_MAX;

        for(int i = begin+1; i < end; i++){
    
            int triScore = values[begin] * values[end] * values[i];
            int remScore = GetMinAreaRec(values, begin, i) + GetMinAreaRec(values, i, end);
            int totalScore = triScore + remScore;

            minScore = min(minScore, totalScore);
        }

        return minScore;
    }

    int GetMinAreaMem(vector<int>& values, int begin, int end, vector<vector<int>>& dp){

        if(begin + 1 == end){ return 0; }

        if(dp[begin][end] != -1){
            return dp[begin][end];
        }

        int minScore = INT_MAX;

        for(int i = begin+1; i < end; i++){
    
            int triScore = values[begin] * values[end] * values[i];
            int remScore = GetMinAreaMem(values, begin, i, dp) + GetMinAreaMem(values, i, end, dp);
            int totalScore = triScore + remScore;

            minScore = min(minScore, totalScore);
        }

        return dp[begin][end] = minScore;
    }

    int GetMinAreaTab(vector<int>& values){

        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int begin = n-1; begin >= 0; begin--){
            for(int end = begin + 2; end < n; end++){
                
                int minScore = INT_MAX;
                for(int i = begin+1; i < end; i++){

                    int triScore = values[begin] * values[end] * values[i];
                    int remScore = dp[begin][i] + dp[i][end];
                    int totalScore = triScore + remScore;

                    minScore = min(minScore, totalScore);
                }
                dp[begin][end] = minScore;
            }
        }
        return dp[0][n-1];

    }

    int minScoreTriangulation(vector<int>& values) { 
        int n = values.size(); 
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return GetMinAreaTab(values);
    }
};