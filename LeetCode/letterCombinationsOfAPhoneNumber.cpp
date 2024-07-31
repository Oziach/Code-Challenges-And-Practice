class Solution {
private:
    void FillLetterCombinations(string& digits,
     unordered_map<char,string>& lettersForDigit, string current, int index, vector<string>& ans){
        
        //base condn
        if(index >= digits.size()){ans.push_back(current); return;}

        int digit = digits[index];
        for(char letter : lettersForDigit[digit]){
            FillLetterCombinations(digits, lettersForDigit, current + letter, index+1, ans);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.size() == 0){return ans;}

        unordered_map<char, string> lettersForDigit;
        lettersForDigit['2'] = "abc"; 
        lettersForDigit['3'] = "def"; 
        lettersForDigit['4'] = "ghi"; 
        lettersForDigit['5'] = "jkl"; 
        lettersForDigit['6'] = "mno"; 
        lettersForDigit['7'] = "pqrs"; 
        lettersForDigit['8'] = "tuv"; 
        lettersForDigit['9'] = "wxyz"; 

        FillLetterCombinations(digits, lettersForDigit, "", 0, ans);
        return ans;
    }
};