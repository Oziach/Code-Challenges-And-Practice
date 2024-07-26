class Solution {
public:

    int romanToInt(string s) {
        unordered_map<char, int> toInt;
        toInt['I'] = 1;
        toInt['V'] = 5;
        toInt['X'] = 10;
        toInt['L'] = 50;
        toInt['C'] = 100;
        toInt['D'] = 500;
        toInt['M'] = 1000;

        int ans = 0;
        int i = 0;
        while(i < s.length()){
            int ch = toInt[s[i]];
            int nextCh = i < s.length()-1 ? toInt[s[i+1]] : INT_MIN;

            if(ch >= nextCh){
                ans += ch;
                i++;
            }
            else{
                ans += nextCh - ch;
                i+=2;
            }
        }

        return ans;
    }
};