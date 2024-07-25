class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if(k < arr[0]){return k;}
        if(k > arr[n-1] - n){return n + k;}

        int s = 0;
        int e = n-1;
        int rangeStart = -1;

        while(s <= e){
            int mid = s + (e-s)/2;
            int numbersMissingTillMid = arr[mid] - (mid + 1);

            if(numbersMissingTillMid < k){
                s = mid + 1;
                rangeStart = mid;
            }
            else{
                e = mid - 1;
            }
        }

        // this works as well: rangeStart = e;
        int numbersMissingTillHere = arr[rangeStart] - (rangeStart+1);
        int tillK = k - numbersMissingTillHere;

        return arr[rangeStart] + tillK;
    }
};