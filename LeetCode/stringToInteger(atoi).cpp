class Solution {
public:
    int myAtoi(string s) {
        int startIndex = 0;
        long long num = 0;
        bool negative = false;

        //step 1
        for(startIndex; startIndex < s.size(); startIndex++){
            if(s[startIndex] != ' '){
                break;
            }
        }

        //step 2
        if(s[startIndex] == '+'){negative = false; startIndex++;}
        else if(s[startIndex] == '-'){negative = true; startIndex++;}

        //step 3
        int endIndex = startIndex;
        for(endIndex; endIndex < s.size(); endIndex++){
            if(s[endIndex] < '0' || s[endIndex] > '9'){break;}
        }
        endIndex--;
    
        //gen number
        int sign = negative ? -1 : 1;

        for(int i = startIndex; i <= endIndex; i++){
            
            int digit = sign * (s[i] - '0');
            num = (num * 10) + digit;
            
            if(num <= INT_MIN || num >= INT_MAX){break;}
        }
        
        if(num <= INT_MIN){return INT_MIN;}
        if(num >= INT_MAX){return INT_MAX;}
        return (int)num;
        
    }
};