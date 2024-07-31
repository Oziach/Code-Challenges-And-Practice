class Solution {
private:

    bool IsPalindrome(string& s, int startIndex, int endIndex){
        while(startIndex < endIndex){
            if(s[startIndex++] != s[endIndex--])
                return false;
        }
        return true;
    }

    void FillPalPartitions(string& s, int pI, int index, vector<string>& pals, vector<vector<string>>& ans){
        
        if(index >= s.length()){
            if(pI == index-1){
                ans.push_back(pals);
            }
            //else
            return;
        }

        //place partition if all before is palindrome
        if(IsPalindrome(s, pI+1, index)){
            pals.push_back(s.substr(pI+1, index - pI));
            FillPalPartitions(s, index, index+1, pals, ans);
            pals.pop_back();
        }

        //move to next index
        FillPalPartitions(s, pI, index+1, pals, ans);
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> pals;
        vector<vector<string>> ans;

        FillPalPartitions(s, -1, 0, pals, ans);
        return ans;
    }
};