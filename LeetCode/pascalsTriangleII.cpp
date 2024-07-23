class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int n = rowIndex;
        long long  ele = 1;
        ans.push_back(ele);

        for(int r = 0; r < n; r++){
            ele = (1LL * ele * (n - r)) / (r+1);
            ans.push_back(ele);
        }

        return ans;
    }
};