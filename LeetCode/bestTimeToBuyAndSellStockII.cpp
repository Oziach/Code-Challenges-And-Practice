class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = prices[0];

        for(int i = 0; i < prices.size(); i++){
            int price = prices[i];
            if(price > minPrice){
                profit += price - minPrice;
                minPrice = price;
            }
            else{
                //if price < minprice
                minPrice = price;
            }
        }

        return profit;
    }
};