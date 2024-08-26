class Solution{
  private:
    int CutRod(int price[], int rodLength, int pieceLength, vector<vector<int>>& dp){
        
        if(pieceLength == 0){return 0;}
        
        if(dp[rodLength][pieceLength] != -1){return dp[rodLength][pieceLength];}
        
        int maxVal = 0;
        
        //pick this piece length
        if(pieceLength <= rodLength){
             maxVal += price[pieceLength-1] + CutRod(price, rodLength - pieceLength, pieceLength, dp);
        }
       

        //decrease piece length
        maxVal = max(maxVal, CutRod(price, rodLength, pieceLength-1, dp));
        
        
        return dp[rodLength][pieceLength] = maxVal;
        
    }
    
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return CutRod(price, n, n, dp);
    }
};