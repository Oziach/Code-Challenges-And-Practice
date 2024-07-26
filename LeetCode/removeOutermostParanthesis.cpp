class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0; 
        string ans;

        for(char ch : s){

            if(ch == '('){
                if(count >= 1){ans += '(';}
                count++;
            }
            else{
                if(count > 1){ans += ')';}
                count--;
            }
        }

        return ans;
    }
};