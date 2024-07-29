class Solution {
    void Gen(int& n, int open, string curr, vector<string>& ans){

        if(curr.length() == n*2){
            ans.push_back(curr);
            return;
        }
        
        int closed = curr.length() - open;

        //pick open
        if(open < n){
            Gen(n, open+1, curr + '(', ans);
        }

        //pick closed
        if(open && closed < open){
            Gen(n, open, curr + ')', ans);
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        Gen(n, 0, "", ans);
        return ans;
    }
};