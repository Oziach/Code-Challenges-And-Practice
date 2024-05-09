#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   

    for(int j = 0; j < arr.size() - 1; j++){
        int minIndex = j;
        
        for(int i = j+1; i < arr.size(); i++){
            if(arr[i] < arr[minIndex]){
                minIndex = i;
            }
        }
        swap(arr[j], arr[minIndex]);
    }
