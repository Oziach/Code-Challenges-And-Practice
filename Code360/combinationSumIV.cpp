#include <bits/stdc++.h> 

int GetWaysRec(vector<int>& nums, int tar){

    if(tar == 0){return 1;}
    if(tar < 0){return 0;}

    int ways = 0;
    for(int num : nums){
        ways += GetWaysRec(nums, tar-num);
    }

    return ways;
}

int GetWaysMem(vector<int>& nums, int tar, vector<int>& waysForTarget){

    if(tar == 0){return 1;}
    if(tar < 0){return 0;}

    if(waysForTarget[tar] != -1){
        return waysForTarget[tar];
    }

    int ways = 0;
    for(int num : nums){
        ways += GetWaysMem(nums, tar-num, waysForTarget);
    }

    return waysForTarget[tar] = ways;
}

int GetWaysTab(vector<int>& nums, int tar){
    vector<int> waysForTarget(tar+1, 0);
    waysForTarget[0] = 1;

    for(int i = 1; i <= tar; i++){
        for(int num : nums){
            if(i-num >= 0 && waysForTarget[i-num] != 0){
                waysForTarget[i] += waysForTarget[i-num];
            }
        }
    }

    return waysForTarget[tar];
}


int findWays(vector<int> &num, int tar)
{
    vector<int> waysForTarget(tar+1, -1);
    return GetWaysTab(num, tar);
}