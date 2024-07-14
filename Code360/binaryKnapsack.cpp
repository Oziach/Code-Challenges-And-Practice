#include <bits/stdc++.h> 

int GetMaxValue(vector<int>& weight, vector<int>& value, int index, int capacity){

	if(index < 0){return 0;}

	//include
	int include = 0;
	if(weight[index] <= capacity){
		include = value[index] + GetMaxValue(weight, value, index-1,  capacity-weight[index]);
	}

	//exclude
	int exclude = GetMaxValue(weight, value, index-1, capacity);

	return max(include, exclude);
}


int GetMaxValueMem(vector<int>& weight, vector<int>& value, int index, int capacity, 
vector<vector<int>>& dp){

	if(index < 0){return 0;}

	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}

	//include
	int include = 0;
	if(weight[index] <= capacity){
		include = value[index] + GetMaxValueMem(weight, value, index-1,  capacity-weight[index], dp);
	}

	//exclude
	int exclude = GetMaxValueMem(weight, value, index-1, capacity, dp);

	dp[index][capacity] = max(include, exclude);
	return dp[index][capacity];
}

int GetMaxValueTab(vector<int> weight, vector<int> value, int capacity, int n){
	
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

	for(int w = weight[0]; w <= capacity; w++){
		if(weight[0] <= capacity)
			dp[0][w] = value[0];
		else
			dp[0][w] = 0;
	}

	for(int index = 1; index < n; index++){
		for(int w = 0; w <= capacity; w++){
			
			int include = 0;
			//include
			if(weight[index] <= w)
				include = value[index] + dp[index-1][w - weight[index]];
			
			//exclude
			int exclude = dp[index-1][w];

			dp[index][w] = max(include, exclude);

		}
	}

	return dp[n-1][capacity];
}

int GetMaxValueSO(vector<int> weight, vector<int> value, int capacity, int n){
	vector<int> prev(capacity+1, 0);
	for(int w = 0; w <= capacity; w++){
		if(weight[0] <= w){
			prev[w] = value[0];
		}
		else{
			prev[w] = 0;
		}
	}

	for(int index = 1; index < n; index++){

		vector<int> current(capacity+1, 0);

		for(int w = 0; w <= capacity; w++){
			//include
			int include = 0;
			if(w >= weight[index]){
				include = value[index] + prev[w-weight[index]];
			}

			int exclude = prev[w];

			current[w] = max(include, exclude);
		}
		prev = current;
	}

	return prev[capacity];
}

//the last S serves the same purpose as the last S in 'dds'
int GetMaxValueSOS(vector<int> weight, vector<int> value, int capacity, int n){
	
	vector<int> current(capacity+1, 0);

	for(int w = 0; w <= capacity; w++){
		if(weight[0] <= w){
			current[w] = value[0];
		}
		else{
			current[w] = 0;
		}
	}

	for(int index = 1; index < n; index++){

		for(int w = capacity; w >= 0; w--){
			//include
			int include = 0;
			if(w >= weight[index]){
				include = value[index] + current[w-weight[index]];
			}

			int exclude = current[w];

			current[w] = max(include, exclude);
		}

	}

	return current[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{	
	//vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return GetMaxValueSO(weight, value, maxWeight, n);
}