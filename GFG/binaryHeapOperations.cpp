*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};*/



//Function to extract minimum value in heap and then to store 
//next minimum value at first index.
int MinHeap::extractMin() 
{
    if(heap_size <= 0){return -1;}
    if(heap_size == 1){heap_size--; return harr[0];}
    
    int popped = harr[0];
    
    harr[0] = harr[heap_size-1]; //swap last element to top
    
    heap_size--;
    MinHeapify(0);
    
    return popped;
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{   
    
    // if(i >= heap_size){return;}
    // decreaseKey(i, INT_MIN);
    // extractMin();
    

    if(i >= heap_size){return;}
    
    if(heap_size == 1){heap_size--; return;}
    
    int lastIndex = heap_size - 1;
    
    harr[i] = harr[lastIndex];
    heap_size--;
    
    //when swapping with the last element, WE CANNOT GUARANTEE WHETHER IT'S SMALLER OR GREATER.
    //ONLY, ONLY EVER SWAP THE LAST ELEMENT WITH THE FIRST ELEMENT. PERIOD. NOWHERE ELSE. 
    //to do deletions like this instead...no, don't swap it with the top idiot. very specifically, decrease key on it by setting
    //it to INT_MIN instead.
    //okay at this point my own solution of doing both minHeapify and decraseKey to accound for both possibilties after swapping 
    //with the last element seems like the better solution
    MinHeapify(i);
    decreaseKey(i, harr[i]);
 
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    if(heap_size == capacity){return;}
    
    heap_size++;
    int lastIndex = heap_size - 1;
    
    harr[lastIndex] = k;
    decreaseKey(lastIndex, k);
    
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) 
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
    
}