
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        
        vector<int> ans;
        
        int greatest = -1;
        for(int i = n-1; i >= 0; i--){
            if(arr[i] >= greatest){
                greatest = arr[i];
                ans.push_back(greatest);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};