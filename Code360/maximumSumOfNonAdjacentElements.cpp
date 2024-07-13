#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i < nums.size(); i++){
        
        int inc = nums[i] + prev2;
        int exc = prev1;

        int curr = max(inc, exc);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}