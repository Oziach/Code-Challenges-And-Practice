class Solution {
public:
    int divide(int dividend, int divisor) {

        bool negative = false;

        if(dividend < 0 && divisor < 0){negative = false;}
        else if(dividend < 0 || divisor < 0){negative = true;}


        long d = abs(dividend);
        long x = abs(divisor);

        long long quotient = 0;

        while(d >= x){
            int pow = 0;
            
            while(d >= (x << pow+1)){
                pow++;
            }

            d -= (x << pow);
            quotient += 1 << pow;
            cout << quotient << endl;

            if(quotient == (1 << 31)){ 
                if(negative){return INT_MIN;}
                return INT_MAX;
            }
        }

        return negative ? -quotient : quotient;
    }
};