class Solution {
public:
    
    int Merge(vector<int>& nums, int s, int mid, int e){
        int l1 = mid - s + 1;
        int l2 = e - mid;

        int* arr1 = new int[l1];
        int* arr2 = new int[l2];

        //populate the arrays
        for(int i = 0; i < l1; i++){
            arr1[i] = nums[s + i];
        }
        for(int i = 0; i < l2; i++){
            arr2[i] = nums[mid + 1 + i];
        }

        int ind1 = 0;
        int ind2 = 0;
        int ind = s;

        int count = 0;

        //count pairs
        while(ind1 < l1 && ind2 < l2){
            if(arr1[ind1] > 1LL * 2 * arr2[ind2]){
                count += l1 - ind1;
                ind2++;
            }
            else{
                ind1++;
            }
        }

        ind1 = ind2 = 0;

        //go through arrays
        while(ind1 < l1 && ind2 < l2){
            
            //logic to check for reverse pairs
            if(arr1[ind1] < arr2[ind2]){
                nums[ind++] = arr1[ind1++];
            }
            else{
                nums[ind++] = arr2[ind2++];
            }
        }

        while(ind1 < l1){nums[ind++] = arr1[ind1++];}
        while(ind2 < l2){nums[ind++] = arr2[ind2++];}

        delete[] arr1;
        delete[] arr2;  

        return count;
    }

    int MergeSort(vector<int>& nums, int s, int e){
        if(s >= e){return 0;}

        int count = 0;
        int mid = s + (e-s)/2;
        count += MergeSort(nums, s, mid);
        count += MergeSort(nums, mid+1, e);
        count += Merge(nums, s, mid, e);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return MergeSort(nums, 0, nums.size()-1);
    }
};