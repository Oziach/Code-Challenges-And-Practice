class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        
        vector<int> curr(3,0);
        vector<int> next(3,0);
        
        for(int day = n-1; day >= 0; day--){
            for(int activity = 0; activity <= 2; activity++){
                
                for(int nextActivity = 0; nextActivity <= 2; nextActivity++){
                    if(nextActivity == activity){continue;}
                    curr[activity] = max(curr[activity], arr[day][activity] + next[nextActivity]);
                }
            }
            next = curr;
        }
        
        return max(curr[0], max(curr[1], curr[2]));
    }
};