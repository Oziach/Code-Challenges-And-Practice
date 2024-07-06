#include <bits/stdc++.h> 

void heapify(vector<int>& arr, int i){

    int smallestIndex = i;
    int leftIndex = i * 2 + 1;
    int rightIndex = i * 2 + 2;

    while(i < arr.size()/2 + 2){

    
        if(leftIndex < arr.size() && arr[smallestIndex] > arr[leftIndex]){
            smallestIndex = leftIndex;
        }

        if(rightIndex < arr.size() && arr[smallestIndex] > arr[rightIndex]){
            smallestIndex = rightIndex;
        }

        if (i == smallestIndex) {
            return;
        }

        // else
        swap(arr[i], arr[smallestIndex]);
        i = smallestIndex;
        leftIndex = i * 2 + 1;
        rightIndex = i * 2 + 2;
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int leafNodesStart = (arr.size()-1)/2 + 2;

    for(int i = leafNodesStart - 1; i >= 0; i--){
        heapify(arr, i);
    }

    return arr;
}
