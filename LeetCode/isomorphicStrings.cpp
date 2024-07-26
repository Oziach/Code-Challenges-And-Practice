class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sV(256, -1);
        vector<int> tV(256, -1);

        for(int i = 0; i < s.size(); i++){
            if(sV[s[i]] != tV[t[i]])
                return false;
            
            sV[s[i]] = tV[t[i]] = i;
        }

        return true;
    }
};