#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    map<int, list<pair<int,int>>> adj;
    for(pair<pair<int,int>, int> entry : g){
        pair<int,int> uV = entry.first;
        int cost = entry.second;
        int u = uV.first;
        int v = uV.second;

        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    vector<bool> visited(n+1, false);
    vector<int> costs(n+1, INT_MAX);
    vector<int> parent(n+1, -1);

    costs[1] = 0;

    for(int i = 1; i < n; i++){ //node counter;

        //get min node from costs
        int mini = INT_MAX;
        int minIndex = 0;

        for(int current = 1; current <= n; current++){
            if(!visited[current] && costs[current] < mini){
                
                minIndex = current;
                mini = costs[current];
            }
        }

        visited[minIndex] = true;

        for(pair<int,int> vCostPair : adj[minIndex]){
            int v = vCostPair.first;
            int cost = vCostPair.second;

            if(!visited[v] && cost < costs[v]){
                parent[v] = minIndex;
                costs[v] = cost;
            }
        }

    }

    vector<pair<pair<int,int>, int>> ans;
    for(int i = 2; i <= n ; i++){
        ans.push_back({{parent[i], i}, costs[i]});
    }

    return ans;

}
