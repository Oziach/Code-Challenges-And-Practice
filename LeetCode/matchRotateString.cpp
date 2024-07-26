class Solution {
public:
    bool rotateString(string s, string goal) {
       
        int len = s.length();

        for(int i = 0; i < len; i++){        

            if(s == goal){return true;}

            //rotate string
            char ch = s[len-1];
            for(int i = len-1; i > 0; i--){
                s[i] = s[i-1];
            }
            s[0] = ch;

        }

        return false;
    }
};