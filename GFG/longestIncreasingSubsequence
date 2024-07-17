class Solution
{
    public:
    
    int GetLongestSub(int n, int a[], int index, int prev){
        
         if(index >= n){ return 0; }
        
         int include = 0;
        //include
        if(prev == -1 || a[index] > a[prev]){
            include = 1 + GetLongestSub(n, a, index+1, index);
        }
        
        //exclude
        int exclude = GetLongestSub(n, a, index+1, prev);
        
        return(max(include,exclude));
    }
    
    int GetLongestMem(int& n, int a[], int index, int prev, vector<vector<int>>& dp){
        
        if(index >= n){ return 0; }
        
        if(dp[index][prev+1] != -1){
            return dp[index][prev+1];
        }    
        
         int include = 0;
        //include
        if(prev == -1 || a[index] > a[prev]){
            include = 1 + GetLongestMem(n, a, index+1, index, dp);
        }
        
        //exclude
        int exclude = GetLongestMem(n, a, index+1, prev, dp);
        
        return dp[index][prev+1] = max(include,exclude);
    }
    
    int GetLongestTab(int& n, int a[]){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int index = n-1; index >= 0; index--){
            for(int prev = index-1; prev >= -1; prev--){
                
                int include = 0;
                //include

                if(prev == -1 || a[index] > a[prev]){
                    include = 1 + dp[index+1][index+1];
                }
                
                //exclude
                int exclude = dp[index+1][prev+1];
                dp[index][prev+1] = max(include,exclude);
                
            }
        }
        
        return dp[0][0];
    }
    
        int GetLongestSO(int& n, int a[]){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        vector<int> current(n+1, 0);
        vector<int> previous(n+1, 0);
        
        for(int index = n-1; index >= 0; index--){
            for(int prev = index-1; prev >= -1; prev--){
                
                int include = 0;
                //include

                if(prev == -1 || a[index] > a[prev]){
                    include = 1 + previous[index+1];
                }
                
                //exclude
                int exclude = previous[prev+1];
                current[prev+1] = max(include,exclude);
                
            }
            previous = current;
        }
        
        return previous[0];
    }
    
    int UltraSolve(int n, int a[]){
        
    
        
        vector<int> v;
        
        for(int i = 0; i < n; i++){
            
            if(v.size() == 0 || a[i] > v.back()){
                v.push_back(a[i]);
            }
            else{
                int index = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
                v[index] = a[i];
            }
        }
        
        return v.size();
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        
        //vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return UltraSolve(n, a);
    }
};