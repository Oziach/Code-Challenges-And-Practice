class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int part1EndIndex = -1;
        int i = 0;
        for(i; i < intervals.size(); i++){
            if(intervals[i][1] < newInterval[0]){continue;}
            break;
        }

        part1EndIndex = i-1;

        for(i; i < intervals.size(); i++){
            if(intervals[i][0] > newInterval[1]){break;}

            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }

        vector<vector<int>> ans;
        for(int j = 0; j <= part1EndIndex; j++){
            ans.push_back(intervals[j]);
        }

        ans.push_back(newInterval);

        for(i; i < intervals.size(); i++){
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};