class Solution {
  private:
  
    int GetXorFromOne(int n){
        int i = n % 4;
        if(i == 1){return 1;}
        if(i == 2){return n + 1;}
        if(i == 3){return 0;}
        if(i == 0){return n;}
    }
  
  public:
    int findXOR(int l, int r) {
        int a = l-1;
        int b = r;
        
        int xorA = GetXorFromOne(a);
        int xorB = GetXorFromOne(b);
        
        return xorA ^ xorB;
        
        
    }
};