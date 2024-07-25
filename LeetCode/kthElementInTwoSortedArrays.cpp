class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if(m < n){return kthElement(nums2, nums1, m, n, k);}
        int s = max(0, k - m);
        int e = min(k, n);
        int sym = k;

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
            return max(l1Val,l2Val);
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