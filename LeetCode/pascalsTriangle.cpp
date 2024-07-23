class Solution {
public:

    vector<int> genRow(int row1Indexed){
        int n = row1Indexed - 1;
        int ele = 1;

        vector<int> row;
        row.push_back(ele);

        for(int r = 0; r < n; r++){
            ele = (ele * (n-r)) / (r + 1);
            row.push_back(ele);
        }

        return row;
    }

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;

        for(int i = 1; i <= numRows; i++){
            ans.push_back(genRow(i));
        }

        return ans;
    }
};