int GetMinCoinsRec(vector<int>& days, vector<int>& costs, int index, int daysLeft){

    if(index == 0){
        if(daysLeft <= 0){
            return costs[0];
        }
        return 0;
    }

    int daysToNext = days[index] - days[index-1];
    daysLeft = daysLeft < 0 ? 0 : daysLeft;
    
    if(daysLeft > 0){
        return GetMinCoinsRec(days, costs, index-1, daysLeft - daysToNext);
    }

    //call for cost 1
    int cost1 = GetMinCoinsRec(days, costs, index-1, daysLeft + 1 - daysToNext);

    //call for cost 2
    int cost2 = GetMinCoinsRec(days, costs, index-1, daysLeft + 7 - daysToNext);

    //call for cost 3
    int cost3 = GetMinCoinsRec(days, costs, index-1, daysLeft + 30 - daysToNext);

    cost1 += costs[0];
    cost2 += costs[1];
    cost3 += costs[2];
    

    int mini = min(cost1, cost2);
    mini = min(mini, cost3);


    return mini;

}

int GetMinCoinsRec2(int& n, vector<int>& days, vector<int>& costs, int index){

    if(index >= n){
        return 0;
    }

    //first
    int first = GetMinCoinsRec2(n, days, costs, index+1);
    first += costs[0];

    //second
    int i;
    for(i = index; i < n && days[i] < days[index]+7; i++);
    int second = GetMinCoinsRec2(n, days, costs, i);
    second += costs[1];

    //third
    int j;
    for(j = index; j < n && days[j] < days[index]+30; j++);
    int third = GetMinCoinsRec2(n, days, costs, j);
    third+=costs[2];
    
    return min(first, min(second,third));
    
}

int GetMinCoinsMem(int& n, vector<int>& days, vector<int>& costs, int index, vector<int>& dp){
    
    if(index >= n){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }
    
    //first
    int first = GetMinCoinsRec2(n, days, costs, index+1);
    first += costs[0];

    //second
    int i;
    for(i = index; i < n && days[i] < days[index]+7; i++);
    int second = GetMinCoinsMem(n, days, costs, i, dp);
    second += costs[1];

    //third
    int j;
    for(j = index; j < n && days[j] < days[index]+30; j++);
    int third = GetMinCoinsRec2(n, days, costs, j);
    third+=costs[2];
    
    return dp[index] = min(first, min(second,third));
}

int GetMinCoinsTab(int& n, vector<int>& days, vector<int>& costs){

    vector<int> minCoinsForIndex(n+1, INT_MAX);
    minCoinsForIndex[n] = 0;

    for(int i = n-1; i >= 0; i--){
        //first
        int first = minCoinsForIndex[i+1];
        first += costs[0];

        //second
        int j;
        for(j = i; j < n && days[j] < days[i]+7; j++);
        int second = minCoinsForIndex[j];
        second += costs[1];

        //third
        int k;
        for(k = i; k < n && days[k] < days[i]+30; k++);
        int third = minCoinsForIndex[k];
        third+=costs[2];

        minCoinsForIndex[i] = min(first, min(second,third));
    }

    return minCoinsForIndex[0];

}

int GetMinCoinsSO(int& n, vector<int>& days, vector<int>& costs){

    queue<pair<int,int>> monthly;
    queue<pair<int,int>> weekly;
    int ans = 0;

    for(int day : days){

        while(!weekly.empty() && weekly.front().second + 7 <= day){
            weekly.pop();
        }

        while(!monthly.empty() && monthly.front().second + 30 <= day){
            monthly.pop();
        }

        weekly.push({ans + costs[1], day});
        monthly.push({ans + costs[2], day});

        ans = min(ans+costs[0], min(weekly.front().first, monthly.front().first));

    }

    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1, -1);
    return GetMinCoinsSO(n, days, cost);
}