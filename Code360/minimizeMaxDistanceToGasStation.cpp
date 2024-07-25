#include<bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	
	int n = arr.size();

	priority_queue<pair<double,int>> maxHeap;

	for(int i = 0; i < n-1; i++){
		maxHeap.push({arr[i+1] - arr[i], 0});
	}

	while(k--){
		auto top = maxHeap.top();
		maxHeap.pop();

		double dist = top.first * (top.second+1);
		int newCount = top.second + 1;
		double newDist = dist / (newCount+1);

		maxHeap.push({newDist, newCount});
	}

	return maxHeap.top().first;
}
