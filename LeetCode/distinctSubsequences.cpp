class Solution {
private:
    int NumDistinct(string& s, string& t, int i, int j, vector<vector<int>>& numDistinctFor){
        
        if(j >= t.length()){return 1;}
        if(i >= s.length()){return 0;}

        if(numDistinctFor[i][j] != -1){
            return numDistinctFor[i][j];
        }

        int total = 0;

        if(s[i] == t[j]){
            total += NumDistinct(s, t, i+1, j+1, numDistinctFor);    
        }

        total += NumDistinct(s, t, i+1, j, numDistinctFor);

        return numDistinctFor[i][j] = total;
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> numDistinctFor(n, vector<int>(m, -1));
        return NumDistinct(s, t, 0, 0, numDistinctFor);
    }
};