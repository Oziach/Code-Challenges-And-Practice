class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low >= high){return;}
        
        int pI = partition(arr, low, high);
        quickSort(arr, low, pI-1);
        quickSort(arr, pI+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        
       int placeIndex = low;
       
       for(int i = low; i < high; i++){
           if(arr[i] < arr[high]){
               swap(arr[placeIndex++], arr[i]);
           }
       }
       
       swap(arr[placeIndex], arr[high]);
       
       return placeIndex;
    }
};