class Solution {
private:
    int MinCost(vector<int>& cuts, int start, int end, vector<vector<int>>& dp){

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        //logic
        int minCost = 0;

        for(int i = start+1; i < end; i++){

                int cutPos = cuts[i];
            
                int costToCut = cuts[end] - cuts[start];
                                    
                int totalCost = costToCut + MinCost(cuts, start, i, dp) + MinCost(cuts, i, end, dp);
                
                if(minCost == 0 || totalCost < minCost){minCost = totalCost;}
        }

        return dp[start][end] =  minCost;

    }

public:
    int minCost(int n, vector<int>& cuts) {
        
        vector<int> newCuts = cuts;
        newCuts.push_back(0);
        newCuts.push_back(n);
        sort(newCuts.begin(), newCuts.end());

        vector<vector<int>> dp(newCuts.size(), vector<int>(newCuts.size(), -1));
        return MinCost(newCuts, 0, newCuts.size()-1, dp);
    }
};class Solution {
private:
    int MinCost(vector<int>& cuts, int start, int end, vector<vector<int>>& dp){

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        //logic
        int minCost = 0;

        for(int i = start+1; i < end; i++){

                int cutPos = cuts[i];
            
                int costToCut = cuts[end] - cuts[start];
                                    
                int totalCost = costToCut + MinCost(cuts, start, i, dp) + MinCost(cuts, i, end, dp);
                
                if(minCost == 0 || totalCost < minCost){minCost = totalCost;}
        }

        return dp[start][end] =  minCost;

    }

public:
    int minCost(int n, vector<int>& cuts) {
        
        vector<int> newCuts = cuts;
        newCuts.push_back(0);
        newCuts.push_back(n);
        sort(newCuts.begin(), newCuts.end());

        vector<vector<int>> dp(newCuts.size(), vector<int>(newCuts.size(), -1));
        return MinCost(newCuts, 0, newCuts.size()-1, dp);
    }
};