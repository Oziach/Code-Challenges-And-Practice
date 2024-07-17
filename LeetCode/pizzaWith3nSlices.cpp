class Solution {
public:

    int GetMaxRec(vector<int>& slices, int index, int end, int size){

        if(size == 0 || index > end){return 0;}

        int pick = slices[index] + GetMaxRec(slices, index+2, end, size-3);
        int dontPick = GetMaxRec(slices, index+1, end, size);

        return max(pick, dontPick);
    }

    int GetMaxMem(vector<int>& slices, int index, int end, int size, vector<vector<int>>& dp){

        if(size == 0 || index > end){return 0;}

        if(dp[size][index] != -1){
            return dp[size][index];
        }  

        int pick = slices[index] + GetMaxMem(slices, index+2, end, size-1, dp);
        int dontPick = GetMaxMem(slices, index+1, end, size, dp);

        return dp[size][index] = max(pick, dontPick);
    }

    int GetMaxTab(vector<int>& slices, int start, int end){
        int n = slices.size();

        vector<vector<int>> dp(n/3+1, vector<int>(n+2, 0));

        for(int s = 1; s <= n/3; s++){
            for(int index = end; index >= start; index--){

                int pick = slices[index] + dp[s-1][index+2];
                int dontPick = dp[s][index+1];

                dp[s][index] = max(pick, dontPick);

            }
        }

        return dp[n/3][start];
    }

    int GetMaxSO(vector<int>& slices, int start, int end){
        int n = slices.size();

        vector<vector<int>> dp(n/3+1, vector<int>(n+2, 0));
        vector<int> currentRow(n+2, 0);
        vector<int> prevRow(n+2, 0);

        for(int s = 1; s <= n/3; s++){
            for(int index = end; index >= start; index--){

                int pick = slices[index] + prevRow[index+2];
                int dontPick = currentRow[index+1];

                currentRow[index] = max(pick, dontPick);

            }
            prevRow = currentRow;
        }

        return prevRow[start];
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n+1, vector<int>(n,-1));
        vector<vector<int>> dp2(n+1, vector<int>(n,-1));

        int firstCase = GetMaxSO(slices, 0, slices.size()-2);
        int secondCase = GetMaxSO(slices, 1, slices.size()-1);
        
        return max(firstCase, secondCase);
    }
};