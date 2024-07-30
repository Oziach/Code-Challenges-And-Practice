class Solution {
private:
    void CombinationSum(vector<int>& arr, int target, int ind, vector<int>& comb, vector<vector<int>>& ans){
        
        if(target < 0){return;}
        
        if(ind >= arr.size()){

                if(target == 0){
                    ans.push_back(comb);
                }
                //else
                return; 
        }

        //pick
        comb.push_back(arr[ind]);
        CombinationSum(arr, target-arr[ind], ind+1, comb, ans);
        comb.pop_back();

        //skip dupes, through some weird unintuitive looking perfectly clean code
        for(ind; ind < arr.size() - 1 && arr[ind] == arr[ind+1]; ind++);

        //dont pick
        CombinationSum(arr, target, ind+1, comb, ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combi;
        sort(candidates.begin(), candidates.end());
        CombinationSum(candidates, target, 0, combi, ans);
        return ans;
    }
};