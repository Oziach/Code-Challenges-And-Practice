class Solution {
public:

    int GetMaxSatRec(vector<int>& sat, int index, int time){
        
        if(index >= sat.size()){ return 0; }

        int maxSat = 0;

        //ignore
        if(sat[index] < 0){
            maxSat = max(maxSat, GetMaxSatRec(sat, index+1, time));
        }

        //choose
        maxSat = max(maxSat, sat[index] * time + GetMaxSatRec(sat, index+1, time+1));

        return maxSat;
    }

    int GetMaxSatMem(vector<int>& sat, int index, int time, vector<vector<int>>& dp){
        
        if(index >= sat.size()){ return 0; }

        if(dp[index][time] != -1){
            return dp[index][time];
        }

        int maxSat = 0;

        //ignore
        if(sat[index] < 0){
            maxSat = max(maxSat, GetMaxSatMem(sat, index+1, time, dp));
        }

        //choose
        maxSat = max(maxSat, sat[index] * time + GetMaxSatMem(sat, index+1, time+1, dp));

        return dp[index][time] = maxSat;
    }

    int GetMaxSatTab(vector<int>& sat){
        int n = sat.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        //base condn - all zeros for index n
    
        for(int index = n-1; index >= 0; index--){
            for(int time = index; time >= 0; time--){
                
                int maxSat = 0;

                //ignore
                if(sat[index] < 0){
                    maxSat = max(maxSat, dp[index+1][time]);
                }

                //choose
                if(time < n){
                    maxSat = max(maxSat, sat[index] * (time+1) + dp[index+1][time+1]);
                }

                dp[index][time] = maxSat;
            }
        }

        return dp[0][0];

    }


    int MaxSatisfaction(vector<int>& sat){
        int n = sat.size();
        sort(sat.begin(), sat.end());

        int sum = 0;
        int ans = 0;

        for(int i = n-1; i >= 0; i--){
            sum += sat[i];
            if(ans + sum > ans){
                ans += sum;
            }
            else{
                return ans;
            }
        }

        return ans;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return GetMaxSatSO(satisfaction);
    }
};