class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        
        int mini = INT_MAX;
        int minRowIndex = -1;
        
        for(int i = 0; i < arr.size(); i++){
            vector<int> row = arr[i];
            
            auto ub = upper_bound(row.begin(), row.end(), 0);
            if(ub != row.end()){
                int index = ub - row.begin();
                if(index < mini){
                    mini = index;
                    minRowIndex = i;
                }
            }
        }
        
        return minRowIndex;
    }
};