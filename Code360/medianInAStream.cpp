#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	
	priority_queue<int> maxHeapLeft;
	
	priority_queue<int, vector<int>, greater<int>> minHeapRight;

	
	vector<int> ans;

	for(int i = 0; i < arr.size(); i++){
		int num = arr[i];

		if(maxHeapLeft.empty() || num < maxHeapLeft.top()){
			maxHeapLeft.push(num);
		}
		else{
			minHeapRight.push(num);
		}

		//balance size
		while(abs(maxHeapLeft.size() - minHeapRight.size() > 1)){
			if(maxHeapLeft.size() > minHeapRight.size()){
				minHeapRight.push(maxHeapLeft.top());
				maxHeapLeft.pop();
			}
			else{
				maxHeapLeft.push(minHeapRight.top());
				minHeapRight.pop();
			}
		}

		//if odd and if even logic
		int sizeDiff = maxHeapLeft.size() - minHeapRight.size();
		if(sizeDiff == 0){ans.push_back((maxHeapLeft.top() + minHeapRight.top())/2);}
		else if(sizeDiff == 1){ans.push_back(maxHeapLeft.top());}
		else{ans.push_back(minHeapRight.top());}
		
	}

	return ans;

}