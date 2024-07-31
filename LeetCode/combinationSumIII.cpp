class Solution {
private:
    void FillCombinations(int k, int n, int num, vector<int>& combi, vector<vector<int>>& ans){
        
        //base condn
        if(n == 0 && k == 0){
            ans.push_back(combi);
            return;
        }

        if(num > 9){return;}

        //pick
        if(n - num >= 0 && k > 0){
            combi.push_back(num);
            FillCombinations(k-1, n-num, num+1, combi, ans) ;
            combi.pop_back();

        }

        //leave
        FillCombinations(k, n, num+1, combi, ans);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> combi;

        FillCombinations(k, n, 1, combi, ans);
        return ans;
    }
};