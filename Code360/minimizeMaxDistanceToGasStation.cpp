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

//using binary search:
int GetCount(vector<int>& arr, double dist){
	
	int count = 0;

	for(int i = 1; i < arr.size(); i++){

		int noInBetween = ((arr[i] - arr[i-1]) / dist);

		if(arr[i] - arr[i-1] / dist == noInBetween){
			noInBetween--;
		}
		count += noInBetween;
	}

	return count;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	
	long double s = 0;
	long double e = 0;

	for(int i = 0; i < arr.size() - 1; i++){
		e = max(e, (long double)(arr[i+1] - arr[i]));
	}

	long double diff = 1e-6;
	while(e - s > diff){
		long double mid = (s + e)/2.0;
		int numberOfStations = GetCount(arr, mid);

		if(numberOfStations > k){
			s = mid;
		}
		else{
			e = mid;
		}
	}

	return e;
}
