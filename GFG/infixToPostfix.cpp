class Solution {
  private:
    map<char, int> precs;
    
    bool IsOperator(char ch){
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
    }
    
  public:
    Solution(){
        precs['+'] = 1;
        precs['-'] = 1;
        precs['*'] = 2;
        precs['/'] = 2;
        precs['^'] = 3;
        precs['('] = -1;
    }

    

    string infixToPostfix(string s) {
        
        stack<char> st;
        string ans = "";
        
        for(int i = 0; i < s.length(); i++){
            
            char ch = s[i];
            
            //hnandle brackets
            if(ch == '('){st.push(ch); continue;}
            if(ch == ')'){
                
                while(st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
                continue;
            }
            
            
            if(IsOperator(ch)){
                
                if(!st.empty() && precs[ch] <= precs[st.top()]){
                     //empty the stack 
                    while(!st.empty() && st.top() != '('){
                        ans+=st.top();
                        st.pop();
                    }
                }
    
                st.push(ch);
              
            }
            else{ // ch is a letter
                ans += ch;
            }
        }    
        
        //empty stack one last time 
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
             
        return ans;
    }
};