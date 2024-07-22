class Solution
{
    public:
    
    
    void merge(int arr[], int l, int m, int r)
    {
         int l1 = m - l + 1;
         int l2 = r - m;
         
         int* arr1 = new int[l1];
         int* arr2 = new int[l2];
         
         for(int i = 0; i < l1; i++){
             arr1[i] = arr[i+l];
         }
         
         for(int i = 0; i < l2; i++){
             arr2[i] = arr[m+1+i];
         }
         
         //merge two sorted arrays
         int ind1 = 0;
         int ind2 = 0;
         int ind = l;
         
        while(ind1 < l1 && ind2 < l2){
             if(arr1[ind1] < arr2[ind2]){
                 arr[ind++] = arr1[ind1++];
             }
             else{
                 arr[ind++] = arr2[ind2++];
             }
        }
        
        while(ind1 < l1){arr[ind++] = arr1[ind1++];}
        while(ind2 < l2){arr[ind++] = arr2[ind2++];}
         
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l >= r){return;}
        
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, mid, r);
    }
};