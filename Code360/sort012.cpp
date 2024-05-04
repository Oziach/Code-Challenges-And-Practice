#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
 
  int toPlace0 = 0;
  int toPlace2 = n-1;
  int i = 0;

  while( i <= toPlace2){
    
    if(arr[i] == 0){
      swap(arr[i], arr[toPlace0]);
      toPlace0++;
      i++;
    }
    else if(arr[i] == 1){
      i++;
    }
    else{
      swap(arr[i], arr[toPlace2]);
      toPlace2--;
    }
  }



}