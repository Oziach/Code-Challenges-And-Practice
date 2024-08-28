class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
    
                if(word1[i-1] == word2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(curr[j-1], prev[j]);
                }
            }
            prev = curr;
        }

        int longest = prev[m];
        return n + m - 2*longest;

    }
};