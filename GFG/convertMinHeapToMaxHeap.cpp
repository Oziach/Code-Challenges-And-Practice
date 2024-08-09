class Solution{
private:
void Heapify(vector<int>& arr, int N, int index){
 
    
    while(index <= (N-1)/2){
        
        int left = 2*index + 1;
        int right = 2*index + 2;
        int largest = index;
        
        if(left < N && arr[left] > arr[largest]){largest = left;}
        if(right < N && arr[right] > arr[largest]){largest = right;}
        
        if(index == largest){ //i couldn't find anythign to swap with
            break;
        }
        
        swap(arr[index], arr[largest]);
        index = largest;
        
    }
}

public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
        
        for(int i = (N-1)/2; i >= 0; i--){
            Heapify(arr, N, i);
        }
    }
    
};