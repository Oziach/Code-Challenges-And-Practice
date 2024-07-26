class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1){return strs[0];}
        
        int prefixLen = INT_MAX;

        for(int i = 1; i < strs.size(); i++){
            string& str1 = strs[i-1];
            string& str2 = strs[i];
            int minLen = min(str1.length(), str2.length());
            prefixLen = min(prefixLen, minLen);
            
            for(int j = 0; j < prefixLen; j++){
                if(str1[j] != str2[j]){
                    prefixLen = j;
                    break;
                }
            }
        }

        return strs[0].substr(0, prefixLen);
    }
};