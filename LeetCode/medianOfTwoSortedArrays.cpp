class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(); int m = nums2.size();
        if(m < n){return findMedianSortedArrays(nums2, nums1);}
        int s = 0;
        int e = n;
        int sym = (n + m + 1 ) / 2;

        while(s <= e){
        int mid = s + (e-s)/2;

        //take mid elements from first array and sym - mid elements from second array
        int r1 = mid;
        int r2 = sym - mid;

        int l1 = r1-1;
        int l2 = r2-1;

        int l1Val = l1 < 0 ? INT_MIN : nums1[l1];
        int l2Val = l2 < 0 ? INT_MIN : nums2[l2];

        int r1Val = r1 >= n ? INT_MAX : nums1[r1];
        int r2Val = r2 >= m ? INT_MAX : nums2[r2];

        if(max(l1Val,l2Val) <= min(r1Val, r2Val)){ //found median
            if(m + n & 1){return max(l1Val,l2Val);}
            return (max(l1Val, l2Val) + min(r1Val,r2Val))/2.0;
        }

        if(l1Val > r2Val){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

       } 

       return -1;
    }
};