class Solution{
	private:
	int GetMax(int arr[], int n, int index, int prev, vector<vector<int>>& maxSumFor){
	    //base condition
	    if(index >= n){return 0;}
	    
	    if(maxSumFor[index][prev+1] != -1){
	        return maxSumFor[index][prev+1];
	    }
	    
	    int maxi = 0;
	    
	    //pick
	    if(prev == -1 || arr[index] > arr[prev]){
	        maxi = arr[index] + GetMax(arr, n, index+1, index, maxSumFor);
	    }
	    
	    //don't pick
	    maxi = max(maxi, GetMax(arr, n, index+1, prev, maxSumFor));
	    
	    return maxSumFor[index][prev+1] = maxi;
	}

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> maxSumFor(n, vector<int>(n+1,-1));
	    return GetMax(arr, n, 0, -1, maxSumFor);
	}  
};