class Solution {
  public:
    void bitManipulation(int num, int i) {
        cout << ((num >> (i-1)) & 1) << " "; //print ith bit from right
        
        int setNum = num | (1 << i-1);
        cout << setNum << " ";
        
        int clearNum = INT_MAX << 1;
        for(int index = 0; index < i-1; index++){
                clearNum = clearNum << 1;
                clearNum = clearNum | 1;
        }
        clearNum = clearNum & num;
        
        cout << clearNum;
    }
};