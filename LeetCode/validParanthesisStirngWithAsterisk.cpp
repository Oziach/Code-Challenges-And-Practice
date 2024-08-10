class Solution {
public:
    bool checkValidString(string s) {
        int minCount = 0;
        int maxCount = 0;

        for(char ch : s){
            if(ch == '('){
                //add
                minCount += 1;
                maxCount += 1;
            }
            else if(ch == ')'){
                minCount--;
                maxCount--;
                if(minCount < 0 && maxCount < 0){return false;}
                minCount = max(0, minCount);
                maxCount = max(0,maxCount);
            }
            else{//if asterisk
                minCount = max(0, minCount-1);
                maxCount = maxCount + 1;
            }
        }
            
            if(minCount == 0){
                return true;
            }
            return false;
    }
};