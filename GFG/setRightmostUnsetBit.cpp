class Solution {
  public:
    int setBit(int n) {
        int bitPos = 0;
        int nDupe = n;
        int mask = 1;
        
        while(nDupe & 1){
            nDupe = nDupe >> 1;
            mask = mask << 1;
            mask = mask | 1;
        }
        
        return n | mask;
    }
};