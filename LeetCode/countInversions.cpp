class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void Merge(long long arr[], int s, int mid, int e, long long& count){
        
        int l1 = mid - s + 1;
        int l2 = e - mid;
        
        long long int* arr1 = new long long int[l1];
        long long int* arr2 = new long long int[l2];
        
        for(int i = 0; i < l1; i++){
            arr1[i] = arr[s+i];
        }
        
        for(int i = 0; i < l2; i++){
            arr2[i] = arr[mid + 1 + i];
        }
        
        //merge two sorted arrays while keeping track of count
        int ind1 = 0;
        int ind2 = 0;
        int ind = s;
        
        while(ind1 < l1 && ind2 < l2){
            if(arr1[ind1] <= arr2[ind2]){
               arr[ind++] = arr1[ind1++]; 
            }
            else{
                count += l1 - ind1;
                arr[ind++] = arr2[ind2++];
            }
        }
        
        while(ind1 < l1){arr[ind++] = arr1[ind1++];}
        while(ind2 < l2){arr[ind++] = arr2[ind2++];}
        
    }
    
    void MergeSort(long long arr[], int s, int e, long long& count){
        
        if(s >= e){return;}

        int mid = s + (e-s)/2;
        
        MergeSort(arr, s, mid, count);
        MergeSort(arr, mid+1, e, count);
        
        Merge(arr, s, mid, e, count);
        
    }
    
    long long int inversionCount(long long arr[], int n) {
        long long count = 0;
        MergeSort(arr, 0, n-1, count);
        return count;
    }
};