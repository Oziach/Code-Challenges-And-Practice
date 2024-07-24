class Solution {
public:
    int BinarySearch(vector<int>& nums, int& target, int s, int e){
        
        if(s > e){return false;}
        
        int mid = s + (e-s)/2;

        if(nums[mid] == target){
            return true;
        }

        if(nums[s] == nums[mid] && nums[mid] == nums[e]){
            return BinarySearch(nums, target, s+1, e-1);
        }

        if(nums[mid] >= nums[s]){ //part 1
            if(nums[s] <= target && target < nums[mid]){
                return BinarySearch(nums, target, s, mid-1);
            }
            else{
                return BinarySearch(nums, target, mid+1, e);
            }
        }
        else{ //part 2
            if(nums[mid] < target && target <= nums[e]){
                return BinarySearch(nums, target, mid+1, e);
            }
            else{
                return BinarySearch(nums,target,s, mid-1);
            }
        }
    }


    bool search(vector<int>& arr, int k) {
        int n = arr.size(); // size of the array.
        return BinarySearch(arr, k, 0, n-1);

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
    }
};