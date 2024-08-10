class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	int maxSimultaneous = 0;
    	int currTrains = 0;
    	
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int arrs = 0;
    	int deps = 0;
    	
    	while(arrs < n && deps < n){
    	    if(arr[arrs] <= dep[deps]){
    	        currTrains++;
    	        maxSimultaneous = max(maxSimultaneous, currTrains);
    	        arrs++;
    	    }
    	    else{
    	        currTrains--;
    	        deps++;
    	    }
    	}
    	
    	
    	return maxSimultaneous;
    }
};