class Solution{
    private:
    
    bool IsMaxHeap(int arr[], int n, int currIndex){
        
        if(currIndex >= n/2){return true;}
        
        int leftChild = arr[currIndex*2 + 1];
        int rightChild = arr[currIndex*2 + 2];
        int curr = arr[currIndex];
        
        return (curr >= leftChild && curr >= rightChild 
        && IsMaxHeap(arr, n, currIndex*2 + 1) && IsMaxHeap(arr, n, currIndex*2 + 2));
    }
    
    public:
    bool isMaxHeap(int arr[], int n)
    {
        return IsMaxHeap(arr, n, 0) ;
    }
};