class Solution{
    public:
    
    void heapify(vector<int>& heap, int size, int i ){
        
        int leftIndex = i*2 + 1;
        int rightIndex = i*2 + 2;
            
        while(i < size){
            
            if(leftIndex < size && heap[i] < heap[leftIndex] && heap[leftIndex] > heap[rightIndex]){
                swap(heap[i], heap[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && heap[i] < heap[rightIndex]){
                swap(heap[i], heap[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
            
            leftIndex = i*2 + 1;
            rightIndex = i*2 + 2;
            
        }
        
    }
    
    int top(vector<int>& heap){
        if(heap.size() > 0)
            return heap[0];
        
        return -1;
    }
    
    int pop(vector<int>& heap){
        heap[0] = heap[heap.size() - 1];
        heapify(heap, heap.size(), 0);
        heap.pop_back();
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> merged;
        
        while(a.size() > 0 && b.size() > 0){
            if(top(a) > top(b)){
                merged.push_back(top(a));
                pop(a);
            }
            else{
                merged.push_back(top(b));
                pop(b);
            }
        }
        
        if(a.size() > 0){
            for(int i = 0; i < a.size(); i++){
                merged.push_back(a[i]);
            }
        }
        
        if(b.size() > 0){
            for(int i = 0; i < b.size(); i++){
                merged.push_back(b[i]);
            }
        }
        

        return merged;
    }
};