#include <bits/stdc++.h>

int subarraysXor(vector<int> &nums, int k) {

           
        int n = nums.size();
        map<int, int> xrToCount;

        int xr = 0;
        int count = 0;

        for(int i = 0; i < n; i++){
            
            xr = xr ^ nums[i];

            if(xr == k){
                count++;
            }

            int rem = xr ^ k;
            if(xrToCount.count(rem)){
                count += xrToCount[rem];
            }

            xrToCount[xr]++;
        }

        return count;

}