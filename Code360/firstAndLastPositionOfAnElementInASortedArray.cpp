#include<bits/stdc++.h>

int firstPos(vector<int>& arr, int s, int e, int k){
    if(s > e){return -1;}

    int mid = s + (e-s)/2;

    if(arr[mid]==k){
        int min = firstPos(arr,s, mid-1, k);
        if(min == -1){
            return mid;
        }
        else{
            return min;
        }
    }
    else if(arr[mid] > k){
        return firstPos(arr, s, mid-1, k);
    }
    else{
        return(firstPos(arr, mid+1, e, k));
    }
}

int lastPos(vector<int>& arr, int s, int e, int k){
    if(s > e){return -1;}

    int mid = s + (e-s)/2;

    if(arr[mid] == k){
        int maxi = lastPos(arr, mid+1, e , k);
        if(maxi == -1){
            return mid;
        }
        else{
            maxi;
        }
    }
    else if(arr[mid] < k){
        return lastPos(arr, mid+1, e, k);
    }
    else{
        return(lastPos(arr, s, mid-1, k));
    }
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> ans;
    ans.first = firstPos(arr, 0, n-1, k);
    ans.second =lastPos(arr, 0, n-1, k);

    return ans;
}
