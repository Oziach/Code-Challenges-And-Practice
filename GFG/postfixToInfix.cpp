
class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;
        
        for(int i = 0; i < exp.length(); i++){
            
            char ch = exp[i];
            
            if(isalnum(ch)){
                string s;
                s += ch;
                st.push(s);
            }    
            else{
                string a = st.top(); 
                st.pop();
                
                string b = st.top();
                st.pop();
                
                st.push('(' + b + ch + a + ')');
            }
        }
        
        return st.top();
    }
};