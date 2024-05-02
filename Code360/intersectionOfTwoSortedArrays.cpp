#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i = 0;
	int j = 0;

	vector<int> ans;

	while(i < n && j < m){

		int ele1 = arr1[i];
		int ele2 = arr2[j];

		if(ele1 == ele2){
			ans.push_back(ele1);
			i++;
			j++;
		}
		else if(ele1 < ele2){
			i++;
			continue;
		}
		else{
			j++;
			continue;
		}
	}

	return ans;
}