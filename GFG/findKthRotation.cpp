class Solution {
  public:
  
    int findKRotation(vector<int> &arr) {
        int s = 0;
        int e = arr.size() - 1;
        int minIndex = 0;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(arr[s] <= arr[e]){
                minIndex = arr[minIndex] < arr[mid] ? minIndex : s;
                break;
            }
            
            if(arr[s] <= arr[mid]){
                minIndex = s;
                s = mid+1;
            }
            else{
                minIndex = arr[minIndex] < arr[mid] ? minIndex : mid;
                e = mid - 1;
            }
        }
        
        return minIndex;
    }
};