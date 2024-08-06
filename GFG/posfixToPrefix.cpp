class Solution {
  public:
    string postToPre(string post_exp) {
        
        stack<string> st;
        
        for(int i = 0; i < post_exp.length(); i++){
            char ch = post_exp[i];
            string sCh = ""; sCh += ch;
            
            if(isalnum(ch)){
                st.push(sCh);
            }
            else{ //if ch is operator
                string a = st.top();
                st.pop();
                
                string b = st.top();
                st.pop();
                
                st.push(sCh + b + a);
            }
        }
        
        return st.top();
    }
};