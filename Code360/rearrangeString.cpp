#include <bits/stdc++.h> 
string reArrangeString(string &s)
{	

	map<char, int> charFreq;
	priority_queue<pair<int, char>> maxHeap;

	for(char ch : s){
		charFreq[ch]++;
	}

	for(pair<char,int> p : charFreq){
		maxHeap.push({p.second, p.first});
	}

	string ans = "";

	pair<int,char> block = {-1, '*'};

	while(!maxHeap.empty()){
		auto top = maxHeap.top();
		maxHeap.pop();

		ans += top.second;
		top.first--;

		if(block.first > 0){
			maxHeap.push(block);
		}

		block = top;
	}

	if(block.first > 0){
		return "not possible";
	}
	
	return ans;
}
