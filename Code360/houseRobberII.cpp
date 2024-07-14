#include <bits/stdc++.h> 

long long GetMaxSum(vector<int>& valueInHouse, int start, int end){
    long long int prev2 = 0;
    long long int prev1 = valueInHouse[start];

    for(int i = start + 1; i <= end; i++){
        long long int inc = prev2 + valueInHouse[i];
        long long int exc = prev1;

        long long int current = max(inc,exc);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{   
    int n = valueInHouse.size();

    if(n==1){return valueInHouse[0];}
    return max(GetMaxSum(valueInHouse, 0, n-2), GetMaxSum(valueInHouse, 1, n-1));
}