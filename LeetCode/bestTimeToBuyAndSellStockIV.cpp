class Solution {
public:

    int GetMaxTab(vector<int>& prices, int k){
        int n = prices.size();
       vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int index = n-1; index >= 0; index--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){  
                for(int limit = 1; limit <= k; limit++){
              
                    int skip = dp[index+1][canBuy][limit];
                    int buy = 0;
                    if(canBuy){
                        //buy
                        buy = -prices[index] + dp[index+1][false][limit];
                    }

                    //sell
                    int sell = 0;
                    if(!canBuy){
                        sell = prices[index] + dp[index+1][true][limit-1];
                    }

                    dp[index][canBuy][limit] = max(buy, max(sell, skip));
                }
            }
        }

        return dp[0][true][k];
    }

    int GetMaxSO(vector<int>& prices, int k){
        int n = prices.size();
       vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        vector<vector<int>> current(2, vector<int>(2, 0));
        vector<vector<int>> next(2, vector<int>(2, 0));


        for(int index = n-1; index >= 0; index--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){  
                for(int limit = 1; limit <= k; limit++){
              
                    int skip = next[canBuy][1];
                    int buy = 0;
                    if(canBuy){
                        //buy
                        buy = -prices[index] + next[false][1];
                    }

                    //sell
                    int sell = 0;
                    if(!canBuy){
                        sell = prices[index] + next[true][0];
                    }

                    current[canBuy][1] = max(buy, max(sell, skip));
                }
                next[canBuy][1] = next[canBuy][0];
            }
            next = current;
        }

        return next[true][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        return GetMaxTab(prices, k);
    }
};