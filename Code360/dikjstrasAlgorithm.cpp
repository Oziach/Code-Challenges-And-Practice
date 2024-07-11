#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<int> costs (vertices, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> minHeap;

    vector<vector<pair<int,int>>> adj(vertices);

     for(vector<int> uVC : vec){
        int u = uVC[0];
        int v = uVC[1];
        int cost = uVC[2];

        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});

    }

    minHeap.push({0, source});
    costs[source] = 0;

    while(!minHeap.empty()){
        int u = minHeap.top().second;
        int costToU = minHeap.top().first;

        minHeap.pop();
        if(costs[u] < costToU){continue;}

        for(pair<int,int> vCostPair : adj[u]){
            int v = vCostPair.first;
            int costUToV = vCostPair.second;

            int totalCostToV = costToU + costUToV;
            if(totalCostToV < costs[v]){
                costs[v] = totalCostToV;
                minHeap.push({totalCostToV, v});
            }
        }
    }

    return costs;
}
