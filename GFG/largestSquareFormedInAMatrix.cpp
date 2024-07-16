
class Solution {
  public:
    
    int MaxSquareMem(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp, int& maxi){
        
         if(i >= mat.size() || j >= mat[0].size()) { return 0; }
        
        if(dp[i][j] != -1){
           return dp[i][j];
        }
        
        int right = MaxSquareMem(mat, i, j+1, dp, maxi);
        int down = MaxSquareMem(mat, i+1, j, dp, maxi);
        int diag = MaxSquareMem(mat, i+1, j+1, dp, maxi);
        
        if(mat[i][j] == 1){
            dp[i][j] = min(right, min(down, diag)) + 1;
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
            
        }
        else{
            return 0;
        }
    }
  
    int MaxSquareTab(vector<vector<int>>& mat, int n, int m){
        vector<vector<int>> maxSquareFor(n+1, vector<int>(m+1, 0));
        int maxi = 0;
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){

                int right = maxSquareFor[i][j+1];
                int down = maxSquareFor[i+1][j];
                int diag = maxSquareFor[i+1][j+1];

                if(mat[i][j] == 1){
                    maxSquareFor[i][j] = min(right, min(down, diag)) + 1;
                    maxi = max(maxi, maxSquareFor[i][j]);
                }
                else{
                    maxSquareFor[i][j] = 0;
                }
                
            }
        }
        
        return maxi;
    }
    
    int MaxSquareSO(vector<vector<int>>& mat, int n, int m){
        
        vector<vector<int>> dp(2, vector<int>(m+1, 0));
        
        int maxi = 0;
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){

                int right = dp[0][j+1];
                int down = dp[1][j];
                int diag = dp[1][j+1];

                if(mat[i][j] == 1){
                    dp[0][j] = min(right, min(down, diag)) + 1;
                    maxi = max(maxi, dp[0][j]);
                }
                else{
                    dp[0][j] = 0;
                }
                
            }
            dp[1] = dp[0];
        }
        
        return maxi;
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int maxi = 0;
        return MaxSquareSO(mat,n, m);

    }
};