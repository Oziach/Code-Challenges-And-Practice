//this is just n meetings in one room LOL

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int cnt = 0;
        vector<int> currInterval = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            
            if(intervals[i][0] < currInterval[1]){
                if(intervals[i][1] <= currInterval[1]){
                    cnt++;
                    currInterval = intervals[i];
                }
                else{
                    cnt++;
                }
            }
            else{
                currInterval = intervals[i];
            }
        }

        return cnt;
    }
};