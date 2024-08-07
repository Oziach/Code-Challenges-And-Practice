class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int removed = 0;

        for(int i = 0; i < num.length(); i++){
            
            while(!st.empty() && removed < k && st.top() > num[i]){
                st.pop();
                removed++;
            }

            st.push(num[i]);
        }

        while(!st.empty() && removed < k){
            st.pop();
            removed++;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        if(ans.length() == 0){return "0";}

        int afterLeadingZeros = ans.find_first_not_of('0');
        if(afterLeadingZeros == -1){return "0";}

        return ans.substr(afterLeadingZeros, ans.length());
    }
};