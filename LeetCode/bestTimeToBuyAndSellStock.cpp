class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int maxProfit = 0;
        int n = prices.size();

        
        for(int i = n-1; i >= 0; i--){
            if(prices[i] > maxi){
                maxi = prices[i];
            }

            maxProfit = max(maxProfit, maxi - prices[i]);
        }

        return maxProfit;
    }
};