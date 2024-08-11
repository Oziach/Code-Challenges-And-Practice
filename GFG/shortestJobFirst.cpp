
class Solution {
  public:
    long long solve(vector<int>& bt) {
        
        sort(bt.begin(), bt.end());
        
        long long totalWaitTime = 0;
        int currTime = 0;
        
        for(int i = 0; i < bt.size(); i++){
            totalWaitTime += currTime;
            currTime += bt[i];
        }


        return totalWaitTime / bt.size();
    }
};