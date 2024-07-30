#define MOD 1000000007

class Solution{
    private:
    int helper(int arr[], int n, int sum){
        
        int currIndex = n-1;
        
        if(currIndex < 0){
            if(sum == 0){return 1;}
            //else
            return 0;
        }
        
        int count = 0;
        
        //pick
        count += perfectSum(arr, n-1, sum-arr[currIndex]);
        
        //leave
        count += perfectSum(arr, n-1, sum);
        
        return count % MOD;
    }
    
	public:
	int perfectSum(int arr[], int n, int sum)
	{
       return helper(arr, n, sum);
	}
	  
};