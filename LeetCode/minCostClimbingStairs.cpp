class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int stairs = cost.size();

        int firstCost = cost[0];
        int secondCost = cost[1];

        for(int i = 2; i < stairs; i++){
            int currentCost = min(firstCost, secondCost) + cost[i];
            firstCost = secondCost;
            secondCost = currentCost;
        }

        return min(firstCost, secondCost);
    }
};