class Solution {
  public:
    void bitManipulation(int num, int i) {
        cout << ((num >> (i-1)) & 1) << " "; //print ith bit from right
        
        int setNum = num | (1 << i-1);
        cout << setNum << " ";
        
        int clearNum = num & (~(1 << i-1));
        cout << clearNum;
    }
};