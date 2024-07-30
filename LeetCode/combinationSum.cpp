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
        CombinationSum(arr, target-arr[ind], ind, comb, ans);
        comb.pop_back();

        //dont pick
        CombinationSum(arr, target, ind+1, comb, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        CombinationSum(candidates, target, 0, comb, ans);
        return ans;
    }
};