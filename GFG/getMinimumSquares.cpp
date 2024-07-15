class Solution{
	public:
	
	int MinSquaresRec(int n){
	       
	   if(n == 0){return 0;}
	       
	    int minWays = n;
	    for(int i = 1; i*i <= n ; i++){
	        minWays = min(minWays, 1 + MinSquaresRec(n-(i*i)));
	    }
	    
	    return minWays;
	}
	
	int MinSquaresMem(int n, vector<int>& minWaysForN){
	       
	   if(n == 0){return 0;}
	   
	   if(minWaysForN[n] != -1){
	       return minWaysForN[n];
	   }
	       
	    int minWays = n;
	    
	    for(int i = 1; i*i <= n ; i++){
	        int temp = i*i;
	        minWays = min(minWays, 1 + MinSquaresMem(n-temp, minWaysForN));
	    }

	    return minWaysForN[n] = minWays;
	}
	
	int MinSquaresTab(int n){
	    vector<int> dp(n+1, INT_MAX);
	    dp[0] = 0;
	    
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j*j <= i; j++){
	            int temp = j*j;
	            if(i-temp >= 0)
	             dp[i] = min(dp[i], 1 + dp[i - temp]) ;
	        }
	    }
	    
	    return dp[n];
	}
	
	int MinSquares(int n)
	{   
	    vector<int> minWaysForN(n+1, -1);
	    return MinSquaresMem(n, minWaysForN);
	}
};