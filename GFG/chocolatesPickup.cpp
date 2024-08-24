class Solution {
  private:
    
    int GetChocolates(vector<vector<int>>& grid, int row, int col1, int col2, vector<vector<vector<int>>>& dp){
        
        //base conditions
        if(row >= grid.size()){return 0;} 
        
        if(col1 >= grid[0].size() || col1 < 0 || col2 >= grid[0].size() ||col2 < 0){return INT_MIN;}
        
        if(dp[row][col1][col2] != -1){return dp[row][col1][col2];}
        
        int chocsPicked = 0;
        
        //robo1
        int pickup1 = grid[row][col1];
        grid[row][col1] = 0;
        
        int pickup2 = 0;
        if(col1 != col2){
            //robo2
            pickup2 = grid[row][col2];
            grid[row][col2] = 0;
        }
     
  
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                chocsPicked = max(chocsPicked, GetChocolates(grid, row+1, col1 + i, col2 + j, dp));
            }
        }
        
        chocsPicked += pickup1 + pickup2;
        
        //place the chocolates back for another attempt
        grid[row][col1] = pickup1;
        if(col1 != col2){grid[row][col2] = pickup2;}
        
        return dp[row][col1][col2] = chocsPicked;
        
    }
    
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return GetChocolates(grid, 0, 0, m-1, dp);
    }
};