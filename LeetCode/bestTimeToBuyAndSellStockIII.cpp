class Solution {
public:
    int GetProfitForOne(vector<int>& prices, int start, int end){
        int mini = prices[start];
        int profit = 0;

        for(int i = start; i <= end; i++){
            int price = prices[i];
            if(price < mini){
                mini = price;
            }
            else{
                profit = max(profit, price - mini);
            }
        }

        return profit;
    }


    int maxProfitMySol(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int firstMini = prices[0];
        int firstProfit = 0;

        //fill dp array
        vector<int> backwardsProfits(n);
        int maxProfitBackwards = 0;
        int maxi = prices[n-1];
        for(int i = n-1; i >= 0; i--){
            int price = prices[i];
            if(price > maxi){
                maxi = price;
            }
            else{
                maxProfitBackwards = max(maxProfitBackwards, maxi - prices[i]);
            }

            backwardsProfits[i] = maxProfitBackwards;
        }

        for(int i = 1; i < n-1; i++){
            //logic for first
            if(prices[i] < firstMini){
                firstMini = prices[i];
            }
            else{
                firstProfit = max(firstProfit, prices[i] - firstMini);
            }

            int first = firstProfit;
            int second = backwardsProfits[i+1];
            maxProfit = max(maxProfit, first + second);
        }

        maxProfit = max(maxProfit, GetProfitForOne(prices, 0, n-1));

        return maxProfit;
    }

//////////////////////////////////////////////////////////////////

    int GetMax(vector<int>& prices, int index, bool canBuy, int limit ){
        
        if(index >= prices.size() || limit == 0){return 0;}

        int skip = GetMax(prices, index+1, canBuy, limit);
        
        int buy = 0;
        if(canBuy){
            //buy
            buy = -prices[index] + GetMax(prices, index+1, false, limit);
        }

        //sell
        int sell = 0;
        if(!canBuy){
            sell = prices[index] + GetMax(prices, index+1, true, limit-1);
        }

        return max(buy, max(sell, skip));
    }

    int GetMaxMem(vector<int>& prices, int index, bool canBuy, int limit, vector<vector<vector<int>>>& dp){
        
        if(index >= prices.size() || limit == 0){return 0;}
        if(dp[index][canBuy][limit] != -1){
            return dp[index][canBuy][limit];
        }

        int skip = GetMaxMem(prices, index+1, canBuy, limit, dp);
        
        int buy = 0;
        if(canBuy){
            //buy
            buy = -prices[index] + GetMaxMem(prices, index+1, false, limit, dp);
        }

        //sell
        int sell = 0;
        if(!canBuy){
            sell = prices[index] + GetMaxMem(prices, index+1, true, limit-1, dp);
        }

        return dp[index][canBuy][limit] = max(buy, max(sell, skip));
    }

    int GetMaxTab(vector<int>& prices){
        int n = prices.size();
       vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int index = n-1; index >= 0; index--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){  
                for(int limit = 1; limit <= 2; limit++){
              
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

        return dp[0][true][2];
    }

    //Space optimization possible to O(1) c:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return GetMaxTab(prices);
    }
};