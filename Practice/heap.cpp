
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    
    heap(){
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int n){
        size++;
        int pos = size;
        arr[pos] = n;
        
        int parent = pos/2;
        
        while(parent > 0 && arr[parent] < n){
            swap(arr[parent], arr[pos]);
            pos = parent;
            parent = pos/2;
        }
    }
    
    void remove(){
        
        if(size == 0) return;
        
        arr[1] = arr[size];
        size--;
        
        int i = 1;
        int leftIndex = i * 2;
        int rightIndex = i * 2 + 1;
        
        while(i < size){
            
            if(leftIndex <= size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            
            else if(rightIndex <= size && arr[i] < arr[rightIndex] && arr[rightIndex] > arr[leftIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
            
            leftIndex = i * 2;
            rightIndex = i * 2 + 1;
            
        }
    }
    
   
    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
    }
};

 void heapify(int arr[], int n, int i){
        
        if(i > n/2) {return;}
        
        int largestInd = i;
        int leftIndex = i*2;
        int rightIndex = i*2 + 1;
        
        if(i < n){
            
            if(leftIndex <= n && arr[leftIndex] > arr[largestInd]){
                largestInd = leftIndex;
            }
             if(rightIndex <= n && arr[rightIndex] > arr[largestInd]){
                largestInd = rightIndex;
            }
        
            if(largestInd == i)
                return;
            //else
            swap(arr[i], arr[largestInd]);
            heapify(arr, n, largestInd);
        }
 }

int main()
{   
    heap h;
    h.insert(50);
    h.insert(47);
    h.insert(48);
    h.insert(46);
    h.print();
    cout << "\n";
        
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }
    
    //pritn array
    for(int i = 1; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
