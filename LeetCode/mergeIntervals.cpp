class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            else{
                return a[0] < b[0];
            }
        });
        
        vector<vector<int>> ans;
        vector<int> interval = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            vector<int> current = intervals[i];

            if(current[0] > interval[1]){
                ans.push_back(interval);
                interval = current;
            }
            else if(current[1] < interval[1]){
                continue;
            }
            else {
                interval[1] = current[1];
            }
        }
        ans.push_back(interval);
        return ans;
    }
};