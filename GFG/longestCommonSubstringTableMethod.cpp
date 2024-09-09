class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        
        vector<vector<int>> longestFor(n+1, vector<int>(m+1, 0));
        int maxi = 0;
        
        for(int row = 1; row <= n; row++){
            for(int col = 1; col <= m; col++){
                
                if(str1[row-1] == str2[col-1]){
                    longestFor[row][col] = 1 + longestFor[row-1][col-1];
                    maxi = max(maxi, longestFor[row][col]);
                }
                else{
                    longestFor[row][col] = 0;
                }
            }
        }
        
        return maxi;
    }
};
