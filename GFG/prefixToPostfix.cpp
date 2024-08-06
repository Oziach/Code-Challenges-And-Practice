class Solution {
  public:
    string preToPost(string pre_exp) {
        
        stack<string> st;
        
        for(int i = pre_exp.length() - 1; i >= 0; i--){
            char ch = pre_exp[i];
            string sCh = ""; sCh += ch;
            
            if(isalnum(ch)){ //if it is operand
                st.push(sCh);
            }
            else{ //if ch is operator
                string a = st.top();
                st.pop();
                
                string b = st.top();
                st.pop();
                
                st.push(a + b + sCh);
            }
        }
        
        return st.top();
    }
};