class Solution {

    void SubsetSum(vector<int>& arr, int index, vector<int>& ans, int sum){
        
        if(index >= arr.size()){
            ans.push_back(sum);
            return;
        }
        
        //pick
        SubsetSum(arr, index+1, ans, sum+arr[index]);
        
        //leave
        SubsetSum(arr, index+1, ans, sum);
    }
    
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        SubsetSum(arr, 0, ans, 0);
        return ans;
    }
};