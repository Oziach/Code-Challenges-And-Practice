class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> myBills;

        for(int i = 0; i < bills.size(); i++){
            int bill = bills[i];
            
            if(bill == 5){
                myBills[5]++;
            }
            else if(bill == 10){ //we need to return a 5$ bill
                
                if(!myBills[5]){return false;}

                myBills[10]++;
                myBills[5]--;
            }
            else if(bill == 20){
                if(myBills[10] && myBills[5]){
                    myBills[20]++; //not really useful tbh
                    myBills[10]--;
                    myBills[5]--;
                }
                else if(myBills[5] >= 3){
                    myBills[5] -= 3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};