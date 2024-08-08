class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0;

        for(char ch = 'A'; ch <= 'Z'; ch++){

            int st = 0;
            int e = 0;
            int kDupe = k;

            while(e < s.length()){
                
                if(s[e] != ch){
                    kDupe--;
                }

                while(kDupe < 0){
                    if(s[st] != ch){
                        kDupe++;
                    }
                    st++;
                }

                longest = max(longest, e-st+1);
                
                e++;

            }

        }

        return longest;
    }
};