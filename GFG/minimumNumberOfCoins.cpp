#include <bits/stdc++.h> 

int GetMinCoins(vector<int>& num, int x, vector<int>& coinsNeededForCost){

    if(x == 0){return 0;}
    if(x < 0){return INT_MAX;}

    int minCoinsUsedSoFar = INT_MAX;

    if(coinsNeededForCost[x] != -1){return coinsNeededForCost[x];}

    for(int dnmn : num){
        int coinsUsed = GetMinCoins(num, x-dnmn, coinsNeededForCost);
        
        if(coinsUsed != INT_MAX)
            minCoinsUsedSoFar = min(minCoinsUsedSoFar, coinsUsed+1);
    }

    return coinsNeededForCost[x] = minCoinsUsedSoFar;
    
}

int GetMinCoinsTabular(vector<int>& num, int x){
    vector<int> minCoinsForValue(x+1, INT_MAX);
    
    minCoinsForValue[0] = 0;

    for(int i = 1; i <= x; i++){

        for(int n : num){
           if(i - n >= 0 && minCoinsForValue[i-n] != INT_MAX){
               minCoinsForValue[i] = min(minCoinsForValue[i], minCoinsForValue[i-n] + 1);
           }
        }
    }

    if(minCoinsForValue[x] == INT_MAX)
        return -1;

    return minCoinsForValue[x];
}

int minimumElements(vector<int> &num, int x)
{   
    //vector<int> coinsNeededForCost(x+1, -1);

    // int ans = GetMinCoins(num, x, coinsNeededForCost);
    
    // if(ans == INT_MAX)
    //     return -1;

    // return ans;

    //bottom up soln
    return GetMinCoinsTabular(num, x);
}